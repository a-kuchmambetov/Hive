/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-19 15:15:15 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-19 15:15:15 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	temp_value;
	int	index_range;

	index = 0;
	index_range = size - 1;
	while (index < size / 2)
	{
		temp_value = tab[index];
		tab[index] = tab[index_range - index];
		tab[index_range - index] = temp_value;
		index++;
	}
}
