/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-20 11:02:52 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-20 11:02:52 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_it(int *value1, int *value2);
void	ft_sort_int_tab(int *tab, int size);

void	ft_swap_it(int *value1, int *value2)
{
	int	temp;

	temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	position;
	int	index;

	position = 0;
	while (position < size)
	{
		index = 0;
		while (index < size - position - 1)
		{
			if (tab[index] > tab[index + 1])
			{
				ft_swap_it(&tab[index], &tab[index + 1]);
			}
			index++;
		}
		position++;
	}
}
