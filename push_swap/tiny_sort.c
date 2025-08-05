/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-14 09:36:29 by Artem             #+#    #+#             */
/*   Updated: 2025-07-14 09:36:29 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int stack_gvtop(t_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	return (stack->top->value);
}

static int stack_gvtop_next(t_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	return (stack->top->next->value);
}

static int stack_gvbot(t_stack *stack)
{
	if (!stack || !stack->bottom)
		return (0);
	return (stack->bottom->value);
}

int tiny_sort(t_stack *stack_a)
{
	int size;

	if (!stack_a || !stack_a->top)
		return (0);
	size = stack_size(stack_a);
	if (size == 2)
	{
		if (stack_gvtop(stack_a) > stack_gvtop_next(stack_a))
			pw_sa(stack_a);
	}
	else if (size == 3)
	{
		if (stack_gvtop(stack_a) > stack_gvtop_next(stack_a) && stack_gvtop(stack_a) > stack_gvbot(stack_a))
			pw_ra(stack_a);
		else if (stack_gvtop_next(stack_a) > stack_gvtop(stack_a) && stack_gvtop_next(stack_a) > stack_gvbot(stack_a))
			pw_rra(stack_a);
		if (stack_gvtop(stack_a) > stack_gvtop_next(stack_a))
			pw_sa(stack_a);
	}
	return (1);
}
