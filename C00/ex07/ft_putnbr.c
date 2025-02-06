/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 12:09:05 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-19 12:09:05 by akuchmam         ###   ########.fr       */
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
	int	size;

	size = 10;
	while (nb > size)
		size *= 10;
	size /= 10;
	while (size >= 1)
	{
		ft_print_number(nb / size + '0');
		nb %= size;
		size /= 10;
	}
}
