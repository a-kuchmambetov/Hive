NAME    = so_long

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Imlx
LDFLAGS = -Lmlx -lmlx -lXext -lX11 -lm

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRC     = main.c free_utils.c init.c map_reader.c map_parser.c get_level_data.c render_utils.c render.c

OBJS     = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS) mlx/libmlx.a
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LIBFT) -o $(NAME)

mlx/libmlx.a:
	$(MAKE) -C mlx

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all
