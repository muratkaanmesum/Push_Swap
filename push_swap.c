#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int		*arr;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		value;

	i = 0;
	arr = get_args(argc, argv);
	stack_a = init_stack(arr, argc);
	stack_b = malloc(sizeof(t_stack));
	stack_b->stack = malloc(sizeof(int) * (argc - 1));
	stack_b->size = 0;
	stack_b->name = 'b';
	sort_five_numbers(stack_a, stack_b);
	return (0);
}
