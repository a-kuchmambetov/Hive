/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshoweky <wshoweky@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:08:36 by wshoweky          #+#    #+#             */
/*   Updated: 2025/01/19 20:17:40 by wshoweky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char value, int size);

void	print_hor_line(int x)
{
	int	iterator;

	iterator = 0;
	while (iterator < x)
	{
		if (iterator == 0)
			ft_putchar('A', 1);
		else if (iterator == x - 1)
			ft_putchar('C', 1);
		else
			ft_putchar('B', 1);
		iterator++;
	}
	ft_putchar('\n', 1);
}

int	validate_rush_value(int x, int y)
{
	if (x <= 0 || y <= 0)
		return (1);
	return (0);
}

void	print_ver_line(int x)
{
	int	iterator_col;

	iterator_col = 0;
	while (iterator_col < x)
	{
		if (iterator_col == 0 || iterator_col == x - 1)
			ft_putchar('B', 1);
		else
			ft_putchar(' ', 1);
		iterator_col++;
	}
	ft_putchar('\n', 1);
}

void	rush(int x, int y)
{
	int	iterator_line;

	iterator_line = 0;
	if (validate_rush_value(x, y) == 1)
		return ;
	while (iterator_line < y)
	{
		if (iterator_line == 0 || iterator_line == y -1)
			print_hor_line(x);
		else
		{
			print_ver_line(x);
		}
		iterator_line++;
	}
}
