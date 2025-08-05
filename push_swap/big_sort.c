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

static int	find_val_to_move(t_stack *stack_a, t_stack *stack_b)
{
	int		best_moves;
	int		current_moves;
	int		best_index;
	t_node	*current;

	current = stack_a->top;
	current_moves = INT_MAX;
	best_moves = INT_MAX;
	best_index = INT_MAX;
	while (current)
	{
		current_moves = count_moves(stack_a, stack_b, current->value);
		if (current_moves < best_moves)
		{
			best_moves = current_moves;
			best_index = stack_i_of_v(stack_a, current->value);
		}
		current = current->next;
	}
	return (best_index);
}

static void	move_from_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		place_after_v;

	current = stack_b->top;
	place_after_v = 0;
	while (stack_size(stack_b) > 0)
	{
		place_after_v = value_closest_biggest(stack_a, stack_a->bottom->value);
		if (stack_a->bottom->value > current->value
			&& place_after_v == stack_a->top->value)
		{
			pw_rra(stack_a);
			continue ;
		}
		pw_pa(stack_a, stack_b);
		current = stack_b->top;
	}
	while (stack_a->top->value > stack_a->bottom->value)
		pw_rra(stack_a);
}

int	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	val_i;

	if (!stack_a || !stack_b)
		return (0);
	if (stack_size(stack_a) >= 5)
	{
		pw_pb(stack_a, stack_b);
		pw_pb(stack_a, stack_b);
	}
	while (stack_size(stack_a) > 3)
	{
		val_i = find_val_to_move(stack_a, stack_b);
		do_moves(stack_a, stack_b, stack_v_by_i(stack_a, val_i));
	}
	tiny_sort(stack_a);
	while (stack_b->top->value < stack_b->bottom->value)
	{
		if (value_closest_smallest(stack_b, INT_MAX) > stack_size(stack_b) / 2)
			pw_rb(stack_b);
		else
			pw_rrb(stack_b);
	}
	move_from_b_to_a(stack_a, stack_b);
	return (1);
}

/* place_after - 0 don't place after found index;
place_after - 1 place after found index; when there are no closest smaller
number, to prevent wrong behavior of direction and calc_moves_from_data
functions. P.S Only when index != 0;
*/
int	get_future_pos(t_stack *stack_b, int value, int *index)
{
	int	res;
	int	place_after;

	place_after = 0;
	res = value_closest_smallest(stack_b, value);
	*index = stack_i_of_v(stack_b, res);
	if (res == INT_MIN)
	{
		res = value_closest_biggest(stack_b, value);
		*index = stack_i_of_v(stack_b, res);
		if (*index > stack_size(stack_b) || res == INT_MAX)
			*index = 0;
		else
			*index = stack_i_of_v(stack_b, res) + 1;
		place_after = 1;
	}
	return (place_after);
}

t_data_ab	get_direction(t_data_ab data)
{
	t_data_ab	result;

	result.i_a = data.i_a;
	result.i_b = data.i_b;
	result.size_a = data.size_a;
	result.size_b = data.size_b;
	if (data.i_a < data.size_a / 2)
		result.dir_a = 1;
	else
		result.dir_a = -1;
	if (data.i_b <= data.size_b / 2)
		result.dir_b = 1;
	else
		result.dir_b = -1;
	return (result);
}
