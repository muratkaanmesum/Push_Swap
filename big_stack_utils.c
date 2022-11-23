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
