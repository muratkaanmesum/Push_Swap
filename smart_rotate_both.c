#include "./libft/libft.h"
#include "push_swap.h"
void	rotate_stack_temp(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size > 1)
	{
		temp = stack->stack[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->stack[i] = stack->stack[i + 1];
			i++;
		}
		stack->stack[i] = temp;
	}
}

void	reverse_rotate_stack_temp(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size > 1)
	{
		temp = stack->stack[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->stack[i] = stack->stack[i - 1];
			i--;
		}
		stack->stack[i] = temp;
	}
}
void	smart_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack_temp(stack_a);
	rotate_stack_temp(stack_b);
	ft_putstr_fd("rr\n", 1);
}
void	smart_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_stack_temp(stack_a);
	reverse_rotate_stack_temp(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
