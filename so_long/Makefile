NAME    = so_long

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Imlx
LDFLAGS = -Lmlx -lmlx -lXext -lX11 -lm

SRC     = main.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) mlx/libmlx.a
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

mlx/libmlx.a:
	$(MAKE) -C mlx

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
