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

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS = main.c parse_input.c parse_input_utils.c t_stack.c t_stack_val_index.c \
       pw_sa_sb_ss.c pw_pa_pb.c pw_ra_rb_rr.c pw_rra_rrb_rrr.c \
       tiny_sort.c big_sort.c big_sort_count_moves_utils.c big_sort_do_moves_utils.c

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

.PHONY: all clean fclean re debug
