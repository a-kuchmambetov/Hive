/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 16:19:09 by akuchmam          #+#    #+#             */
/*   Updated: 2025/01/26 22:31:29 by cdavidov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "check_board.h"
#include "recursion.h"
#include "print.h"

int	validate_input(int *result, char *user_input_str)
{
	int	valid_digit_num;
	int	i;

	i = 0;
	valid_digit_num = 0;
	while (user_input_str[i])
	{
		if ((user_input_str[i] >= '1'
				&& user_input_str[i] <= '4')
			&& ((user_input_str[i + 1] == ' ')
				|| ((user_input_str[i + 1] == 0)
					&& (user_input_str[i - 1] == ' '))))
		{
			result[valid_digit_num] = (user_input_str[i] - '0');
			valid_digit_num++;
			i++;
		}
		if (user_input_str[i] == 32)
			i++;
		else
			break ;
	}
	return (valid_digit_num);
}

int	main(int argc, char **argv)
{
	int		result[16];
	char	*user_input_str;
	int		valid_digit_num;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	user_input_str = argv[1];
	valid_digit_num = validate_input(result, user_input_str);
	result[valid_digit_num] = '\0';
	if (valid_digit_num == 16)
		start_game(result);
	else
		write(1, "Error\n", 6);
	return (0);
}
