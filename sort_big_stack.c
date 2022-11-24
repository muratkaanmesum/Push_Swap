/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:12:54 by mmesum            #+#    #+#             */
/*   Updated: 2022/11/24 16:21:25 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
t_pos	*find_sorted_section(t_stack *stack)
{
	int		i;
	int		startindex;
	int		biggestsec;
	t_pos	*pos;

	i = 0;
	startindex = 0;
	pos = malloc(sizeof(t_pos));
	biggestsec = 0;
	while (startindex < stack->size - 1)
	{
		i = startindex;
		while (stack->stack[i] < stack->stack[i + 1])
			i++;
		if (i - startindex > biggestsec)
		{
			biggestsec = i - startindex;
			pos->start = startindex;
			pos->end = i;
		}
		startindex++;
	}
	return (pos);
}

void	push_non_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_pos	*sorted_pos;
	int		i;
	int		startvalue;

	i = 0;
	sorted_pos = find_sorted_section(stack_a);
	startvalue = stack_a->stack[sorted_pos->start];
	while (stack_a->size > sorted_pos->end - sorted_pos->start + 1)
	{
		if (stack_a->stack[0] == startvalue)
		{
			while (i < sorted_pos->end - sorted_pos->start + 1)
			{
				rotate_stack(stack_a);
				i++;
			}
		}
		push_to_stack(stack_a, stack_b);
	}
}

void	push_min_step(t_stack *stack_a, t_stack *stack_b, int min_step_value)
{
	int	smallest;

	while (stack_b->stack[0] != min_step_value)
		smart_rotate_stack(stack_b, min_step_value);
	if (min_step_value > find_biggest(stack_a))
	{
		smallest = find_smallest(stack_a);
		while (stack_a->stack[0] != smallest)
			smart_rotate_stack(stack_a, smallest);
		push_to_stack(stack_b, stack_a);
	}
	else
	{
		while (stack_a->stack[0] > min_step_value)
			smart_rotate_stack(stack_a, min_step_value);
	}
}
void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	min_step_value;

	push_non_sorted(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		min_step_value = calculate_min_steps(stack_a, stack_b);
		push_min_step(stack_a, stack_b, min_step_value);
	}
}
