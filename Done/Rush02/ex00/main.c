/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-02 18:57:28 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-02 18:57:28 by akuchmam         ###   ########akuchmam  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_run_1param(char *argv[], int size);
int		ft_run_2param(char *argv[], int size);
void	free_parsed(char *parsed[]);
void	free_dict(t_dict_entry *dict, int size);

int	main(int argc, char *argv[])
{
	int	size;

	size = 0;
	if (argc == 2)
	{
		if (ft_run_1param(argv, size))
			return (1);
	}
	else if (argc == 3)
	{
		if (ft_run_2param(argv, size))
			return (1);
	}
	else
		write_error();
	write(1, "\n", 1);
}

int	ft_run_1param(char *argv[], int size)
{
	t_dict_entry	*dict;
	char			**parsed;

	dict = ft_parse_dict("numbers.dict", &size);
	if (dict == NULL)
	{
		free_dict(dict, size);
		return (1);
	}
	else if (size == -1)
	{
		write(1, "Dict Error", 10);
		return (1);
	}
	parsed = convert_num(argv[1]);
	if (parsed == NULL)
	{
		free_parsed(parsed);
		return (1);
	}
	ft_print_parsed(parsed, dict, size);
	free_parsed(parsed);
	free_dict(dict, size);
	return (0);
}

int	ft_run_2param(char *argv[], int size)
{
	t_dict_entry	*dict;
	char			**parsed;

	dict = ft_parse_dict(argv[2], &size);
	if (dict == NULL)
	{
		free_dict(dict, size);
		return (1);
	}
	else if (size == -1)
	{
		write(1, "Dict Error", 10);
		return (1);
	}
	parsed = convert_num(argv[3]);
	if (parsed == NULL)
	{
		free_parsed(parsed);
		return (1);
	}
	ft_print_parsed(parsed, dict, size);
	free_parsed(parsed);
	free_dict(dict, size);
	return (0);
}

void	free_parsed(char *parsed[])
{
	int	index;

	index = 0;
	while (parsed[index])
		free(parsed[index++]);
	free(parsed);
}

void	free_dict(t_dict_entry *dict, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		free(dict[index].key);
		free(dict[index++].value);
	}
	free(dict);
}
