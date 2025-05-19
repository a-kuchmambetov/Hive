/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-16 08:57:55 by akuchmam          #+#    #+#             */
/*   Updated: 2025-05-16 08:57:55 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const size_t	buffer_size = BUFFER_SIZE;
	size_t count;

	if (str == NULL)
		return (0);
	count = 0;
	while ((str[count] != '\0' || str[count] != '\n') && count < buffer_size)
		count++;
	return (count);
}

int	ft_get_newline_i(char *src)
{
	const size_t	buffer_size = BUFFER_SIZE;
	int	count;

	count = 0;
	while (count < buffer_size)
	{
		if (src[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}

// Wrong implementation fix it !!!
char	*ft_append_str(const char *original, const char *addition)
{
	const size_t	buffer_size = BUFFER_SIZE;
	const size_t	org_len = ft_strlen(original);
	const size_t	add_len = ft_strlen(addition);
	char	*temp;
	size_t	index;

	if (!addition)
		return (NULL);
	temp = malloc(org_len + add_len + 1);
	if (!temp)
		return (NULL);
	index = 0;
	while (original[index] != '\0' && index < buffer_size)
		temp[index] = original[index++];
	while (addition[index] != '\n' && index < buffer_size)
	{
		temp[index] = addition[index];
		index++;
	}
	if (addition[index] == '\n')
		temp[index] = '\n';
	if (original)
		free(original);
	return (temp);
}
