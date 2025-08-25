/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 10:13:09 by akuchmam          #+#    #+#             */
/*   Updated: 2025-08-25 10:13:09 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_outer_walls(t_map map)
{
	int	cols;
	int	rows;

	cols = 0;
	while (cols < map.cols)
	{
		if (map.data[0][cols] != '1' || map.data[map.rows - 1][cols] != '1')
			return (1);
		cols++;
	}
	rows = 0;
	while (rows < map.rows)
	{
		if (map.data[rows][0] != '1' || map.data[rows][map.cols - 1] != '1')
			return (1);
		rows++;
	}
	return (0);
}

static int	invalid_char(char c)
{
	return (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P');
}

static int	check_map_chars(t_map map)
{
	int	rows;
	int	cols;

	rows = 0;
	while (rows < map.rows)
	{
		cols = 0;
		while (cols < map.cols)
		{
			if (invalid_char(map.data[rows][cols]))
				return (1);
			cols++;
		}
		rows++;
	}
	return (0);
}

int	check_valid_map(t_map map, t_array3 existing_elem, char **data)
{
	if (!data)
		return (ft_putstr_fd("Error\nMap duplicate allocation failed\n", 2), 1);
	if (check_map_chars(map))
		return (ft_putstr_fd("Error\nMap contains invalid characters\n", 2), 1);
	if (check_outer_walls(map))
		return (ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2), 1);
	if (existing_elem.data[0] == 0)
		return (ft_putstr_fd("Error\nNo collectibles found\n", 2), 1);
	if (existing_elem.data[1] != 1 || existing_elem.data[2] != 1)
		return (ft_putstr_fd("Error\nInvalid number of player/exit\n", 2), 1);
	return (0);
}
