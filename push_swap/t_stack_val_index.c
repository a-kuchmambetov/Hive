/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_val_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-22 12:28:13 by Artem             #+#    #+#             */
/*   Updated: 2025-07-22 12:28:13 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get index of a value in the stack from the top.
int	stack_i_of_v(t_stack *stack, int value)
{
	t_node	*current;
	int		index;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	index = 0;
	while (current)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

int	stack_v_by_i(t_stack *stack, int index)
{
	t_node	*current;
	int		iterator;

	if (!stack || !stack->bottom)
		return (-1);
	current = stack->top;
	iterator = 0;
	while (iterator < stack_size(stack) && current)
	{
		if (iterator == index)
			return (current->value);
		current = current->next;
		iterator++;
	}
	return (-1);
}
