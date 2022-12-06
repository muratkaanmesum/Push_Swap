/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:33:12 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/06 16:33:21 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	smart_rotate_stack(t_stack *stack, int value)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == value)
			index = i;
		i++;
	}
	if (index < stack->size / 2)
		rotate_stack(stack);
	else
		reverse_rotate_stack(stack);
}

int	find_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	find_biggest(t_stack *stack)
{
	int	biggest;
	int	i;

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

int	find_smallest(t_stack *stack)
{
	int	smallest;
	int	i;

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
