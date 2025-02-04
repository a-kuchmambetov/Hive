/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 16:55:05 by akuchmam          #+#    #+#             */
/*   Updated: 2025/01/26 22:33:21 by cdavidov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# include <unistd.h>
# include "check_board.h"
# include "recursion.h"
# define PRINT_H "print"

void	print_board(int board[4][4])
{
	int		row;
	int		col;
	char	print_value;

	row = 0;
	col = 0;
	while (row < 4)
	{
		write (1, " ", 1);
		col = 0;
		while (col < 4)
		{
			print_value = board[row][col] + '0';
			write (1, &print_value, 1);
			if (col == 3)
				col++;
			else
				write (1, " ", 1);
			col++;
		}
		write (1, "\n", 1);
		row++;
	}
}

void	search_4_row(int board[4][4], int *input, int pos)
{
	int	fill;

	fill = 0;
	while ((input[pos]) && pos <= 15)
	{
		if ((input[pos] == 4) && ((pos >= 8 && pos <= 11)))
		{
			while (fill < 4)
			{
				board[pos % 4][fill] = fill + 1;
				fill++;
			}
		}
		fill = 4;
		if ((input[pos] == 4) && ((pos >= 12 && pos <= 15)))
		{
			while (fill > 0)
			{
				board[pos % 4][4 - fill] = fill;
				fill--;
			}
		}
		pos++;
	}
}

void	search_4_col(int board[4][4], int *input, int pos)
{
	int	fill;

	fill = 0;
	while ((input[pos]) && pos < 8)
	{
		if ((input[pos] == 4) && ((pos >= 0 && pos <= 3)))
		{
			while (fill < 4)
			{
				board[fill][pos] = fill + 1;
				fill++;
			}
		}
		fill = 4;
		if ((input[pos] == 4) && ((pos >= 4 && pos <= 7)))
		{
			while (fill > 0)
			{
				board[4 - fill][(pos % 4)] = fill;
				fill--;
			}
		}
		pos++;
	}
	search_4_row(board, input, pos);
}

void	search_1(int board[4][4], int *input)
{
	int	pos;

	pos = 0;
	while (input[pos])
	{
		if ((input[pos] == 1) && ((pos >= 0) && (pos <= 3)))
			board[0][pos] = 4;
		if ((input[pos] == 1) && ((pos >= 4) && (pos <= 7)))
			board[3][pos - 4] = 4;
		if ((input[pos] == 1) && ((pos >= 8) && (pos <= 11)))
			board[pos - 8][0] = 4;
		if ((input[pos] == 1) && ((pos >= 12) && (pos <= 15)))
			board[pos - 12][3] = 4;
		pos++;
	}
	pos = 0;
	search_4_col(board, input, pos);
}

int	start_game(int *input)
{
	int	row;
	int	col;
	int	board[4][4];

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	search_1(board, input);
	if (recursion(board, input))
		print_board(board);
	else
		write(1, "Error\n", 6);
	return (0);
}

#endif
