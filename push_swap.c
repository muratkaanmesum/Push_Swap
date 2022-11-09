#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	int		*arr;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		value;

	arr = malloc(sizeof(int) * argc);
	while (argc > 1)
	{
		value = ft_atoi(argv[argc - 1]);
		arr[argc - 2] = value;
	}
	return (0);
}
