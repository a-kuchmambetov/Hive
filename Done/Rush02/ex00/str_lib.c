/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 15:02:52 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-01 15:02:52 by akuchmam         ###   ########akuchmam  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_str_equal(char *str1, char *str2)
{
	int	index;
	int	result;

	result = 0;
	index = 0;
	while (str1[index] || str2[index])
	{
		if (str1[index] != str2[index])
		{
			result = str1[index] - str2[index];
			break ;
		}
		index++;
	}
	if (result == 0)
		return (1);
	return (0);
}

int	ft_str_length(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_str_print(char *str)
{
	if (str == 0)
		return ;
	write(1, str, ft_str_length(str));
}

void	ft_str_print_with_space(char *str)
{
	if (str == 0)
		return ;
	write(1, str, ft_str_length(str));
	write(1, " ", 1);
}

// '\0' included in size
char	*ft_str_malloc(int size)
{
	char	*str;

	str = (char *)malloc(size * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size - 1] = '\0';
	return (str);
}
