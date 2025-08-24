#include "main.h"

static void draw_tiles(t_game *game, t_map *map)
{
    int rows;
    int cols;

    rows = 0;
    while (rows < map->rows)
    {
        cols = 0;
        while (cols < map->cols)
        {
            char cur_char = map->data[rows][cols];
            if (cur_char == '1')
            {
                blit_copy(&game->frame, &game->textures[TEX_WALL], cols * TILE_SIZE, rows * TILE_SIZE);
            }
            else if (cur_char == '0' || cur_char == 'P' || cur_char == 'C' || cur_char == 'E')
            {
                blit_copy(&game->frame, &game->textures[TEX_EMPTY], cols * TILE_SIZE, rows * TILE_SIZE);
            }
            cols++;
        }
        rows++;
    }
}

static void draw_items(t_game *game, t_map *map)
{
    int rows;
    int cols;
    unsigned int key;
    
    rows = 0;
    while (rows < map->rows)
    {
        cols = 0;
        while (cols < map->cols)
        {
            if (map->data[rows][cols] == 'C')
            {
                key = getp(&game->textures[TEX_COLLECTIBLE], 0, 0);
                blit_colorkey(&game->frame, &game->textures[TEX_COLLECTIBLE], cols * TILE_SIZE, rows * TILE_SIZE, key);
            }
            else if (map->data[rows][cols] == 'E')
            {
                key = getp(&game->textures[TEX_EXIT], 0, 0);
                blit_colorkey(&game->frame, &game->textures[TEX_EXIT], cols * TILE_SIZE, rows * TILE_SIZE, key);
            }
            cols++;
        }
        rows++;
    }
}

void render_map(t_game *game)
{
    const int p_pos[2] = {game->level.p_pos[0], game->level.p_pos[1]};
    unsigned int key = getp(&game->textures[TEX_PLAYER_IDLE], 0, 0);

    draw_tiles(game, &game->map);
    draw_items(game, &game->map);
    blit_colorkey(&game->frame, &game->textures[TEX_PLAYER_IDLE], p_pos[1] * TILE_SIZE, p_pos[0] * TILE_SIZE, key);
    mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}

void render_player(t_game *game, int py, int px)
{
    const int old_pos[2] = {game->level.p_pos[0], game->level.p_pos[1]};
    const int new_pos[2] = {py, px};
    unsigned int key = getp(&game->textures[TEX_PLAYER_IDLE], 0, 0);

    blit_copy(&game->frame, &game->textures[TEX_EMPTY], old_pos[1] * TILE_SIZE, old_pos[0] * TILE_SIZE);
    if (game->map.data[new_pos[0]][new_pos[1]] != 'E')
    blit_copy(&game->frame, &game->textures[TEX_EMPTY], new_pos[1] * TILE_SIZE, new_pos[0] * TILE_SIZE);
    if (game->map.data[old_pos[0]][old_pos[1]] == 'E')
        blit_colorkey(&game->frame, &game->textures[TEX_EXIT], old_pos[1] * TILE_SIZE, old_pos[0] * TILE_SIZE, key);
    blit_colorkey(&game->frame, &game->textures[TEX_PLAYER_IDLE], new_pos[1] * TILE_SIZE, new_pos[0] * TILE_SIZE, key);
    mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}