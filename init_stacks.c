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
