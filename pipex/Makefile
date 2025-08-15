# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuchmam <akuchmam@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025-07-01 00:00:00 by akuchmam          #+#    #+#              #
#    Updated: 2025-07-01 00:00:00 by akuchmam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

debug: CFLAGS += -g
debug: all clean

gitTester:
	@[ ! -d "42_pipex_tester" ] && git clone https://github.com/michmos/42_pipex_tester.git; \
	cd 42_pipex_tester && bash run.sh && cd ..;

gitTesterClean: fclean
	@[ -d "42_pipex_tester" ] && rm -rf 42_pipex_tester;

.PHONY: all clean fclean re debug gitTester gitTesterClean