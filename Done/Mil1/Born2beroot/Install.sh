#! /bin/bash

# variables
PORT=4242
HOST_NAME=akuchmam42
HOSTS_FILE="/etc/hosts"
HOSTNAME_FILE="/etc/hostname"
# update package lists
apt-get update

# install packages, auto-yes to prompts
apt-get install -y \
    sudo \
    curl \
    ufw \
    apparmor \
    git \
    gcc \
    make \
    gawk \
    libpam-pwquality

sudo addgroup user42
sudo adduser "$USER" sudo
sudo adduser "$USER" user42
# This replaces your current shell (exec) with a new login shell under the "sudo" group (via sg), so you don't have to manually exit and re-enter.
exec sg sudo "$SHELL" -l 

sudo sed -i.bak -E \
  -e 's/^[#[:space:]]*Port .*/Port 4242/' \
  -e 's/^[#[:space:]]*PermitRootLogin .*/PermitRootLogin no/' \
  /etc/ssh/sshd_config
sudo systemctl restart sshd

sudo ufw --force enable
sudo ufw allow "${PORT}" 

sudo hostnamectl set-hostname $HOST_NAME
if grep -qE "^127\.0\.1\.1\s+" "$HOSTS_FILE"; then
  echo "Updating existing 127.0.1.1 entry"
  sudo sed -ri "s|^(127\.0\.1\.1\s+).*|\1$HOST_NAME|" "$HOSTS_FILE"
else
  echo "Adding new 127.0.1.1 entry"
  echo -e "127.0.1.1\t$HOST_NAME" | sudo tee -a "$HOSTS_FILE" >/dev/null
fi

echo "Done! Your hostname is now '$HOST_NAME'."
echo "Verify with: hostname"
echo "And check sudo no longer complains:"
echo "  sudo echo OK"

sudo systemctl enable --now apparmor

curl -sS https://starship.rs/install.sh | sh -s -- --yes
cat > ~/.bashrc << 'EOF'
# ~/.bashrc
# Only for interactive shells
[[ $- != *i* ]] && return

# 1. Load ble.sh
# (adjust the path if you installed it somewhere else)
source ~/.local/share/blesh/ble.sh

# --------------------------
# Environment settings
# --------------------------

# Use UTF-8 everywhere
export LANG=en_US.UTF-8
export LC_ALL=en_US.UTF-8

# Add user bin to PATH
export PATH="$HOME/bin:$HOME/.local/bin:$PATH"

# --------------------------
# Bash options
# --------------------------

# Append to history, don't overwrite it
shopt -s histappend

# Check window size after each command and update LINES and COLUMNS
shopt -s checkwinsize

# Enable programmable completion
if [ -f /etc/bash_completion ]; then
  . /etc/bash_completion
fi

# --------------------------
# History
# --------------------------

# Bigger history
export HISTSIZE=10000
export HISTFILESIZE=20000

# Don't record duplicates or commands starting with space
export HISTCONTROL=ignoreboth

# Timestamp each history entry
export HISTTIMEFORMAT="%F %T "

# --------------------------
# Prompt
# --------------------------

# Colors
GREEN="\[\e[32m\]"
BLUE="\[\e[34m\]"
YELLOW="\[\e[33m\]"
RESET="\[\e[0m\]"

# --------------------------
# Aliases
# --------------------------

# ls variants
alias ll='ls -lh --color=auto'
alias lla='ls -lah --color=auto'
alias la='ls -Ah --color=auto'
alias l.='ls -d .* --color=auto'

# safer remove / overwrite
alias rm='rm -i'
alias mv='mv -i'
alias cp='cp -i'

# Quick directory navigation
alias ..='cd ..'
alias ...='cd ../..'

# handy grep
alias grep='grep --color=auto'

# Update & upgrade
alias update='sudo apt-get update && sudo apt-get upgrade -y'

#My own
alias cl='clear'

# --------------------------
# Functions
# --------------------------

# mkcd: make directory and enter it
mkcd () {
  mkdir -p -- "$1" && cd -P -- "$1"
}

# extract: unpack various archive types
extract () {
  if [ -f "$1" ] ; then
    case "$1" in
      *.tar.bz2)   tar xjf "$1"    ;;
      *.tar.gz)    tar xzf "$1"    ;;
      *.bz2)       bunzip2 "$1"    ;;
      *.rar)       unrar x "$1"    ;;
      *.gz)        gunzip "$1"     ;;
      *.tar)       tar xf "$1"     ;;
      *.tbz2)      tar xjf "$1"    ;;
      *.tgz)       tar xzf "$1"    ;;
      *.zip)       unzip "$1"      ;;
      *.Z)         uncompress "$1" ;;
      *.7z)        7z x "$1"       ;;
      *)           echo "dont know how to extract '$1'" ;;
    esac
  else
    echo "'$1' is not a valid file"
  fi
}

# --------------------------
# Load local overrides
# --------------------------

# If you create ~/.bash_aliases or ~/.bash_functions, they get loaded here
if [ -f ~/.bash_aliases ]; then
  . ~/.bash_aliases
fi
if [ -f ~/.bash_functions ]; then
  . ~/.bash_functions
fi

# Add this line at the end of .bashrc:
[[ ! ${BLE_VERSION-} ]] || ble-attach

eval "$(starship init bash)"
# End of ~/.bashrc
EOF

mkdir ~/.config/

touch ~/.config/starship.toml

source ~/.bashrc

starship preset pure-preset -o ~/.config/starship.toml

cat >> ~/.config/starship.toml << 'EOF'

[username]
style_user = "#98c379"      # OneDark green
style_root = "#e06c75"      # OneDark red
format = '[$user]($style)'
disabled = false
show_always = true

[hostname]
ssh_only = false
style = "#61afef"           # OneDark blue
format = ':[$hostname]($style) '
disabled = false
EOF

git clone --recursive --depth 1 --shallow-submodules https://github.com/akinomyoga/ble.sh.git
make -C ble.sh install PREFIX=~/.local

cat > ~/.bash_profile << 'EOF'
# Source interactive config
if [[ $- == *i* ]] && [ -f "$HOME/.bashrc" ]; then
   source ~/.local/share/blesh/ble.sh
   eval "$(starship init bash)" 

   # Congih for ble.sh
   # Disable auto-complete based on the command history
   bleopt complete_auto_history=
   # Disable ambiguous completion
   bleopt complete_ambiguous=

   clear
fi
EOF
