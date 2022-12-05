#include "push_swap.h"
#include <stdlib.h>
void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	copy_stack(int *src, int *dest, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}
int	*get_sorted_arr(t_stack *stack)
{
	int	*sorted_arr;

	sorted_arr = (int *)malloc(sizeof(int) * stack->size);
	copy_stack(stack->stack, sorted_arr, stack->size);
	sort_arr(sorted_arr, stack->size);
	return (sorted_arr);
}
