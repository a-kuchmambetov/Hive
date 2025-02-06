/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 16:19:57 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-16 16:19:57 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int	*nbr;

	ft_ft(nbr);
	printf("%d", *nbr);
	return (0);
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
