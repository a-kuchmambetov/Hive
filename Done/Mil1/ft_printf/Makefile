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

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

MAIN = curl -O https://raw.githubusercontent.com/a-kuchmambetov/Hive/master/ft_printf/test_ft_printf.c

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(LIBFTDIR) fclean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

getmain:
	@[ ! -f "test_ft_printf.c" ] && $(MAIN) || true
compile:
	$(CC) $(CFLAGS) -o tester test_ft_printf.c libftprintf.a && ./tester
test: getmain compile clean
	./tester > res.txt && cat res.txt && rm -f tester

printTester: clean
	git clone https://github.com/Tripouille/printfTester.git && cd printfTester && make m

.PHONY: all clean fclean re test getmain compile printTester
