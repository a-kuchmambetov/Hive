/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 10:53:51 by akuchmam          #+#    #+#             */
/*   Updated: 2025-05-05 10:53:51 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	const int		str_len = ft_strlen(s);
	char			*str;
	unsigned int	index;

	str = ft_calloc(1, str_len + 1);
	if (!str)
		return ;
	index = 0;
	while (s[index])
	{
		f(index, s);
		index++;
	}
}
