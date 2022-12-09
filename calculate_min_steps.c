/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_min_steps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:32:48 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/09 13:22:32 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	calculate_in_between(t_stack *stack, int value, int *sorted_arr, int size)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	while (i < size)
	{
		if (sorted_arr[i] == value)
		{
			while (find_index(stack, sorted_arr[i - j]) == -1)
				j++;
			if (find_index(stack, sorted_arr[i - j]) < stack->size / 2)
				return (find_index(stack, sorted_arr[i - j]) + 1);
			else
				return (stack->size - find_index(stack, sorted_arr[i - j]));
		}
		i++;
	}
	return (-1);
}

int	calculate_right_position(t_stack *stack, int value, int *sorted_arr,
		int size)
{
	int	biggest;
	int	i;
	int	j;

	i = 0;
	if (value > find_biggest(stack) || value < find_smallest(stack))
	{
		i = find_index(stack, find_smallest(stack));
		if (i < stack->size / 2)
			return (i + 1);
		else
			return (stack->size - i);
	}
	else
		return (calculate_in_between(stack, value, sorted_arr, size));
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

int	calculate_min_steps(t_stack *stack_a, t_stack *stack_b, int *sorted_arr,
		int size)
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
		cur_value_steps += calculate_right_position(stack_a, stack_b->stack[i],
				sorted_arr, size);
		if (cur_value_steps < min_steps)
		{
			min_steps = cur_value_steps;
			cur_value = stack_b->stack[i];
		}
		i++;
	}
	return (cur_value);
}
