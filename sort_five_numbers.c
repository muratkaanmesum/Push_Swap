#include "ft_libft/libft.h"
#include "push_swap.h"

static int	find_biggest(t_stack *stack)
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
static int	find_smallest(t_stack *stack)
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
static int	insert_biggest(t_stack *stack_a, t_stack *stack_b, int *biggest)
{
	while (stack_a->stack[0] != *biggest)
		rotate_stack(stack_a);
	*biggest = stack_b->stack[0];
	rotate_stack(stack_a);
	push_to_stack(stack_b, stack_a);
}
void	sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	biggest;
	int	smallest;

	i = 0;
	biggest = stack_a->stack[0];
	if (stack_a->size < 5)
		return ;
	smallest = find_smallest(stack_a);
	push_to_stack(stack_a, stack_b);
	push_to_stack(stack_a, stack_b);
	sort_three_numbers(stack_a);
	biggest = find_biggest(stack_a);
	while (stack_b->size != 0)
	{
		if (stack_b->stack[0] > biggest)
			insert_biggest(stack_a, stack_b, &biggest);
		else
		{
			if (stack_b->stack[0] <= stack_a->stack[0])
				push_to_stack(stack_b, stack_a);
			else
				rotate_stack(stack_a);
		}
	}
	while (stack_a->stack[0] != smallest)
		rotate_stack(stack_a);
	print_stack(stack_a);
}
