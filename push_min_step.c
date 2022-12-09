/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:36:02 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/09 13:22:31 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_edge(t_stack *stack_a, t_stack *stack_b)
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

	if (min_step_value < find_smallest(stack_a)
		|| min_step_value > find_biggest(stack_a))
		return (find_smallest(stack_a));
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
int	check_rotate_both(t_stack *stack_a, t_stack *stack_b, int min_step_value,
		int diff_value)
{
	if ((find_index(stack_a, diff_value) < stack_a->size / 2
			&& find_index(stack_b, min_step_value) < stack_b->size / 2)
		&& (stack_a->stack[0] != diff_value
			&& stack_b->stack[0] != min_step_value))
	{
		smart_rotate_both(stack_a, stack_b);
		return (1);
	}
	else if ((find_index(stack_a, diff_value) > stack_a->size / 2
				&& find_index(stack_b, min_step_value) > stack_b->size / 2)
			&& (stack_a->stack[0] != diff_value
				&& stack_b->stack[0] != min_step_value))
	{
		smart_reverse_rotate_both(stack_a, stack_b);
		return (1);
	}
	return (0);
}
void	push_min_step(t_stack *stack_a, t_stack *stack_b, int *sorted_arr,
		int size)
{
	int	smallest;
	int	diff_value;
	int	min_step_value;

	min_step_value = calculate_min_steps(stack_a, stack_b, sorted_arr, size);
	diff_value = find_value(min_step_value, sorted_arr, size, stack_a);
	while (check_rotate_both(stack_a, stack_b, min_step_value, diff_value) == 1)
		;
	while (stack_b->stack[0] != min_step_value)
		smart_rotate_stack(stack_b, min_step_value);
	if (min_step_value > find_biggest(stack_a)
		|| min_step_value < find_smallest(stack_a))
		push_edge(stack_a, stack_b);
	else
	{
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
