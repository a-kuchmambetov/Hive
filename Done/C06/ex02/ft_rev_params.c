/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 12:16:41 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-03 12:16:41 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int	iterator;
	int	index;

	iterator = argc - 1;
	while (iterator >= 1)
	{
		index = 0;
		while (argv[iterator][index])
		{
			write(1, &argv[iterator][index], 1);
			index++;
		}
		write(1, "\n", 1);
		iterator--;
	}
	return (0);
}
