/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-27 10:45:43 by akuchmam          #+#    #+#             */
/*   Updated: 2025-04-27 10:45:43 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charcmp(const char s1, const char *set)
{
	while (*set)
		if (*set++ == s1)
			return (1);
	return (0);
}

static char	*trim(char *str, char const *set, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len && charcmp(str[index], set))
		index++;
	str = str + index;
	if (index >= len)
		return (str);
	index++;
	while (len - index > 0 && charcmp(str[len - index], set))
	{
		str[len - index] = '\0';
		index++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	if (!set)
		return (NULL);
	str = ft_strdup(s1);
	str = trim(str, set, ft_strlen(s1));
	return (str);
}