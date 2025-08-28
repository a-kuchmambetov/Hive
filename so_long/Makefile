# Makefile
NAME    = so_long

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Imlx
LIBFLAGS = -Lmlx -lmlx -lXext -lX11 -lm

LIBFTDIR = libft
LIBFT    = $(LIBFTDIR)/libft.a
MLXDIR   = mlx
MLX      = $(MLXDIR)/libmlx.a

SRC      = main.c free_utils.c init.c map_reader.c map_parser_utils.c map_parser.c get_level_data.c render_utils.c render.c

OBJS     = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@{ \
		if [ ! -f "$(MLX)" ]; then echo "libmlx.a missing → recloning"; \
			rm -rf "$(MLXDIR)"; \
			git clone https://github.com/42paris/minilibx-linux.git "$(MLXDIR)"; \
		fi; \
		$(MAKE) -C "$(MLXDIR)"; \
	}

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFLAGS) $(MLX) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

mlxDel:
	rm -rf mlx

allClean: fclean mlxDel

re: fclean all
