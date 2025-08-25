/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 10:08:29 by akuchmam          #+#    #+#             */
/*   Updated: 2025-08-25 10:08:29 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	init_map(t_game *game, char *file_name)
{
	if (read_map(&game->map, file_name))
		close_game(game);
	if (parse_map(game->map))
		close_game(game);
}

static int	init_tex(t_game *game)
{
	const char	*tex_filenames[TEX_COUNT] = {
		TEXTURE_EMPTY, TEXTURE_WALL, TEXTURE_COLLECTIBLE,
		TEXTURE_EXIT, TEXTURE_PLAYER_IDLE};
	int			i;

	i = 0;
	while (i < TEX_COUNT)
	{
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx,
				(char *)tex_filenames[i], &game->textures[i].w,
				&game->textures[i].h);
		if (!game->textures[i].img)
			return (1);
		game->textures[i].a = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bpp, &game->textures[i].ll,
				&game->textures[i].endian);
		if (!game->textures[i].a)
			return (1);
		i++;
	}
	return (0);
}

static void	init_frame(t_game *game)
{
	const int	w = game->map.cols * TILE_SIZE;
	const int	h = game->map.rows * TILE_SIZE;

	game->frame = (t_img){0};
	game->frame = (t_img){mlx_new_image(game->mlx, w, h), 0, 0, 0, 0, w, h};
	if (!game->frame.img)
	{
		perror("Error\nFailed to create frame buffer");
		close_game(game);
	}
	game->frame.a = mlx_get_data_addr(game->frame.img, &game->frame.bpp,
			&game->frame.ll, &game->frame.endian);
	if (!game->frame.a)
	{
		perror("Error\nFailed to get frame buffer data address");
		close_game(game);
	}
}

void	init_game(t_game *game, char *map_file_name)
{
	*game = (t_game){0};
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to initialize mlx");
		close_game(game);
	}
	init_map(game, map_file_name);
	game->win = mlx_new_window(game->mlx,
			game->map.cols * TILE_SIZE, game->map.rows * TILE_SIZE, "So Long");
	if (!game->win)
	{
		perror("Error\nFailed to create window");
		close_game(game);
	}
	if (init_tex(game))
	{
		perror("Error\nFailed to initialize game textures");
		close_game(game);
	}
	init_frame(game);
	get_level_data(game->map, &game->level);
}
