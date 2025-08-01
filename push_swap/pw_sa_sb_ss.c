/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <Artem@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-06 09:18:29 by Artem             #+#    #+#             */
/*   Updated: 2025-07-06 09:18:29 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int pw_s(t_stack *stack_a)
{
	t_node *first;
	t_node *second;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return (0);
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	second->next = first;
	first->prev = second;
	stack_a->top = second;
	stack_set_btm(stack_a);
	return (1);
}

int pw_sa(t_stack *stack_a)
{
	const int res = pw_s(stack_a);

	if (res == 1)
		ft_putstr_fd("sa\n", 1);
	return (res);
}

int pw_sb(t_stack *stack_b)
{
	const int res = pw_s(stack_b);

	if (res == 1)
		ft_putstr_fd("sb\n", 1);
	return (res);
}

int pw_ss(t_stack *stack_a, t_stack *stack_b)
{
	int result_a;
	int result_b;

	if (!stack_a || !stack_b || !stack_a->top || !stack_b->top)
		return (0);
	result_a = pw_sa(stack_a);
	result_b = pw_sb(stack_b);
	if (result_a && result_b)
	{
		ft_putstr_fd("ss\n", 1);
		return (1);
	}
	else if (!result_a && !result_b)
		return (0);
	else
		return (-1);
}
