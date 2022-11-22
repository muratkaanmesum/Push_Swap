/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:12:54 by mmesum            #+#    #+#             */
/*   Updated: 2022/11/21 16:06:58 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
int find_biggest(t_stack *stack)
{
    int biggest;
    int i;

    biggest = stack->stack[0];
    i = 0;
    while (i < stack->size)
    {
        if (stack->stack[i] > biggest)
            biggest = stack->stack[i];
        i++;
    }
    return (biggest);
}
void sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
    int middle = stack_a->size / 2;
    int biggest = find_biggest(stack_a);
    while (stack_a->size > middle)
    {

        while (biggest != stack_a->stack[0])
            smart_rotate_stack(stack_a, find_biggest(stack_a));
        push_to_stack(stack_a, stack_b);
    }
}
