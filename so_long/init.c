#include "main.h"

static void init_map(t_game *game, char *file_name)
{
    if (read_map(&game->map, file_name))
        close_game(game);
    if (parse_map(game->map))
        close_game(game);
}

static int init_TEX(t_game *game)
{
    const char *TEX_filenames[TEX_COUNT] = {
        TEXTURE_EMPTY, TEXTURE_WALL, TEXTURE_COLLECTIBLE,
        TEXTURE_EXIT, TEXTURE_PLAYER_IDLE};
    int i;

    i = 0;
    while (i < TEX_COUNT)
    {
        game->textures[i].img = mlx_xpm_file_to_image(game->mlx, (char *)TEX_filenames[i], &game->textures[i].w, &game->textures[i].h);
        if (!game->textures[i].img)
            return 1;
        game->textures[i].a = mlx_get_data_addr(game->textures[i].img, &game->textures[i].bpp, &game->textures[i].ll, &game->textures[i].endian);
        if (!game->textures[i].a)
            return 1;
        i++;
    }
    return 0;
}

static void init_frame(t_game *game)
{
    const int W = game->map.cols * TILE_SIZE;
    const int H = game->map.rows * TILE_SIZE;

    game->frame = (t_img){0};
    game->frame = (t_img){mlx_new_image(game->mlx, W, H), 0, 0, 0, 0, W, H};
    if (!game->frame.img)
    {
        perror("Failed to create frame buffer");
        close_game(game);
    }
    game->frame.a = mlx_get_data_addr(game->frame.img, &game->frame.bpp, &game->frame.ll, &game->frame.endian);
    if (!game->frame.a)
    {
        perror("Failed to get frame buffer data address");
        close_game(game);
    }
}
void init_game(t_game *game, char *map_file_name)
{
    int w;
    int h;
    *game = (t_game){0};
    if (!(game->mlx = mlx_init()))
    {
        perror("Failed to initialize mlx");
        close_game(game);
    }
    init_map(game, map_file_name);
    w = game->map.cols * TILE_SIZE;
    h = game->map.rows * TILE_SIZE;
    game->win = mlx_new_window(game->mlx, w, h, "So Long");
    if (!game->win)
    {
        perror("Failed to create window");
        close_game(game);
    }
    if (init_TEX(game))
    {
        perror("Failed to initialize game textures");
        close_game(game);
    }
    init_frame(game);
    get_level_data(game->map, &game->level);
}
