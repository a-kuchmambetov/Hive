/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-21 13:31:27 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-21 13:31:27 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] < 32 || str[index] > 126)
			return (0);
		index++;
	}
	return (1);
}
