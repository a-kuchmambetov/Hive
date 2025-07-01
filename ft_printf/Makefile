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

SRCS = ft_printf.c

LIBFT_SRCS = $(LIBFTDIR)/ft_strlen.c \
			$(LIBFTDIR)/ft_putchar_fd.c \
			$(LIBFTDIR)/ft_putstr_fd.c \
			$(LIBFTDIR)/ft_putnbr_fd.c \
			$(LIBFTDIR)/ft_putendl_fd.c \
			$(LIBFTDIR)/ft_itoa.c \
			$(LIBFTDIR)/ft_strchr.c \
			$(LIBFTDIR)/ft_strdup.c \
			$(LIBFTDIR)/ft_substr.c \
			$(LIBFTDIR)/ft_strjoin.c \
			$(LIBFTDIR)/ft_strtrim.c \
			$(LIBFTDIR)/ft_split.c \
			$(LIBFTDIR)/ft_strmapi.c \
			$(LIBFTDIR)/ft_striteri.c \
			$(LIBFTDIR)/ft_isalpha.c \
			$(LIBFTDIR)/ft_isdigit.c \
			$(LIBFTDIR)/ft_isalnum.c \
			$(LIBFTDIR)/ft_isascii.c \
			$(LIBFTDIR)/ft_isprint.c \
			$(LIBFTDIR)/ft_toupper.c \
			$(LIBFTDIR)/ft_tolower.c \
			$(LIBFTDIR)/ft_strlcpy.c \
			$(LIBFTDIR)/ft_strlcat.c \
			$(LIBFTDIR)/ft_strrchr.c \
			$(LIBFTDIR)/ft_strncmp.c \
			$(LIBFTDIR)/ft_strnstr.c \
			$(LIBFTDIR)/ft_memset.c \
			$(LIBFTDIR)/ft_memcpy.c \
			$(LIBFTDIR)/ft_memmove.c \
			$(LIBFTDIR)/ft_memchr.c \
			$(LIBFTDIR)/ft_memcmp.c \
			$(LIBFTDIR)/ft_bzero.c \
			$(LIBFTDIR)/ft_calloc.c \
			$(LIBFTDIR)/ft_atoi.c

OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) -o test_ft_printf test_ft_printf.c ft_printf_utils.c -L. -lftprintf
	./test_ft_printf

.PHONY: all clean fclean re test
