/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 17:25:29 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-23 17:25:29 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int	index;
	int	negative_count;
	int	number;

	while (*str == ' ')
		str++;
	negative_count = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative_count++;
		str++;
	}
	number = 0;
	index = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number *= 10;
		number += str[index] - '0';
		index++;
	}
	if (negative_count % 2 == 1)
		number *= -1;
	return (number);
}
