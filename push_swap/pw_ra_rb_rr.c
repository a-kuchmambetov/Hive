/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <Artem@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-06 09:36:45 by Artem             #+#    #+#             */
/*   Updated: 2025-07-06 09:36:45 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pw_r(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (0);
	first = stack_a->top;
	last = stack_a->bottom;
	stack_a->top = first->next;
	stack_a->top->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	stack_a->bottom = first;
	return (1);
}

int	pw_ra(t_stack *stack_a)
{
	const int	res = pw_r(stack_a);

	if (res == 1)
		ft_putstr_fd("ra\n", 1);
	return (res);
}

int	pw_rb(t_stack *stack_b)
{
	const int	res = pw_r(stack_b);

	if (res == 1)
		ft_putstr_fd("rb\n", 1);
	return (res);
}

int	pw_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	result_a;
	int	result_b;

	if (!stack_a || !stack_b || !stack_a->top || !stack_b->top)
		return (0);
	result_a = pw_r(stack_a);
	result_b = pw_r(stack_b);
	if (result_a && result_b)
	{
		ft_putstr_fd("rr\n", 1);
		return (1);
	}
	else if (!result_a && !result_b)
		return (0);
	else
		return (-1);
}
