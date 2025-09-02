/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 10:13:21 by akuchmam          #+#    #+#             */
/*   Updated: 2025-08-25 10:13:21 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_array3	get_count_items(t_map map, t_array3 count, int start_pos[2])
{
	int	rows;
	int	cols;

	rows = 0;
	while (rows < map.rows)
	{
		cols = 0;
		while (cols < map.cols)
		{
			if (map.data[rows][cols] == 'C')
				count.data[0]++;
			else if (map.data[rows][cols] == 'P')
			{
				count.data[1]++;
				start_pos[0] = rows;
				start_pos[1] = cols;
			}
			else if (map.data[rows][cols] == 'E')
				count.data[2]++;
			cols++;
		}
		rows++;
	}
	return (count);
}

static void	check_map_items(char **data, int coordsYX[2], t_array3 *count)
{
	if (data[coordsYX[0]][coordsYX[1]] == '1'
		|| data[coordsYX[0]][coordsYX[1]] == 'M')
		return ;
	if (data[coordsYX[0]][coordsYX[1]] == 'C')
		count->data[0]++;
	else if (data[coordsYX[0]][coordsYX[1]] == 'P')
		count->data[1]++;
	else if (data[coordsYX[0]][coordsYX[1]] == 'E')
		count->data[2]++;
	data[coordsYX[0]][coordsYX[1]] = 'M';
	check_map_items(data, (int []){coordsYX[0] - 1, coordsYX[1]}, count);
	check_map_items(data, (int []){coordsYX[0] + 1, coordsYX[1]}, count);
	check_map_items(data, (int []){coordsYX[0], coordsYX[1] - 1}, count);
	check_map_items(data, (int []){coordsYX[0], coordsYX[1] + 1}, count);
}

static char	**duplicate_map_data(t_map map)
{
	int		i;
	char	**new_map;

	new_map = malloc(map.rows * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < map.rows)
	{
		new_map[i] = ft_strdup(map.data[i]);
		if (!new_map[i])
		{
			free_map_data(new_map, i);
			return (NULL);
		}
		i++;
	}
	return (new_map);
}

int	parse_map(t_map map)
{
	int				start_pos[2];
	const t_array3	exist_elem = get_count_items(map, (t_array3){0}, start_pos);
	t_array3		res;
	char			**data;

	data = duplicate_map_data(map);
	if (check_valid_map(map, exist_elem, data))
	{
		free_map_data(data, map.rows);
		return (1);
	}
	res = (t_array3){0};
	check_map_items(data, start_pos, &res);
	free_map_data(data, map.rows);
	if (res.data[0] != exist_elem.data[0] || res.data[1] != exist_elem.data[1]
		|| res.data[2] != exist_elem.data[2])
		return (ft_putstr_fd("Error\nImpossible to finish map.\n", 2), 1);
	return (0);
}
