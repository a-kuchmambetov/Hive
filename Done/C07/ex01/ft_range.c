/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 12:31:02 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-03 12:31:02 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	index;
	int	*arr;
	int	length;

	if (min >= max)
		return (NULL);
	length = max - min;
	arr = (int *)malloc(length * sizeof(int));
	if (arr == NULL)
		return (NULL);
	index = 0;
	while (min < max)
		arr[index++] = min++;
	return (arr);
}
