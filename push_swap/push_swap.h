/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <akuchmam@student.hive.fi>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-04 12:23:13 by Artem             #+#    #+#             */
/*   Updated: 2025-07-04 12:23:13 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

// List node
typedef struct s_node
{
	int value;
	struct s_node *prev;
	struct s_node *next;
} t_node;

// "Stack" List
typedef struct stack
{
	t_node *top;
	t_node *bottom;
} t_stack;

typedef struct data_ab
{
	int i_a;
	int i_b;
	int size_a;
	int size_b;
	int dir_a; // 1 for up, -1 for down
	int dir_b; // 1 for up, -1 for down
} t_data_ab;

// Stack operations --->

int stack_constructor(t_stack *stack);
int stack_destructor(t_stack *stack);
int stack_push(t_stack *stack, int value);

/// @brief Setting bottom of the stack after completion of the operation.
/// @param stack for which would set bottom element.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int stack_set_btm(t_stack *stack);

/// @brief Get size of the stack.
/// @param stack for which would get size.
/// @return Returns size of the stack, or 0 if stack is NULL.
int stack_size(t_stack *stack);

int stack_vi(t_stack *stack, int value);
int stack_vi_btm(t_stack *stack, int value);
// <--- Stack operations

// Swap ops --->

/// @brief Swap first 2 elements of stack A.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int pw_sa(t_stack *stack_a);

/// @brief Swap first 2 elements of stack B.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int pw_sb(t_stack *stack_b);

/// @brief Simultaneously Swap first 2 elements of stack A and stack B.
/// @param stack_a for which would do operation sa.
/// @param stack_b for which would do operation sb.
/// @return Returns 1 on success, 0 if both operations failed, -1 if one of them failed.
int pw_ss(t_stack *stack_a, t_stack *stack_b);
// <--- Swap ops

// Push ops --->

/// @brief Take top element of B and put on top of A.
/// @param stack_a for which adding new elem on top.
/// @param stack_b from where taking top element.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int pw_pa(t_stack *stack_a, t_stack *stack_b);

/// @brief Take top element of A and put on top of B.
/// @param stack_a from where taking top element.
/// @param stack_b for which adding new elem on top.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int pw_pb(t_stack *stack_a, t_stack *stack_b);
// <--- Push ops

// Rotate ops --->

/// @brief Shift up all elements by 1 of stack A.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int pw_ra(t_stack *stack_a);

/// @brief Shift up all elements by 1 of stack B.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int pw_rb(t_stack *stack_b);

/// @brief Simultaneously shift up all elements by 1 of stack A and stack B.
/// @param stack_a for which would do operation ra.
/// @param stack_b for which would do operation rb.
/// @return Returns 1 on success, 0 if both operations failed, -1 if one of them failed.
int pw_rr(t_stack *stack_a, t_stack *stack_b);

/// @brief Shift down all elements by 1 of stack A.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int pw_rra(t_stack *stack_a);

/// @brief Shift down all elements by 1 of stack B.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int pw_rrb(t_stack *stack_b);

/// @brief Simultaneously shift down all elements by 1 of stack A and stack B.
/// @param stack_a for which would do operation rra.
/// @param stack_b for which would do operation rrb.
/// @return Returns 1 on success, 0 if both operations failed, -1 if one of them failed.
int pw_rrr(t_stack *stack_a, t_stack *stack_b);
// <--- Rotate ops

// Sorting algs--->

/// @brief Sorts a stack with 2 or 3 elements.
/// @param stack_a The stack to be sorted.
/// @return Returns 1 on success, 0 if stack is NULL or empty.
int tiny_sort(t_stack *stack_a);

/// @brief Sorts a stack with more than 3 elements using a radix sort algorithm.
/// @param stack_a The stack to be sorted.
/// @param stack_b The additional stack used during sorting.
/// @return Returns 1 on success, 0 if stack_a is NULL or empty.
int big_sort(t_stack *stack_a, t_stack *stack_b);
// <--- Sorting algs

// Big sort Utility functions --->

int calc_moves_from_data(t_data_ab data, int place_after);
int count_moves(t_stack *stack_a, t_stack *stack_b, int value);
int do_moves(t_stack *stack_a, t_stack *stack_b, int value);
// <--- Big sort Utility functions

#endif