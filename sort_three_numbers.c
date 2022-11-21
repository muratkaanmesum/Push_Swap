/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:59:53 by mmesum            #+#    #+#             */
/*   Updated: 2022/11/21 11:00:00 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_three_numbers(t_stack *stack)
{
	int	b;
	int	c;
	int	a;

	if (stack->size != 3)
		return ;
	a = stack->stack[0];
	b = stack->stack[1];
	c = stack->stack[2];
	if (a > b && b > c)
	{
		swap_stacks(stack);
		reverse_rotate_stack(stack);
	}
	else if (a > b && b < c && a < c)
	{
		swap_stacks(stack);
	}
	else if (a > b && b < c && a > c)
	{
		rotate_stack(stack);
	}
	else if (a < b && b > c && a < c)
	{
		swap_stacks(stack);
		rotate_stack(stack);
	}
	else if (a < b && b > c && a > c)
	{
		reverse_rotate_stack(stack);
	}
}
