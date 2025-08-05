/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_do_moves_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem <Artem@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-02 13:12:25 by Artem             #+#    #+#             */
/*   Updated: 2025-08-02 13:12:25 by Artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void do_r_dif(t_data_ab data, t_stack *stack_a, t_stack *stack_b)
{
    const int diff[2] = {data.size_a - data.i_a, data.size_b - data.i_b};
    int i;

    if (data.dir_a == 1 && data.dir_b == -1)
    {
        i = 0;
        while (i++ < data.i_a)
            pw_ra(stack_a);
        i = 0;
        while (i++ < diff[1])
            pw_rrb(stack_b);
    }
    else if (data.dir_a == -1 && data.dir_b == 1)
    {
        i = 0;
        while (i++ < diff[0])
            pw_rra(stack_a);
        i = 0;
        while (i++ < data.i_b)
            pw_rb(stack_b);
    }
}

static void do_r_up(t_data_ab data, t_stack *stack_a, t_stack *stack_b)
{
    const int ra_times = data.i_a;
    const int rb_times = data.i_b;
    int rr_times;
    int i;

    rr_times = 0;
    if (data.i_a != 0 && data.i_b != 0)
    {
        if (data.i_a > data.i_b)
            rr_times = data.i_b;
        else if (data.i_a < data.i_b)
            rr_times = data.i_a;
    }
    i = 0;
    while (i++ < rr_times)
        pw_rr(stack_a, stack_b);
    i = 0;
    while (i++ < ra_times - rr_times)
        pw_ra(stack_a);
    i = 0;
    while (i++ < rb_times - rr_times)
        pw_rb(stack_b);
}

static void do_r_down(t_data_ab data, t_stack *stack_a,
                      t_stack *stack_b)
{
    const int diff[2] = {data.size_a - data.i_a, data.size_b - data.i_b};
    int rr_times;
    int i;

    rr_times = 0;
    if (diff[0] != 0 && diff[1] != 0)
    {
        if (diff[0] > diff[1])
            rr_times = diff[1];
        else if (diff[0] < diff[1])
            rr_times = diff[0];
    }
    i = 0;
    while (i++ < rr_times)
        pw_rrr(stack_a, stack_b);
    i = 0;
    while (i++ < diff[0] - rr_times)
        pw_rra(stack_a);
    i = 0;
    while (i++ < diff[1] - rr_times)
        pw_rrb(stack_b);
}

static void do_moves_from_data(t_data_ab data, t_stack *stack_a,
                               t_stack *stack_b)
{
    if (data.dir_a == 1 && data.dir_b == 1)
        do_r_up(data, stack_a, stack_b);
    else if (data.dir_a == -1 && data.dir_b == -1)
        do_r_down(data, stack_a, stack_b);
    else
        do_r_dif(data, stack_a, stack_b);
}

int do_moves(t_stack *stack_a, t_stack *stack_b, int value)
{
    t_data_ab data;
    int place_after;

    if (!stack_a || !stack_b || !stack_a->top || !stack_b->top)
        return (-1);
    data.i_a = stack_i_of_v(stack_a, value);
    place_after = get_future_pos(stack_b, value, &data.i_b);
    data.size_a = stack_size(stack_a);
    data.size_b = stack_size(stack_b);
    data = get_direction(data);
    do_moves_from_data(data, stack_a, stack_b);
    pw_pb(stack_a, stack_b);
    if (place_after == 1)
        pw_rb(stack_b);
    return (1);
}
