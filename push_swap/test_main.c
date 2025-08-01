/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-04 14:15:55 by Artem             #+#    #+#             */
/*   Updated: 2025-07-04 14:15:55 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int push_arr_to_stack(int arr[], int size, t_stack *stack)
{
	int i;
	if (!stack || size <= 0)
		return (0);
	for (i = 0; i < size; i++)
		if (!stack_push(stack, arr[i]))
			return (0);
	return (1);
}

static int print_stack(t_stack *stack)
{
	t_node *current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		ft_putnbr_fd(current->value, 1);
		ft_putstr_fd(" ", 1);
		current = current->next;
	}
	ft_putstr_fd("\n", 1);
	return (1);
}

// int main(void)
//{
//	t_stack stack_a, stack_b;
//	stack_constructor(&stack_a);
//	stack_constructor(&stack_b);

//	int numbers[] = {
//		83, 71, 56, 19, 40, 99, 62, 2, 88, 37,
//		91, 73, 11, 15, 45, 10, 20, 68, 5, 94,
//		58, 46, 97, 60, 85, 33, 78, 30, 92, 18,
//		22, 41, 76, 87, 17, 59, 21, 28, 8, 75,
//		9, 31, 43, 66, 13, 1, 84, 96, 38, 14,
//		47, 26, 16, 89, 64, 12, 24, 93, 50, 67,
//		7, 35, 77, 27, 80, 29, 53, 6, 0, 3,
//		98, 79, 36, 55, 48, 82, 61, 25, 39, 4,
//		65, 34, 49, 44, 57, 86, 23, 95, 42, 63,
//		32, 74, 69, 70, 81, 72, 90, 52, 54, 51};

//	push_arr_to_stack(numbers, 100, &stack_a);
//	//big_sort(&stack_a, &stack_b);
//	print_stack(&stack_a);

//	return 0;
//}

#include <stdio.h>

int main(void)
{
	t_stack stack_a, stack_b;
	stack_constructor(&stack_a);
	stack_constructor(&stack_b);

	// int numbers[] = {7, 10, -5, -1, -2, -9, 4, -8};
	// int test[] = {0, -7};

	int numbers[] = {-3, -9, 4, -2};
	int test[] = {0, -5, -7, 10, 8, 7};
	// int test[] = {8, 7, 0, -5, -7, 10};

	push_arr_to_stack(numbers, 4, &stack_a);
	push_arr_to_stack(test, 6, &stack_b);
	printf("Val %d; Current pos a - %d; Moves - %d\n", numbers[0], stack_vi(&stack_a, numbers[0]), count_moves(&stack_a, &stack_b, numbers[0]));
	printf("Val %d; Current pos a - %d; Moves - %d\n", numbers[1], stack_vi(&stack_a, numbers[1]), count_moves(&stack_a, &stack_b, numbers[1]));
	printf("Val %d; Current pos a - %d; Moves - %d\n", numbers[2], stack_vi(&stack_a, numbers[2]), count_moves(&stack_a, &stack_b, numbers[2]));
	printf("Val %d; Current pos a - %d; Moves - %d\n", numbers[3], stack_vi(&stack_a, numbers[3]), count_moves(&stack_a, &stack_b, numbers[3]));
	// big_sort(&stack_a, &stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);

	return 0;
}

// {-3, -9, 4, -2};
// {0, -5, -7, 10, 8, 7};

// 1 op{-9, 4, -2};
// {-5, -7, 10, 8, 7};

// 2 op{-9, 4, -2};
// {-7, 10, 8, 7};

// 3 op{-9, 4, -2};
// {10, 8, 7};

// 4 op{4, -2};
// {-9, 10, 8, 7};