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
	size_t count;

	if (str == NULL)
		return (0);
	count = 0;
	while ((str[count] != '\0' || str[count] != '\n'))
		count++;
	return (count++);
}

void	ft_strcpy_noendl(char **dest,const char *src, size_t len)
{
	size_t index;

	index = 0;
	while (index < len)
		*dest[index] = src[index++];
}

// Wrong implementation fix it !!!
char	*ft_append_str(const char *src, const char *buffer)
{
	const size_t	src_len = ft_strlen(src);
	const size_t	buf_len = ft_strlen(buffer);
	const size_t	size = src_len + buf_len + 1;
	char	*temp;
	size_t	index;

	if (buf_len <= 0)
		return ((char *)src);
	temp = malloc(size);
	if (!temp)
		return (NULL);
	temp [size] = '\0';
	if (src_len > 0)
		ft_strcpy_noendl(&temp, src, src_len);
	index = 0;
	while (index < buf_len)
		temp[src_len + index] = buffer[index++];
	return (temp);
}
