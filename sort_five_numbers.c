/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:39:54 by mmesum            #+#    #+#             */
/*   Updated: 2022/11/24 14:51:31 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	smallest;

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
}
