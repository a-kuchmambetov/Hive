/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 10:49:52 by Akuchmam          #+#    #+#             */
/*   Updated: 2025-01-16 10:49:52 by Akuchmam         ###   ########fi        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_write(char input);

void	ft_write(char input)
{
	write(1, &input, sizeof(input));
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 < 100)
	{
		num2 = num1 + 1;
		while (num2 < 100)
		{
			ft_write(num1 / 10 + '0');
			ft_write(num1 % 10 + '0');
			write(1, " ", 1);
			ft_write(num2 / 10 + '0');
			ft_write(num2 % 10 + '0');
			if (!(num1 == 98 && num2 == 99))
				write(1, ", ", 2);
			num2++;
		}
		num1++;
	}
}
