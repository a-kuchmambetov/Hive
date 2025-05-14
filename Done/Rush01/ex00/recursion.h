/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchmam <akuchmam@student.hive.fi>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 16:52:23 by akuchmam          #+#    #+#             */
/*   Updated: 2025-01-26 16:52:23 by akuchmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSION_H
# include "check_board.h"
# define RECURSION_H "recursion"

int	look_for_0_in_board(int board[4][4], int *row, int *col)
{
	*row = 0;
	*col = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (board[*row][*col] == 0)
				return (1);
			*col += 1;
		}
		*row += 1;
	}
	return (0);
}

int	safecol(int board[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (board[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int	saferow(int board[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (board[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int	check_duplicate_digit(int board[4][4], int r, int c, int num)
{
	if (((saferow(board, r, num))
			&& (safecol(board, c, num))
			&& (board[r][c] == 0)))
		return (1);
	return (0);
}

int	recursion(int board[4][4], int *input)
{
	int	row;
	int	col;
	int	n;
	int	has0;
	int	game_win;

	col = 0;
	n = 0;
	has0 = look_for_0_in_board(board, &row, &col);
	game_win = check_board(board, input);
	if ((has0 == (0)) && (game_win == (1)))
		return (1);
	while (n <= 4)
	{
		if (check_duplicate_digit(board, row, col, n))
		{
			board[row][col] = n;
			if (recursion(board, input) == (1))
				return (1);
			board[row][col] = 0;
		}
		n++;
	}
	return (0);
}

#endif