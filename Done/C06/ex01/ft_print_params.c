/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 11:25:23 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-29 11:25:23 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	iterator;
	int	index;

	iterator = 1;
	while (iterator < argc)
	{
		index = 0;
		while (argv[iterator][index])
		{
			write(1, &argv[iterator][index], 1);
			index++;
		}
		write(1, "\n", 1);
		iterator++;
	}
	return (0);
}
