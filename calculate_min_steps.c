#include "push_swap.h"

int	calculate_right_position(t_stack *stack, int value)
{
	int	biggest;
	int	i;
	int	smallest;

	biggest = find_biggest(stack);
	i = 0;
	if (value > biggest)
	{
		smallest = find_smallest(stack);
		i = find_index(stack, smallest);
		if (i < stack->size / 2)
			return (i);
		else
			return (stack->size - i);
	}
	else
	{
		while (i < stack->size)
		{
			if (stack->stack[i] > value)
				return (i);
			i++;
		}
	}
	return (-1);
}
int	calculate_rotation_steps(t_stack *stack, int value)
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
		return (index);
	else
		return (stack->size - index);
}

int	calculate_min_steps(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_steps;
	int	cur_value;
	int	cur_value_steps;

	cur_value_steps = 0;
	i = 0;
	min_steps = 2147483647;
	while (i < stack_b->size)
	{
		cur_value = stack_b->stack[i];
		cur_value_steps += calculate_rotation_steps(stack_b, cur_value);
		cur_value_steps += calculate_right_position(stack_a, cur_value);
		if (cur_value_steps < min_steps)
		{
			min_steps = cur_value_steps;
			cur_value = stack_b->stack[i];
		}
		i++;
	}
	return (cur_value);
}
