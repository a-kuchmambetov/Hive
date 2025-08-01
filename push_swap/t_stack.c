/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <Artem@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-06 09:19:06 by Artem             #+#    #+#             */
/*   Updated: 2025-07-06 09:19:06 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_constructor(t_stack *stack)
{
	if (!stack)
		return (0);
	stack->top = NULL;
	stack->bottom = NULL;
	return (1);
}

int stack_destructor(t_stack *stack)
{
	t_node *current;
	t_node *next;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	return (1);
}

int stack_push(t_stack *stack, int value)
{
	t_node *new_node;

	if (!stack)
		return (0);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
		stack_set_btm(stack);
	}
	else
	{
		new_node->prev = stack->bottom;
		stack->bottom->next = new_node;
		stack->bottom = new_node;
	}
	return (1);
}

int stack_set_btm(t_stack *stack)
{
	t_node *current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	if (!current->next)
	{
		stack->bottom = current;
		return (1);
	}
	while (current->next)
		current = current->next;
	stack->bottom = current;
	return (1);
}

int	stack_size(t_stack *stack)
{
	int size;
	t_node *current;

	if (!stack || !stack->top)
		return (0);
	size = 0;
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}