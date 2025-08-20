#ifndef MAIN_H
#define MAIN_H

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
    int bpp,
        ll,
        endian,
        w,
        h;
} t_img;

typedef struct s_game
{
    void *mlx;
    void *win;
    t_img textures[TEX_COUNT];
    int player_x;
    int player_y;
} t_game;

#endif
