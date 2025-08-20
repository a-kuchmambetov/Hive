/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_count_moves_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <Artem@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-02 13:17:21 by Artem             #+#    #+#             */
/*   Updated: 2025-08-02 13:17:21 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_closest_smallest(t_stack *stack_b, int value)
{
	t_node	*current;
	int		res;

	if (!stack_b || !stack_b->top)
		return (0);
	current = stack_b->top;
	res = INT_MIN;
	while (current)
	{
		if (current->value < value && current->value > res)
			res = current->value;
		current = current->next;
	}
	return (res);
}

int	value_closest_biggest(t_stack *stack_b, int value)
{
	t_node	*current;
	int		res;

	if (!stack_b || !stack_b->top)
		return (0);
	current = stack_b->top;
	res = INT_MAX;
	while (current)
	{
		if (current->value > value && current->value < res)
			res = current->value;
		current = current->next;
	}
	return (res);
}

static int	count_simultanious_moves(t_data_ab data, int *moves)
{
	*moves = 0;
	if (data.dir_a == 1 && data.dir_b == 1)
	{
		*moves = data.i_a + data.i_b;
		if (data.i_a != 0 && data.i_b != 0)
		{
			if (data.i_a > data.i_b)
				*moves = data.i_a;
			else if (data.i_a < data.i_b)
				*moves = data.i_b;
		}
	}
	else if (data.dir_a == -1 && data.dir_b == -1)
	{
		*moves = (data.size_a - data.i_a) + (data.size_b - data.i_b);
		if ((data.size_a - data.i_a) != 0 && (data.size_b - data.i_b) != 0)
		{
			if ((data.size_a - data.i_a) > (data.size_b - data.i_b))
				*moves = (data.size_a - data.i_a);
			else if ((data.size_a - data.i_a) < (data.size_b - data.i_b))
				*moves = (data.size_b - data.i_b);
		}
	}
	return (*moves);
}

static int	calc_moves_from_data(t_data_ab data)
{
	const int	diff[2] = {data.size_a - data.i_a, data.size_b - data.i_b};
	int			moves;

	if (data.dir_a == data.dir_b)
		moves = count_simultanious_moves(data, &moves);
	else
	{
		if (data.dir_a == 1 && data.dir_b == -1)
			moves = data.i_a + diff[1];
		else
			moves = diff[0] + data.i_b;
	}
	return (moves + 1);
}

int	count_moves(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_data_ab	data;
	int			result;

	if (!stack_a || !stack_b || !stack_a->top || !stack_b->top)
		return (-1);
	data.i_a = stack_i_of_v(stack_a, value);
	get_future_pos(stack_b, value, &data.i_b);
	data.size_a = stack_size(stack_a);
	data.size_b = stack_size(stack_b);
	data = get_direction(data);
	result = calc_moves_from_data(data);
	return (result);
}
