#include "push_swap.h"
#include <stdlib.h>
t_stack	*init_stack(int *arr, int argc)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->stack = arr;
	stack->size = argc - 1;
	stack->name = 'a';
	return (stack);
}
