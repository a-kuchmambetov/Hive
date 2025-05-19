/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 12:26:41 by akuchmam          #+#    #+#             */
/*   Updated: 2025-05-14 12:26:41 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *buffer)
{
	const size_t	buffer_size = BUFFER_SIZE;
	char	*res;
	int	index;

	index = -1;
	res = NULL;
	while (index == -1)
	{
		if (read(fd, buffer, buffer_size) < 0)
			return (NULL);
		index = ft_get_newline_i(buffer);
		res = ft_append_str(res, buffer);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	const size_t		buffer_size = BUFFER_SIZE;
	static char	*string;
	char *buffer;

	buffer = malloc(buffer_size);
	if (!buffer)
		return (NULL);
	buffer[buffer_size] = '\0';
	// Read untill the new line
	string = ft_read_line(fd, buffer);
	// Copy buffer to string with '\n' and rest
	// Output res until '\n'
	// Clear before '\n' to string
	// Clear buffer
	if (!string)
		return (NULL);
	free(buffer);
	return (string);
}

#include <fcntl.h>
#include "unistd.h"
#include "stdio.h"

int main ()
{
	const size_t	buffer_size = BUFFER_SIZE;
	char buffer[buffer_size];
	int length;

	int fd = open("test_file_1.txt", O_RDONLY);
	char *str = get_next_line(fd);
	close(fd);
}