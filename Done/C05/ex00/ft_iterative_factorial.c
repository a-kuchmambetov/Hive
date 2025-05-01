/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 12:01:07 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-03 12:01:07 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	index;
	int	result;

	if (nb < 0)
		return (0);
	result = 1;
	index = 1;
	while (index <= nb)
	{
		result *= index;
		index++;
	}
	return (result);
}
