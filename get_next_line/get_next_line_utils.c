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

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

size_t	ft_get_newline_index(char *str)
{
	const size_t	buffer_size = BUFFER_SIZE;
	size_t			count;

	count = 0;
	while (str[count] != '\0' && count < buffer_size)
	{
		if (str[count] == '\n')
				return (count);
		count++;
	}
	return (0);
}

char	*ft_append_str(char *original, const char *addition)
{
	const size_t org_len = ft_strlen(original);
	const size_t add_len = ft_strlen(addition);
	char *temp;
	size_t index;

	if (!addition)
		return (NULL);
	temp = malloc(org_len + add_len + 1);
	if (!temp)
		return (NULL);
	while (addition[index] != '\n' )
	{
		/* code */
	}
	if (original)
		free(original);
	return (temp);
}
