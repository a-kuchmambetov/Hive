/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 12:16:35 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-03 12:16:35 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *str[])
{
	int	index;

	if (argc)
	{
	}
	index = 0;
	while (str[0][index])
	{
		write(1, &str[0][index], 1);
		index++;
	}
	write(1, "\n", 1);
}
