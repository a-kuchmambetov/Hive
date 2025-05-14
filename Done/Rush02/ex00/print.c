/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 15:02:44 by akuchmam          #+#    #+#             */
/*   Updated: 2025-02-01 15:02:44 by akuchmam         ###   ########akuchmam  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_print_parsed(char **parsed_strs,
t_dict_entry *dict, int dict_size)
{
	int	index;
	int	size;

	index = 0;
	while (parsed_strs[index])
		index++;
	size = index;
	index = size - 1;
	while (index >= 0)
	{
		if (index != size -1
			&& !(parsed_strs[index][2] == '0'
			&& parsed_strs[index][1] == '0' && parsed_strs[index][0] == '0'))
			write(1, " ", 1);
		if (ft_print_group(parsed_strs[index], index, dict, dict_size))
		{
			write(1, " ", 1);
			return (1);
		}
		index--;
	}
	return (0);
}

int	ft_print_group(char *input_str, int group_id,
t_dict_entry *dict, int dict_size)
{
	char	string[3];

	ft_print_hundred(input_str, dict, dict_size);
	string[0] = input_str[1];
	string[1] = '0';
	string[2] = '\0';
	if (input_str[1] != '0' && input_str[1] != '1' && input_str[2] == '0')
		ft_str_print(ft_getval_dict_key(string, dict, dict_size));
	else if (input_str[1] != '0' && input_str[1] != '1' && input_str[2] != '0')
		ft_str_print_with_space(ft_getval_dict_key(string, dict, dict_size));
	string[1] = input_str[2];
	if (input_str[1] == '1' && input_str[2] == '0')
		ft_str_print(ft_getval_dict_key(string, dict, dict_size));
	else if (input_str[1] == '1'
		&& (input_str[2] >= '1' && input_str[2] <= '9'))
		ft_str_print(ft_getval_dict_key(string, dict, dict_size));
	else if (input_str[2] != '0')
		ft_str_print(ft_getvalue_dict_skey(input_str[2], dict, dict_size));
	ft_print_thousands(input_str, group_id, dict, dict_size);
	return (0);
}

void	ft_print_hundred(char *input_str,
t_dict_entry *dict, int dict_size)
{
	if (input_str[0] != '0')
	{
		ft_str_print_with_space(ft_getvalue_dict_skey(input_str[0],
				dict, dict_size));
		if (input_str[1] == '0' && input_str[2] == '0')
			ft_str_print(ft_getval_dict_key("100", dict, dict_size));
		else
			ft_str_print_with_space(
				ft_getval_dict_key("100", dict, dict_size));
	}
}

void	ft_print_thousands(char *input_str, int group_id,
t_dict_entry *dict, int dict_size)
{
	char	*value;
	int		length;
	int		index;

	if (group_id == 0)
		return ;
	length = 4 + (group_id - 1) * 3;
	value = (char *)malloc((length + 1) * sizeof(char));
	value[length] = '\0';
	value[0] = '1';
	index = 1;
	while (index < length)
	{
		value[index] = '0';
		index++;
	}
	if (!(input_str[2] == '0' && input_str[1] == '0' && input_str[0] == '0'))
	{
		write(1, " ", 1);
		ft_str_print(ft_getval_dict_key(value, dict, dict_size));
	}
	free(value);
}
