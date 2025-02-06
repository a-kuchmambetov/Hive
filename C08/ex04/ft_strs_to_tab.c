/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 15:14:06 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-05 15:14:06 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_stock_str
{
int size;
char *str;
char *copy;
} t_stock_str;

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (++index);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		index;

	str = (char *) malloc(sizeof(char) * ft_strlen(src));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (src[index])
	{
		str[index] = src[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_arr;
	int			index;

	index = 0;
	s_arr = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (s_arr == NULL)
		return (NULL);
	index = 0;
	while (index < ac)
	{
		s_arr[index].size = ft_strlen(av[index]) - 1;
		s_arr[index].str = av[index];
		s_arr[index].copy = av[index];
		index++;
	}
	s_arr[index].str = 0;
	return (s_arr);
}

int main()
{
	int size = 1;
	char **strs = malloc(1);
	*strs = malloc(5);
	*strs = "Test";

	t_stock_str *arr ;

	arr = ft_strs_to_tab(size, strs);
	free(strs);
	return 0;
}