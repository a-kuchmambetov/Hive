#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$ROOT_DIR"

pass() { printf "✅ %s\n" "$1"; }
fail() { printf "❌ %s\n" "$1"; FAILED=1; }

FAILED=0

echo "=== So Long subject compliance quick-check ==="

# --- 0) Basic structure
[[ -e Makefile ]] && pass "Makefile present" || fail "Missing Makefile"
[[ -d maps ]]     && pass "maps/ folder present" || fail "Missing maps/ folder"
[[ -d textures ]] && pass "textures/ folder present" || fail "Missing textures/ folder"

# --- 1) Makefile sanity
if [[ -e Makefile ]]; then
  for t in "^all\\s*:" "^clean\\s*:" "^fclean\\s*:" "^re\\s*:"; do
    grep -qE "$t" Makefile && pass "Makefile target: ${t//\\s*/ }" || fail "Missing Makefile target: ${t//\\s*/ }"
  done
  grep -qE -- '-Wall(\s|$)'   Makefile && pass "Uses -Wall"   || fail "No -Wall"
  grep -qE -- '-Wextra(\s|$)' Makefile && pass "Uses -Wextra" || fail "No -Wextra"
  grep -qE -- '-Werror(\s|$)' Makefile && pass "Uses -Werror" || fail "No -Werror"

  # extract NAME (supports NAME = foo or NAME:=foo)
  NAME_VAR="$(awk -F '[:=]' '/^[[:space:]]*NAME[[:space:]]*[:=]/{gsub(/[ \t]/,"",$2); print $2; exit}' Makefile || true)"
  BIN="${NAME_VAR:-so_long}"

  echo "→ Building ($BIN)..."
  make -s fclean || true
  if make -s -j; then
    pass "Build succeeded"
  else
    fail "Build failed"
  fi

  # Detect unnecessary relink: second build should do nothing
  out1="$(make -s | wc -l | tr -d ' ')"
  out2="$(make -s | wc -l | tr -d ' ')"
  [[ "$out2" == "0" ]] && pass "No unnecessary relink" || fail "Rebuild happens on second make"

  [[ -f "$BIN" ]] && pass "Binary produced: $BIN" || fail "Binary $BIN not found"
else
  BIN="so_long"
fi

# --- 2) MiniLibX / ft_printf presence (static checks)
grep -R --include='*.c' -nE '#[[:space:]]*include[[:space:]]*[<"]mlx' . >/dev/null 2>&1 && pass "Includes MiniLibX headers" || fail "No mlx include found"
grep -R -nE 'mlx_(init|new_window|put_image_to_window|loop)' . >/dev/null 2>&1 && pass "Uses MiniLibX API" || fail "No MiniLibX API calls found"
grep -R --include='Makefile' -nE '(lmlx|mlx_Linux|mlx_Darwin)' . >/dev/null 2>&1 && pass "Makefile links MiniLibX" || fail "Makefile not linking MiniLibX"
grep -R -nE 'ft_printf' . >/dev/null 2>&1 && pass "Uses your ft_printf (or equivalent)" || echo "ℹ️ Could not confirm ft_printf usage (not mandatory if equivalent present)"

# --- 3) Generate parser test maps (all should fail gracefully with 'Error\\n...')
TMPMAPS="$(mktemp -d)"
cat > "$TMPMAPS/invalid_chars.ber" <<'EOF'
1111
1PZ1
1C01
1E11
1111
EOF

cat > "$TMPMAPS/not_rect.ber" <<'EOF'
11111
1P0C1
1E0111
11111
EOF

cat > "$TMPMAPS/open_walls.ber" <<'EOF'
11111
1P0C1
1E000
11111
EOF

cat > "$TMPMAPS/dup_exit.ber" <<'EOF'
11111
1P0C1
1EE01
11111
EOF

cat > "$TMPMAPS/no_collect.ber" <<'EOF'
11111
1P001
1E001
11111
EOF

cat > "$TMPMAPS/unreachable.ber" <<'EOF'
111111
1P0001
111101
1C0E11
111111
EOF

# A valid map (for info; we won't run it to avoid X requirement)
cat > "$TMPMAPS/valid_sample.ber" <<'EOF'
1111111
1P000C1
1001101
1C0E001
1111111
EOF

# --- 4) Run binary only on invalid maps (should print 'Error' and exit nonzero)
run_and_expect_error() {
  local f="$1"
  if [[ -x "$BIN" ]]; then
    set +e
    out="$("./$BIN" "$f" 2>&1 </dev/null | tr -d '\r')"
    code=$?
    set -e
    if [[ $code -ne 0 && "$out" == Error*$'\n'* || "$out" == Error ]]; then
      pass "Error-path OK for $(basename "$f")"
    else
      echo "---- output ----"
      printf "%s\n" "$out"
      echo "----------------"
      fail "Expected 'Error\\n...' and nonzero exit for $(basename "$f")"
    fi
  else
    echo "ℹ️ Skip runtime checks (binary not executable)"
  fi
}

for f in "$TMPMAPS"/*.ber; do
  case "$f" in
    *valid*) : ;; # skip
    *) run_and_expect_error "$f" ;;
  esac
done

# --- 5) Static hints for gameplay hooks (cannot simulate X input here)
grep -R -nE 'mlx_hook\\s*\\(.*17' . >/dev/null 2>&1 && pass "Handles DestroyNotify (window close)" || echo "ℹ️ No explicit DestroyNotify hook found (look for event 17)"
grep -R -nE 'mlx_key_(hook|down|up)|mlx_hook\\s*\\(.*Key' . >/dev/null 2>&1 && pass "Key handling present" || echo "ℹ️ Key handling not detected"
grep -R -nE '(K_ESC|65307|keycode.*ESC|ESC)' . >/dev/null 2>&1 && pass "ESC key referenced" || echo "ℹ️ ESC key not obvious in sources"
grep -R -nE 'printf|ft_printf.*move|movements' . >/dev/null 2>&1 && echo "ℹ️ Movement counter appears in code" || echo "ℹ️ Movement counter not obvious"

echo "==============================="
if [[ "${FAILED:-0}" == "1" ]]; then
  echo "RESULT: ❌ Some checks failed (see above)."
  exit 1
else
  echo "RESULT: ✅ Static/parse checks look good."
  exit 0
fi
