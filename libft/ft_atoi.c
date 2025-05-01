/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-18 10:01:27 by akuchmam          #+#    #+#             */
/*   Updated: 2025-04-18 10:01:27 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim_local(const char *nptr)
{
	int	index;

	index = 0;
	while (nptr[index] == ' ' || nptr[index] == '\f' || nptr[index] == '\n' || nptr[index] == '\r'
		|| nptr[index] == '\t' || nptr[index] == '\v' || nptr[index] == '+')
		index++;
	return ((char *) &nptr[index]);
}

int	ft_atoi(const char *nptr)
{
	long int	number;
	short int	sign;
	int index;

	sign = 1;
	if (nptr == NULL)
		return (0);
	nptr = ft_trim_local(nptr);
	index = 0;
	if (nptr[index] == '-')
	{
		sign = -1;
		index++;
	}
	number = 0;
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		number *= 10;
		number += nptr[index] - '0';
		if (number > INT_MAX && sign == 1) 
			return (INT_MAX);
		else if (number > (long)INT_MAX + 1 && sign == -1)
			return (INT_MIN);
		index++;
	}
	return (number * sign);
}
