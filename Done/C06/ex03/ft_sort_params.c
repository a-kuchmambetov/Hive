/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-03 12:16:44 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-03 12:16:44 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_params(int size, char const *argv[]);
int		ft_strcmp(char const *s1, char const *s2);

int	main(int argc, char const *argv[])
{
	int	iterator;
	int	index;

	ft_sort_params(argc, argv);
	iterator = 1;
	while (iterator < argc)
	{
		index = 0;
		while (argv[iterator][index])
		{
			write(1, &argv[iterator][index], 1);
			index++;
		}
		write(1, "\n", 1);
		iterator++;
	}
	return (0);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	int	index;
	int	equal;

	index = 0;
	equal = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index])
		{
			equal = s1[index] - s2[index];
			break ;
		}
		index++;
	}
	return (equal);
}

void	ft_sort_params(int size, char const *argv[])
{
	char const	*temp;
	int			position;
	int			index;

	position = 1;
	while (position < size)
	{
		index = 1;
		while (index < size - position)
		{
			if (ft_strcmp(argv[index], argv[index + 1]) > 0)
			{
				temp = argv[index];
				argv[index] = argv[index + 1];
				argv[index + 1] = temp;
			}
			index++;
		}
		position++;
	}
}
