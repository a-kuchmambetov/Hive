/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 13:42:44 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-03 13:42:44 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	*arr;
	int	length;

	if (min >= max)
	{	
		*range = NULL;
		return (0);
	}
	length = max - min;
	arr = (int *)malloc(length * sizeof(int));
	if (arr == NULL)
		return (-1);
	index = 0;
	while (min < max)
		arr[index++] = min++;
	*range = arr;
	return (length);
}
