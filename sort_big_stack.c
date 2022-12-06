/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:12:54 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/06 18:58:17 by mmesum           ###   ########.fr       */
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

int	check_sorted(t_stack *stack, t_pos *sorted_pos)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (i < sorted_pos->start || i > sorted_pos->end)
		{
			if (stack->stack[i] > stack->stack[i + 1])
				return (0);
		}
		i++;
	}
	return (1);
}

void	push_non_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_pos	*sorted_pos;
	int		i;
	int		startvalue;

	i = 0;
	sorted_pos = find_sorted_section(stack_a);
	if (check_sorted(stack_a, sorted_pos) == 0)
		while (stack_a->size > 1)
			push_to_stack(stack_a, stack_b);
	else
	{
		startvalue = stack_a->stack[sorted_pos->start];
		while (stack_a->size != sorted_pos->end - sorted_pos->start + 1)
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
}

void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	min_step_value;
	int	*sorted_arr;
	int	size;

	size = stack_a->size;
	sorted_arr = get_sorted_arr(stack_a);
	push_non_sorted(stack_a, stack_b);
	while (stack_b->size > 0)
		push_min_step(stack_a, stack_b, sorted_arr, size);
	while (stack_a->stack[0] != find_smallest(stack_a))
		smart_rotate_stack(stack_a, find_smallest(stack_a));
	free(sorted_arr);
}
