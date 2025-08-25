/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 10:14:33 by akuchmam          #+#    #+#             */
/*   Updated: 2025-08-25 10:14:33 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	open_file(char *file_name)
{
	const int	fd = open(file_name, O_RDONLY);

	if (fd == -1)
		return (perror("Error\nFailed to open file"), 1);
	return (fd);
}

static int	get_line_length(int fd)
{
	char	input[1];
	int		read_status;
	int		length;

	length = 0;
	read_status = 1;
	while (read_status != 0)
	{
		read_status = read(fd, input, 1);
		if (read_status == -1)
			return (perror("Error\nFailed to read map file"), -1);
		if (read_status == 0 || input[0] == '\n')
			return (length);
		length++;
	}
	return (0);
}

static int	save_map(t_map *map, int fd)
{
	char	*line;
	int		read_status;
	int		i;

	map->data = malloc(map->rows * sizeof(char *));
	if (!map->data)
		return (perror("Error\nFailed to allocate memory for map data"), 1);
	line = ft_calloc(1, map->cols + 2);
	if (!line)
		return (perror("Error\nFailed to allocate memory for line"),
			free(map->data), 1);
	i = 0;
	read_status = 1;
	while (read_status != 0)
	{
		read_status = read(fd, line, map->cols + 1);
		if (read_status == -1)
			return (perror("Error\nFailed to read map file"), free(line), 1);
		if (read_status == 0)
			break ;
		map->data[i] = ft_strdup(line);
		map->data[i][map->cols] = 0;
		i++;
	}
	return (free(line), 0);
}

int	read_map(t_map *map, char *file_name)
{
	int	fd;
	int	cols;
	int	res;

	fd = open_file(file_name);
	if (fd == 1)
		return (1);
	*map = (t_map){0};
	cols = get_line_length(fd);
	while (cols > 0)
	{
		if (cols == -1)
			return (1);
		if (map->cols != 0 && map->cols != cols)
			return (ft_putstr_fd("Error\nWrong number of cols\n", 2), 1);
		map->cols = cols;
		map->rows += 1;
		cols = get_line_length(fd);
	}
	close(fd);
	fd = open_file(file_name);
	res = save_map(map, fd);
	close(fd);
	return (res);
}
