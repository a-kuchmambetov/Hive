#ifndef MAIN_H
#define MAIN_H

#include "config.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

enum e_TEX_ID
{
	TEX_EMPTY,
	TEX_WALL,
	TEX_COLLECTIBLE,
	TEX_EXIT,
    TEX_PLAYER_IDLE,
    TEX_PLAYER_WALK_LEFT,
    TEX_PLAYER_WALK_RIGHT,
    TEX_PLAYER_WALK_UP,
    TEX_PLAYER_WALK_DOWN,
    TEX_COUNT
};

typedef struct s_img
{
    void *img;
    char *a;
    int bpp;
    int ll;
    int endian;
    int w;
    int h;
} t_img;

typedef struct s_game
{
    void *mlx;
    void *win;
    t_img textures[TEX_COUNT];
    int p_pos_col;
    int p_pos_row;
    t_img frame;
} t_game;

typedef struct s_map
{
    char **data;
    int rows;
    int cols;
} t_map;

typedef struct s_level
{
    int num_of_collectibles;
    int collectible_count;
    int player_start[2];
    int exit[2];
} t_level;

// Function prototypes

unsigned int getp(t_img *im, int x, int y);
void blit_copy(t_img *dst, t_img *src, int dx, int dy);
void blit_colorkey(t_img *dst, t_img *src, int dx, int dy, unsigned int key);

// int parse_map(const char *filename, t_map *map);

#endif
