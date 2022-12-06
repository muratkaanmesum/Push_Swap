#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
int	check_if_sorted(t_stack *stack_a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (stack_a->stack[i] > stack_a->stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	arr = get_args(argc, argv);
	stack_a = init_stack(arr, get_num_count(argv));
	stack_b = malloc(sizeof(t_stack));
	stack_b->stack = malloc(sizeof(int) * get_num_count(argv));
	stack_b->size = 0;
	stack_b->name = 'b';
	if (check_if_sorted(stack_a))
		return (1);
	if (stack_a->size == 2 && stack_a->stack[0] > stack_a->stack[1])
		swap_stacks(stack_a);
	if (stack_a->size < 6)
		sort_five_numbers(stack_a, stack_b);
	else
		sort_big_stack(stack_a, stack_b);
	free(stack_a->stack);
	free(stack_a);
	free(stack_b->stack);
	free(stack_b);
	return (0);
}
