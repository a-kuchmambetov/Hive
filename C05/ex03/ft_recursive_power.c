/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 12:01:30 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-03 12:01:30 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (nb == 0 && power == 0 || power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	if (power > 1)
		return (nb * ft_recursive_power(nb, power - 1));
}
