/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_min_steps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:32:48 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/06 16:32:57 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	calculate_right_position(t_stack *stack, int value)
{
	int	biggest;
	int	i;
	int	smallest;

	biggest = find_biggest(stack);
	i = 0;
	if (value > biggest)
	{
		smallest = find_smallest(stack);
		i = find_index(stack, smallest);
		if (i < stack->size / 2)
			return (i);
		else
			return (stack->size - i);
	}
	else
	{
		while (i < stack->size)
		{
			if (stack->stack[i] > value)
				return (i);
			i++;
		}
	}
	return (-1);
}

int	calculate_rotation_steps(t_stack *stack, int value)
{
	int	index;

	index = find_index(stack, value);
	if (index < stack->size / 2)
		return (index);
	else
		return (stack->size - index);
}

int	calculate_min_steps(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_steps;
	int	cur_value;
	int	cur_value_steps;

	i = 0;
	min_steps = 2147483647;
	while (i < stack_b->size)
	{
		cur_value_steps = 0;
		cur_value_steps += calculate_rotation_steps(stack_b, stack_b->stack[i]);
		cur_value_steps += calculate_right_position(stack_a, stack_b->stack[i]);
		if (cur_value_steps < min_steps)
		{
			min_steps = cur_value_steps;
			cur_value = stack_b->stack[i];
		}
		i++;
	}
	return (cur_value);
}
