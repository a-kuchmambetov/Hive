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
		return (perror("Error\nFailed to open file\n"), 1);
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
			return (perror("Error\nFailed to read map file\n"), -1);
		if (read_status == 0 || input[0] == '\n')
			return (length);
		length++;
	}
	return (0);
}

static void	*safe_alloc(char *err_msg, size_t nmemb, size_t size)
{
	void	*dst;

	dst = ft_calloc(nmemb, size);
	if (!dst)
	{
		perror(err_msg);
		return (NULL);
	}
	return (dst);
}

static int	save_map(t_map *map, int fd)
{
	char	*ln;
	int		read_status;
	int		i;

	map->data = safe_alloc("Error\nFailed to allocate for map\n", 8, map->rows);
	ln = safe_alloc("Error\nFailed to allocate for line\n", 1, map->cols + 2);
	if (!map->data || !ln)
		return (1);
	i = 0;
	read_status = 1;
	while (read_status != 0)
	{
		read_status = read(fd, ln, map->cols + 1);
		if (read_status == -1)
			return (perror("Error\nFailed to read map file\n"), free(ln), 1);
		if (read_status == 0)
			break ;
		if (ln[0] == '\n')
			return (ft_putstr_fd("Error\nEmpty line in map\n", 2), free(ln), 1);
		map->data[i] = ft_strdup(ln);
		if (!map->data[i])
			return (perror("Error\nFailed to duplicate line\n"), free(ln), 1);
		i++;
	}
	return (free(ln), 0);
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
