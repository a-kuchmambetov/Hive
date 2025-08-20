/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <Artem@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-09 10:30:13 by Artem             #+#    #+#             */
/*   Updated: 2025-07-09 10:30:13 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pw_rr_base(t_stack *stack_a)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (0);
	last = stack_a->bottom;
	second_last = last->prev;
	stack_a->bottom = second_last;
	second_last->next = NULL;
	last->next = stack_a->top;
	last->prev = NULL;
	stack_a->top->prev = last;
	stack_a->top = last;
	return (1);
}

int	pw_rra(t_stack *stack_a)
{
	const int	res = pw_rr_base(stack_a);

	if (res == 1)
		ft_putstr_fd("rra\n", 1);
	return (res);
}

int	pw_rrb(t_stack *stack_b)
{
	const int	res = pw_rr_base(stack_b);

	if (res == 1)
		ft_putstr_fd("rrb\n", 1);
	return (res);
}

int	pw_rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	result_a;
	int	result_b;

	if (!stack_a || !stack_b || !stack_a->top || !stack_b->top)
		return (0);
	result_a = pw_rr_base(stack_a);
	result_b = pw_rr_base(stack_b);
	if (result_a && result_b)
	{
		ft_putstr_fd("rrr\n", 1);
		return (1);
	}
	else if (!result_a && !result_b)
		return (0);
	else
		return (-1);
}
