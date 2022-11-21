/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:59:45 by mmesum            #+#    #+#             */
/*   Updated: 2022/11/21 10:59:46 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
void	rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size > 1)
	{
		temp = stack->stack[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->stack[i] = stack->stack[i + 1];
			i++;
		}
		stack->stack[i] = temp;
	}
	// ft_putchar_fd('r', 1);
	// ft_putchar_fd(stack->name, 1);
	printf("%s%c\n", "r", stack->name);
}
void	reverse_rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size > 1)
	{
		temp = stack->stack[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->stack[i] = stack->stack[i - 1];
			i--;
		}
		stack->stack[i] = temp;
	}
	// ft_putstr_fd("rr", 1);
	// ft_putchar_fd(stack->name, 1);
	printf("%s%c\n", "rr", stack->name);
}

void	swap_stacks(t_stack *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = temp;
	}
	// ft_putchar_fd('s', 1);
	// ft_putchar_fd(stack->name, 1);
	printf("%s%c\n", "s", stack->name);
}

void	push_to_stack(t_stack *src, t_stack *dest)
{
	int	i;

	if (src->size > 0)
	{
		i = dest->size;
		while (i > 0)
		{
			dest->stack[i] = dest->stack[i - 1];
			i--;
		}
		dest->stack[0] = src->stack[0];
		i = 0;
		while (i < src->size - 1)
		{
			src->stack[i] = src->stack[i + 1];
			i++;
		}
		src->stack[i] = 0;
		src->size--;
		dest->size++;
	}
	// ft_putchar_fd('p', 1);
	// ft_putchar_fd(dest->name, 1);
	printf("%s%c\n", "p", dest->name);
}
void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		printf("%d ", stack->stack[i]);
		i++;
	}
	printf("\n");
}
