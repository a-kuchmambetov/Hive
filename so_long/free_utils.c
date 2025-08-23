#include "main.h"

void free_map_data(char **data, int rows)
{
    int i;

    i = 0;
    while (i < rows)
    {
        free(data[i]);
        i++;
    }
    free(data);
}

int free_game(t_game *game)
{
    char **data;
    int i;

    if (!game)
        return (1);
    i = 0;
    while (i < TEX_COUNT)
    {
        if (game->textures[i].img)
            mlx_destroy_image(game->mlx, game->textures[i].img);
        i++;
    }
    if (game->frame.img)
        mlx_destroy_image(game->mlx, game->frame.img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    data = game->map.data;
    free_map_data(data, game->map.rows);
    return (0);
}

int close_game(t_game *game)
{
    if (free_game(game))
        ft_putstr_fd("Error: no game object to free\n", 2);
    exit(0);
    return (0);
}