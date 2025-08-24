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
	int		total_collectibles;
	int		collected_count;
	int		p_pos[2];
	int		e_pos[2];
} t_level;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	textures[TEX_COUNT];
	t_img	frame;
	t_map	map;
	t_level	level;
	int		move_count;
} t_game;

// Function prototypes
// Initialization functions
void init_game(t_game *game, char *map_file_name);

// Map functions  
int read_map(t_map *map, char *file_name);
int parse_map(t_map map);

// Level data functions
void get_level_data(t_map map, t_level *level);

// Rendering utilities
unsigned int getp(t_img *im, int x, int y);
void blit_copy(t_img *dst, t_img *src, int dx, int dy);
void blit_colorkey(t_img *dst, t_img *src, int dx, int dy, unsigned int key);

// Rendering functions
void render_map(t_game *game);
void render_player(t_game *game, int py, int px);

// Memory management functions
void free_map_data(char **data, int rows);
int free_game(t_game *game);
int close_game(t_game *game);

#endif
