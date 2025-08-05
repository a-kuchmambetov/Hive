/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 16:12:33 by Artem             #+#    #+#             */
/*   Updated: 2025-08-05 16:12:33 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_int_range(char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-num < INT_MIN)))
			return (0);
		i++;
	}
	return (1);
}
