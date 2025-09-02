/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 10:36:04 by akuchmam          #+#    #+#             */
/*   Updated: 2025-08-25 10:36:04 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	draw_tiles(t_game *game, t_map *map)
{
	int		rows;
	int		cols;
	char	cmap;

	rows = 0;
	while (rows < map->rows)
	{
		cols = 0;
		while (cols < map->cols)
		{
			cmap = map->data[rows][cols];
			if (cmap == '1')
			{
				blit_copy(&game->frame, &game->textures[TEX_WALL],
					cols * TILE_SIZE, rows * TILE_SIZE);
			}
			else if (cmap == '0' || cmap == 'P' || cmap == 'C' || cmap == 'E')
			{
				blit_copy(&game->frame, &game->textures[TEX_EMPTY],
					cols * TILE_SIZE, rows * TILE_SIZE);
			}
			cols++;
		}
		rows++;
	}
}

static void	draw_items(t_game *game, t_map *map)
{
	int	rows;
	int	cols;

	rows = 0;
	while (rows < map->rows)
	{
		cols = 0;
		while (cols < map->cols)
		{
			if (map->data[rows][cols] == 'C')
				blit_colorkey(&game->frame, &game->textures[TEX_COLLECTIBLE],
					cols * TILE_SIZE, rows * TILE_SIZE);
			else if (map->data[rows][cols] == 'E')
				blit_colorkey(&game->frame, &game->textures[TEX_EXIT],
					cols * TILE_SIZE, rows * TILE_SIZE);
			cols++;
		}
		rows++;
	}
}

void	render_map(t_game *game)
{
	const int	p_pos[2] = {game->level.p_pos[0], game->level.p_pos[1]};

	draw_tiles(game, &game->map);
	draw_items(game, &game->map);
	blit_colorkey(&game->frame, &game->textures[TEX_PLAYER_IDLE],
		p_pos[1] * TILE_SIZE, p_pos[0] * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}

void	render_player(t_game *game, int py, int px)
{
	const int	old_pos[2] = {game->level.p_pos[0], game->level.p_pos[1]};
	const int	new_pos[2] = {py, px};

	blit_copy(&game->frame, &game->textures[TEX_EMPTY],
		old_pos[1] * TILE_SIZE, old_pos[0] * TILE_SIZE);
	if (game->map.data[new_pos[0]][new_pos[1]] != 'E')
		blit_copy(&game->frame, &game->textures[TEX_EMPTY],
			new_pos[1] * TILE_SIZE, new_pos[0] * TILE_SIZE);
	if (game->map.data[old_pos[0]][old_pos[1]] == 'E')
		blit_colorkey(&game->frame, &game->textures[TEX_EXIT],
			old_pos[1] * TILE_SIZE, old_pos[0] * TILE_SIZE);
	blit_colorkey(&game->frame, &game->textures[TEX_PLAYER_IDLE],
		new_pos[1] * TILE_SIZE, new_pos[0] * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}
