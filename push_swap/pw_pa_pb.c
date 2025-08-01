/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-04 13:57:58 by Artem             #+#    #+#             */
/*   Updated: 2025-07-04 13:57:58 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int pw_p(t_stack *stack_a, t_stack *stack_b)
{
	t_node *top_b;

	if (!stack_b || !stack_b->top)
		return (0);
	top_b = stack_b->top;
	stack_b->top = top_b->next;
	if (stack_b->top)
		stack_b->top->prev = NULL;
	top_b->next = stack_a->top;
	if (stack_a->top)
		stack_a->top->prev = top_b;
	top_b->prev = NULL;
	stack_a->top = top_b;
	if (!stack_a->bottom)
		stack_a->bottom = top_b;
	return (1);
}

int pw_pa(t_stack *stack_a, t_stack *stack_b)
{
	const int	res = pw_p(stack_a, stack_b);

	if (res == 1)
		ft_putstr_fd("pa\n", 1);
	return (res);
}

int pw_pb(t_stack *stack_a, t_stack *stack_b)
{
	const int	res = pw_p(stack_b, stack_a);

	if (res == 1)
		ft_putstr_fd("pb\n", 1);
	return (res);
}