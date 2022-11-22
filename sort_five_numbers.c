/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:39:54 by mmesum            #+#    #+#             */
/*   Updated: 2022/11/21 16:24:36 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int find_smallest(t_stack *stack)
{
	int smallest;
	int i;

	smallest = stack->stack[0];
	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] < smallest)
			smallest = stack->stack[i];
		i++;
	}
	return (smallest);
}

int find_index(t_stack *stack, int value)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int smallest;

	i = 0;
	smallest = find_smallest(stack_a);
	while (stack_a->size > 3)
	{
		while (stack_a->stack[0] != smallest)
			smart_rotate_stack(stack_a, smallest);

		push_to_stack(stack_a, stack_b);
		smallest = find_smallest(stack_a);
	}
	sort_three_numbers(stack_a);
	while (stack_b->size > 0)
		push_to_stack(stack_b, stack_a);
	print_stack(stack_a);
}
