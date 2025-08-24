#include "main.h"

static void move_player(t_game *game, int dy, int dx)
{
    int new_y = game->level.p_pos[0] + dy;
    int new_x = game->level.p_pos[1] + dx;

    if (game->map.data[new_y][new_x] == '1')
        return; // Out of bounds
    if (game->map.data[new_y][new_x] == 'C')
    {
        game->level.collected_count++;
        game->map.data[new_y][new_x] = '0';
    }
    if (game->map.data[new_y][new_x] == 'E' && game->level.collected_count == game->level.total_collectibles)
        close_game(game);
    // else if (game->map.data[new_y][new_x] == 'E' && game->level.collected_count < game->level.total_collectibles)
    //     return ;
    render_player(game, new_y, new_x);
    game->level.p_pos[0] = new_y;
    game->level.p_pos[1] = new_x;
    game->move_count++;
    ft_putstr_fd("Move Count: ", 1);
    ft_putnbr_fd(game->move_count, 1);
    ft_putstr_fd("\n", 1);
}

static int on_key_press(int keycode, t_game *game)
{
    if (keycode == K_ESC)
        close_game(game);
    if (keycode == K_W || keycode == K_UP)
        move_player(game, -1, 0);
    if (keycode == K_S || keycode == K_DOWN)
        move_player(game, 1, 0);
    if (keycode == K_A || keycode == K_LEFT)
        move_player(game, 0, -1);
    if (keycode == K_D || keycode == K_RIGHT)
        move_player(game, 0, 1);
    return (0);
}

static int check_file_type(char *filename)
{
    char *ext = ft_strrchr(filename, '.');
    
    if (!ext || ft_strncmp(ext, ".ber", 4) != 0)
    {
        ft_putstr_fd("Error\nInvalid file type. Please use a .ber file.\n", 2);
        return (0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_game game;
    int w, h;

    if (argc != 2)
        return (ft_putstr_fd("Error\nWrong amount of arguments.\n", 2), 1);
    if (!check_file_type(argv[1]))
        return (1);
    init_game(&game, argv[1]);
    mlx_get_screen_size(game.mlx, &w, &h);
    if (game.map.cols * TILE_SIZE > w || game.map.rows * TILE_SIZE > h)
    {
        ft_putstr_fd("Error\nMap is too large for the screen.\n", 2);
        close_game(&game);
    }
    render_map(&game);
    mlx_key_hook(game.win, on_key_press, &game);
    mlx_hook(game.win, 17, 0, close_game, &game);
    mlx_loop(game.mlx);
}
