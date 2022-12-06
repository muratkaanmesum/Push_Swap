/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:34:33 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/06 16:34:34 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*init_stack(int *arr, int count)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->stack = arr;
	stack->size = count;
	stack->name = 'a';
	return (stack);
}
