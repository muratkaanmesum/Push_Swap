/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:36:02 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/06 23:53:41 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_biggest(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;

	smallest = find_smallest(stack_a);
	while (stack_a->stack[0] != smallest)
		smart_rotate_stack(stack_a, smallest);
	push_to_stack(stack_b, stack_a);
}

void	push_smallest(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;

	smallest = find_smallest(stack_a);
	while (stack_a->stack[0] != smallest)
		smart_rotate_stack(stack_a, smallest);
	push_to_stack(stack_b, stack_a);
}

int	find_value(int min_step_value, int *sorted_arr, int size, t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		if (sorted_arr[i] == min_step_value)
		{
			while (find_index(stack_a, sorted_arr[i - j]) == -1)
				j++;
			return (sorted_arr[i - j]);
		}
		i++;
	}
	return (-1);
}

void	push_min_step(t_stack *stack_a, t_stack *stack_b, int *sorted_arr,
		int size)
{
	int	smallest;
	int	diff_value;
	int	min_step_value;

	min_step_value = calculate_min_steps(stack_a, stack_b);
	while (stack_b->stack[0] != min_step_value)
		smart_rotate_stack(stack_b, min_step_value);
	if (min_step_value > find_biggest(stack_a))
		push_biggest(stack_a, stack_b);
	else if (min_step_value < find_smallest(stack_a))
		push_smallest(stack_a, stack_b);
	else
	{
		diff_value = find_value(min_step_value, sorted_arr, size, stack_a);
		if (find_index(stack_a, diff_value) < stack_a->size / 2)
		{
			while (stack_a->stack[0] != diff_value)
				smart_rotate_stack(stack_a, diff_value);
			smart_rotate_stack(stack_a, diff_value);
		}
		else
			while (stack_a->stack[stack_a->size - 1] != diff_value)
				smart_rotate_stack(stack_a, diff_value);
		push_to_stack(stack_b, stack_a);
	}
}
