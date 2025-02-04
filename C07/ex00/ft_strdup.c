/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 12:30:57 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-03 12:30:57 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index++);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		index;

	str = (char *) malloc(sizeof(char) * ft_strlen(src));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (src[index])
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
