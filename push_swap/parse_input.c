/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 14:35:05 by Artem             #+#    #+#             */
/*   Updated: 2025-08-05 14:35:05 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (is_in_int_range(str));
}

static char	**get_numbers_array(int argc, char *argv[])
{
	char	**numbers;
	int		i;

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
	{
		numbers = ft_calloc(argc, sizeof(char *));
		if (!numbers)
			return (NULL);
		i = 1;
		while (i < argc)
		{
			numbers[i - 1] = argv[i];
			i++;
		}
		numbers[i - 1] = NULL;
	}
	return (numbers);
}

static void	free_numbers_array(char **numbers_str, int argc)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (numbers_str[i])
			free(numbers_str[i++]);
		free(numbers_str);
	}
}

static int	*count_and_calloc_numbers(char **numbers_str, int *count, int argc)
{
	int	*numbers;
	int	i;

	i = 0;
	while (numbers_str[i])
		i++;
	if (i == 0)
	{
		free_numbers_array(numbers_str, argc);
		return (NULL);
	}
	*count = i;
	numbers = ft_calloc(*count, sizeof(int));
	if (!numbers)
	{
		free_numbers_array(numbers_str, argc);
		return (NULL);
	}
	return (numbers);
}

int	*parse_input(int argc, char *argv[], int *count)
{
	char	**numbers_str;
	int		*numbers;
	int		i;

	numbers_str = get_numbers_array(argc, argv);
	if (!numbers_str)
		return (NULL);
	numbers = count_and_calloc_numbers(numbers_str, count, argc);
	if (!numbers)
		return (NULL);
	i = -1;
	while (++i < *count && is_valid_number(numbers_str[i]))
		numbers[i] = ft_atoi(numbers_str[i]);
	if (i < *count)
	{
		free(numbers);
		free_numbers_array(numbers_str, argc);
		return (NULL);
	}
	free_numbers_array(numbers_str, argc);
	return (numbers);
}
