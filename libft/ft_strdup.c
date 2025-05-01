/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-23 09:54:19 by akuchmam          #+#    #+#             */
/*   Updated: 2025-04-23 09:54:19 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	const int	size = ft_strlen(s) + 1;

	str = malloc(size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, size);
	return (str);
}
