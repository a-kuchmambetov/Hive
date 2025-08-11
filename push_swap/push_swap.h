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
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// List node
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// "Stack" List
typedef struct stack
{
	t_node	*top;
	t_node	*bottom;
}	t_stack;

// Data structure for storing information about stacks A and B
// and their indices, sizes, and directions of moves. (For big sort)
typedef struct data_ab
{
	int	i_a;
	int	i_b;
	int	size_a;
	int	size_b;
	int	dir_a; // 1 for up, -1 for down
	int	dir_b; // 1 for up, -1 for down
}	t_data_ab;

// Input parsing functions --->

/// @brief Check if the input is valid.
/// @param argc Number of arguments.
/// @param argv Array of arguments.
/// @return Returns array of integers if valid, NULL if invalid.
int			*parse_input(int argc, char *argv[]);
// <--- Input parsing functions

// Stack operations --->

/// @brief Constructor for stack.
/// @param stack to be initialized.
/// @return Returns 1 on success, 0 if stack is NULL.
int			stack_constructor(t_stack *stack);

/// @brief Destructor for stack which frees all allocated memory for nodes.
/// @param stack to be destroyed.
/// @return Returns 1 on success, 0 if stack is NULL.
int			stack_destructor(t_stack *stack);

/// @brief Allocates and pushes a new value onto the top of the stack.
/// @param stack to which the value will be pushed.
/// @param value to be pushed onto the stack.
/// @return Returns 1 on success, 0 if stack is NULL or memory allocation fails
int			stack_push(t_stack *stack, int value);

/// @brief Setting bottom of the stack after completion of the operation.
/// @param stack for which would set bottom element.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			stack_set_btm(t_stack *stack);

/// @brief Get size of the stack.
/// @param stack for which would get size.
/// @return Returns size of the stack, or 0 if stack is NULL.
int			stack_size(t_stack *stack);

/// @brief Get index of the value in the stack.
/// @param stack for which would get top value.
/// @param value to find index of.
/// @return Returns index of the value in the stack, or -1 if stack is NULL or
/// value is not found
int			stack_i_of_v(t_stack *stack, int value);

/// @brief Get value by index of the stack. (Bad implementation, use with care)
/// @param stack for which would get value by index.
/// @param index of the value to get.
/// @return Returns value at the given index, or 0 if stack is NULL or
/// index is out of bounds.
int			stack_v_by_i(t_stack *stack, int index);
// <--- Stack operations

// Swap ops --->

/// @brief Swap first 2 elements of stack A.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			pw_sa(t_stack *stack_a);

/// @brief Swap first 2 elements of stack B.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			pw_sb(t_stack *stack_b);

/// @brief Simultaneously Swap first 2 elements of stack A and stack B.
/// @param stack_a for which would do operation sa.
/// @param stack_b for which would do operation sb.
/// @return Returns 1 on success, 0 if both ops failed, -1 if one failed.
int			pw_ss(t_stack *stack_a, t_stack *stack_b);
// <--- Swap ops

// Push ops --->

/// @brief Take top element of B and put on top of A.
/// @param stack_a for which adding new elem on top.
/// @param stack_b from where taking top element.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			pw_pa(t_stack *stack_a, t_stack *stack_b);

/// @brief Take top element of A and put on top of B.
/// @param stack_a from where taking top element.
/// @param stack_b for which adding new elem on top.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			pw_pb(t_stack *stack_a, t_stack *stack_b);
// <--- Push ops

// Rotate ops --->

/// @brief Shift up all elements by 1 of stack A.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			pw_ra(t_stack *stack_a);

/// @brief Shift up all elements by 1 of stack B.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			pw_rb(t_stack *stack_b);

/// @brief Simultaneously shift up all elements by 1 of stack A and stack B.
/// @param stack_a for which would do operation ra.
/// @param stack_b for which would do operation rb.
/// @return Returns 1 on success, 0 if both ops failed, -1 if one failed.
int			pw_rr(t_stack *stack_a, t_stack *stack_b);

/// @brief Shift down all elements by 1 of stack A.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			pw_rra(t_stack *stack_a);

/// @brief Shift down all elements by 1 of stack B.
/// @param stack for which would do operation.
/// @return Returns 1 on success, 0 if stack or "top node" is empty (NULL).
int			pw_rrb(t_stack *stack_b);

/// @brief Simultaneously shift down all elements by 1 of stack A and stack B.
/// @param stack_a for which would do operation rra.
/// @param stack_b for which would do operation rrb.
/// @return Returns 1 on success, 0 if both ops failed, -1 if one failed.
int			pw_rrr(t_stack *stack_a, t_stack *stack_b);
// <--- Rotate ops

// Sorting algs--->

/// @brief Sorts a stack with 2 or 3 elements.
/// @param stack_a The stack to be sorted.
/// @return Returns 1 on success, 0 if stack is NULL or empty.
int			tiny_sort(t_stack *stack_a);

/// @brief Sorts a stack with more than 3 elements using a radix sort algorithm.
/// @param stack_a The stack to be sorted.
/// @param stack_b The additional stack used during sorting.
/// @return Returns 1 on success, 0 if stack_a is NULL or empty.
int			big_sort(t_stack *stack_a, t_stack *stack_b);
// <--- Sorting algs

// Big sort Utility functions --->

/// @brief Find the index of the smallest value in stack B.
/// @param stack_b The stack to search for the smallest value.
/// @return Returns the index of the smallest value, or 0 if stack_b is NULL
/// or empty, or INT_MIN if no elements are found.
int			value_closest_smallest(t_stack *stack_b, int value);

/// @brief Find the index of the largest value in stack B.
/// @param stack_b The stack to search for the largest value.
/// @return Returns the index of the largest value, or 0 if stack_b is NULL
/// or empty, or INT_MAX if no elements are found.
int			value_closest_biggest(t_stack *stack_b, int value);

/// @brief Get the future position for value from stack A inside of stack B.
/// @param stack_b The stack to search for the value.
/// @param value The value to find the future position of.
/// @param i_b Pointer to an integer to store the index of the value in stack B
/// @return Returns the future position of the value in stack B, or -1 if the
/// value is not found or stack_b is NULL or empty.
int			get_future_pos(t_stack *stack_b, int value, int *i_b);

/// @brief Get direction of the moves for stack A and stack B.
/// @param data The data structure containing information about the stacks.
/// @return Returns a t_data_ab structure containing the direction of the moves
/// for stack A and stack B, 1 for r_ ops and -1 for rr_ ops.
t_data_ab	get_direction(t_data_ab data);

/// @brief Count the number of moves needed to place a value from stack A
/// inside stack B.
/// @param stack_a The stack A to get index of given value.
/// @param stack_b The stack B to get index of the future position for value.
/// @param value The value to find the number of moves for.
/// @return Returns the number of moves needed to place the value from stack A
/// inside stack B, or -1 if stack A or stack B is NULL or empty.
int			count_moves(t_stack *stack_a, t_stack *stack_b, int value);

/// @brief Perform the moves to place a value from stack A inside stack B.
/// @param stack_a The stack A to get index of given value.
/// @param stack_b The stack B to get index of the future position for value.
/// @param value The value to find the number of moves for.
/// @return Returns 1 on success, -1 if stack A or stack B is NULL or empty.
int			do_moves(t_stack *stack_a, t_stack *stack_b, int value);
// <--- Big sort Utility functions

#endif