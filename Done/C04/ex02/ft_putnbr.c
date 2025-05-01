/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 17:12:49 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-23 17:12:49 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(char number);
void	ft_putnbr(int nb);

void	ft_print_number(char number)
{
	write(1, &number, 1);
}

void	ft_putnbr(int nb)
{
	unsigned long int	size;
	unsigned int		number;

	if (nb < 0)
	{
		number = nb * -1;
		write(1, "-", 1);
	}
	else
		number = nb;
	size = 1;
	while (number > size * 10)
		size *= 10;
	while (size >= 1)
	{
		ft_print_number(number / size + '0');
		number %= size;
		size /= 10;
	}
}
