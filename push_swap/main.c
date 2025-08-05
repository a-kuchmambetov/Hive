/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 14:35:05 by Artem             #+#    #+#             */
/*   Updated: 2025-08-05 14:35:05 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_arr_to_stack(int arr[], int size, t_stack *stack)
{
	int	i;

	if (!stack || size <= 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!stack_push(stack, arr[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current)
	{
		if (current->next && current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	has_duplicates(int arr[], int size)
{
	int	i;
	int	j;

	if (!arr || size <= 1)
		return (0);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	const int	size_stack_a = stack_size(stack_a);

	if (!sorted(stack_a))
	{
		if (size_stack_a <= 3)
			tiny_sort(stack_a);
		else if (size_stack_a == 4)
		{
			pw_pb(stack_a, stack_b);
			big_sort(stack_a, stack_b);
		}
		else
			big_sort(stack_a, stack_b);
	}
}

// Wrong case 212 78 323 434 454 115 701 315 926 749

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*numbers;
	int		count;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	numbers = parse_input(argc, argv, &count);
	if (!numbers || has_duplicates(numbers, count))
	{
		ft_putstr_fd("Error\n", 1);
		if (numbers)
			free(numbers);
		return (1);
	}
	stack_constructor(&stack_a);
	stack_constructor(&stack_b);
	push_arr_to_stack(numbers, count, &stack_a);
	sort_stack(&stack_a, &stack_b);
	free(numbers);
	stack_destructor(&stack_a);
	stack_destructor(&stack_b);
}
