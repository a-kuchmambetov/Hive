/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 10:07:07 by akuchmam          #+#    #+#             */
/*   Updated: 2025-08-25 10:07:07 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_map_data(char **data, int rows)
{
	int	i;

	i = 0;
	if (data)
	{
		while (i < rows)
		{
			if (data[i])
				free(data[i]);
			i++;
		}
		free(data);
	}
}

int	free_game(t_game *game)
{
	char	**data;
	int		i;

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

int	close_game(t_game *game)
{
	if (free_game(game))
		ft_putstr_fd("Error\nNo game object to free\n", 2);
	if (game->level.collected_count == game->level.total_collectibles
		&& game->level.total_collectibles > 0)
	{
		ft_putstr_fd("Total Moves: ", 1);
		ft_putnbr_fd(game->move_count, 1);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("Congratulations! You've completed the level!\n", 1);
		exit(0);
	}
	else
		ft_putstr_fd("Game Over! You exited before collecting all items.\n", 1);
	exit(1);
	return (0);
}
