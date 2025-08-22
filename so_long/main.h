#ifndef MAIN_H
#define MAIN_H

#include "config.h"
#include "libft/libft.h"
//Lib for graphics
#include "mlx/mlx.h"
//Lib for file reading
#include <fcntl.h>
// Lib for perror
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
	void	*img;
	char	*a;
	int		bpp;
	int		ll;
	int		endian;
	int		w;
	int		h;
} t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	textures[TEX_COUNT];
	int		p_pos_col;
	int		p_pos_row;
	t_img	frame;
} t_game;

typedef struct s_map
{
	char	**data;
	int		rows;
	int		cols;
} t_map;

typedef struct s_array3
{
	int		data[3];
} t_array3;

typedef struct s_level
{
	int		num_of_collectibles;
	int		collectible_count;
	int		player_start[2];
	int		exit[2];
} t_level;


// Function prototypes

int close_game(t_game *game);

int read_map(t_map *map, char *file_name);

int parse_map(t_map map);


//

unsigned int getp(t_img *im, int x, int y);
void blit_copy(t_img *dst, t_img *src, int dx, int dy);
void blit_colorkey(t_img *dst, t_img *src, int dx, int dy, unsigned int key);

void free_map_data(char **data, int rows, int cols);

#endif
