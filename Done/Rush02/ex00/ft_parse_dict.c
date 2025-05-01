/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwong <cwong@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:11:05 by cwong             #+#    #+#             */
/*   Updated: 2025/02/02 18:11:07 by cwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	handle_newline(char **ptr, char *newline)
{
	if (newline)
		*newline = '\0';
	if (**ptr == '\0')
	{
		if (newline)
			*ptr = newline + 1;
	}
}

int	process_buffer(char *buffer, int *size, t_dict_entry **entries_ptr)
{
	char	*ptr;
	char	*newline;
	int		result;

	ptr = buffer;
	while (*ptr)
	{
		newline = ft_strchr(ptr, '\n');
		handle_newline(&ptr, newline);
		if (*ptr)
			result = ft_process_entry(ptr, size, entries_ptr);
		if (result < 0)
			return (result);
		if (newline)
			ptr = newline + 1;
		else
			ptr = ptr + ft_strlen(ptr);
	}
	return (0);
}

t_dict_entry	*ft_parse_dict(char *dictionary, int *size)
{
	int				fd;
	t_dict_entry	*entries;
	ssize_t			bytes_read;
	char			buffer[4096];

	fd = open(dictionary, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		*size = -1;
		return (NULL);
	}
	entries = NULL;
	*size = 0;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (process_buffer(buffer, size, &entries) < 0)
			break ;
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
	return (entries);
}
