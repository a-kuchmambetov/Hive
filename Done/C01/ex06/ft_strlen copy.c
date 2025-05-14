/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 10:56:08 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-17 10:56:08 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

//int main(void)
//{
//	int length = ft_strlen("123");

//	printf("%d\n", length);
//	return 0;
//}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
		index++;
	return (index);
}
