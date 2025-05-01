/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 14:03:46 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-04 14:03:46 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	length;

	length = ft_strlen(dest);
	index = 0;
	while (src[index])
	{
		dest[length + index] = src[index];
		index++;
	}
	dest[length + index] = '\0';
	return (dest);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	index;
	int	iterator;
	int	length;
	int	sep_length;

	sep_length = ft_strlen(sep);
	length = 0;
	index = 0;
	while (index < size && strs[index] != 0)
	{
		iterator = 0;
		while (strs[index][iterator])
		{
			length++;
			iterator++;
		}
		if (index < size - 1)
			length += sep_length;
		index++;
	}
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index;
	int		length;
	char	*result;

	if (size == 0)
	{
		result = (char *) malloc(1);
		return (result);
	}
	length = ft_total_length(size, strs, sep);
	result = (char *) malloc(length + 1);
	if (result == NULL)
		return (result);
	index = 0;
	while (index < size && strs[index] != 0)
	{
		ft_strcat(result, strs[index]);
		if (index < size - 1)
			ft_strcat(result, sep);
		index++;
	}
	result[length] = '\0';
	return (result);
}
