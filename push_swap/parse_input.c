/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 14:35:05 by Artem             #+#    #+#             */
/*   Updated: 2025-08-05 14:35:05 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_in_int_range(char *str)
{
	long num;
	int sign;
	int i;

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

static int is_valid_number(char *str)
{
	int i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (is_in_int_range(str));
}

int *parse_input(int argc, char *argv[])
{
	int *numbers;
	int i;

	numbers = ft_calloc(sizeof(int), argc - 1);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < argc - 1 && is_valid_number(argv[i + 1]))
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (i < argc - 1)
	{
		free(numbers);
		return (NULL);
	}
	return (numbers);
}
