/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <Artem@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 17:28:14 by Artem             #+#    #+#             */
/*   Updated: 2025-07-15 17:28:14 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int big_sort(t_stack *stack_a, t_stack *stack_b);

static int index_closest_smallest(t_stack *stack_b, int value)
{
	t_node *current;
	int res;

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

static int index_closest_biggest(t_stack *stack_b, int value)
{
	t_node *current;
	int res;

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

// place_after - 0 don't place after found index;
// place_after - 1 place after found index; when there are no closest smaller number, to prevent wrong behavior of direction and calc_moves_from_data functions. P.S Only when index != 0;
int	get_future_pos(t_stack *stack_b, int value, int *index)
{
	int res;
	int place_after;

	place_after = 0;
	res = index_closest_smallest(stack_b, value);
	*index = stack_vi(stack_b, res);
	if (res == INT_MIN)
	{
		res = index_closest_biggest(stack_b, value);
		if (res > stack_size(stack_b) || res == INT_MAX)
			*index = 0;
		else
		{
			place_after = 1;
			*index = stack_vi(stack_b, res) + 1;
		}
	}
	return (place_after);
}

static t_data_ab	get_direction(t_data_ab data)
{
	t_data_ab	result;

	result.index_a = data.index_a;
	result.index_b = data.index_b;
	result.size_a = data.size_a;
	result.size_b = data.size_b;
	if (data.index_a < data.size_a / 2)
		result.direction_a = 1;
	else
		result.direction_a = -1;
	if (data.index_b < data.size_b / 2)
		result.direction_b = 1;
	else
		result.direction_b = -1;
	return (result);
}

static int calc_moves_from_data(t_data_ab data, int place_after)
{
	int moves;

	if (data.direction_a == 1 && data.direction_b == 1)
	{
		if (data.index_a > data.index_b)
			moves = data.index_a - data.index_b;
		else
			moves = data.index_b - data.index_a;
	}
	else if (data.direction_a == -1 && data.direction_b == -1)
	{
		if ((data.size_a - data.index_a) > (data.size_b - data.index_b))
			moves = (data.size_a - data.index_a) - (data.size_b - data.index_b);
		else
			moves = (data.size_b - data.index_b) - (data.size_a - data.index_a);
	}
	else if (data.direction_a == 1 && data.direction_b == -1)
		moves = data.index_a + (data.size_b - data.index_b);
	else
		moves = (data.size_a - data.index_a) + data.index_b;
	if (place_after)
		return (moves);
	return (moves + 1);
}

int count_moves(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_data_ab	data;
	int	place_after;
	int	result;

	if (!stack_a || !stack_b || !stack_a->top || !stack_b->top)
		return (-1);
	data.index_a = stack_vi(stack_a, value);
	place_after = get_future_pos(stack_b, value, &data.index_b);
	data.size_a = stack_size(stack_a);
	data.size_b = stack_size(stack_b);
	data = get_direction(data);
	result = calc_moves_from_data(data, place_after);
	return (result);
}

static int do_r_up(int ra_times, int rb_times, int rr_times, t_stack *stack_a,
	t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < rr_times)
		pw_rr(stack_a, stack_b);
	i = 0;
	while (i < ra_times)
		pw_ra(stack_a);
	i = 0;
	while (i < rb_times)
		pw_rb(stack_b);
	return (0);
}

static int do_r_down(int ra_times, int rb_times, int rr_times, t_stack *stack_a,
	t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < rr_times)
		pw_rrr(stack_a, stack_b);
	i = 0;
	while (i < ra_times)
		pw_rra(stack_a);
	i = 0;
	while (i < rb_times)
		pw_rrb(stack_b);
	return (0);
}

static int do_move_from_data(t_data_ab data, int place_after, )
{
	int moves;

	if (data.direction_a == 1 && data.direction_b == 1)
	{
		if (data.index_a > data.index_b)
			moves = data.index_a - data.index_b;
		else
			moves = data.index_b - data.index_a;
	}
	else if (data.direction_a == -1 && data.direction_b == -1)
	{
		if ((data.size_a - data.index_a) > (data.size_b - data.index_b))
			moves = (data.size_a - data.index_a) - (data.size_b - data.index_b);
		else
			moves = (data.size_b - data.index_b) - (data.size_a - data.index_a);
	}
	else if (data.direction_a == 1 && data.direction_b == -1)
		moves = data.index_a + (data.size_b - data.index_b);
	else
		moves = (data.size_a - data.index_a) + data.index_b;
	if (place_after)
		return (moves);
	return (moves + 1);
}

int do_moves(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_data_ab	data;
	int	place_after;
	int	result;

	if (!stack_a || !stack_b || !stack_a->top || !stack_b->top)
		return (-1);
	data.index_a = stack_vi(stack_a, value);
	place_after = get_future_pos(stack_b, value, &data.index_b);
	data.size_a = stack_size(stack_a);
	data.size_b = stack_size(stack_b);
	data = get_direction(data);
	result = do_move_from_data(data, place_after);
	return (result);
}