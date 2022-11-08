#include "push_swap.h"
#include "libft/libft.h"

void sort_three_numbers(t_stack *stack)
{
    if (stack->size != 3)
        return;
    int a = stack->stack[0];
    int b = stack->stack[1];
    int c = stack->stack[2];
    if (a > b && b > c)
    {
        swap_stacks(stack);
        reverse_rotate_stack(stack);
    }
    else if (a > b && b < c && a < c)
    {
        swap_stacks(stack);
    }
    else if (a > b && b < c && a > c)
    {
        rotate_stack(stack);
    }
    else if (a < b && b > c && a < c)
    {
        reverse_rotate_stack(stack);
    }
    else if (a < b && b > c && a > c)
    {
        swap_stacks(stack);
        rotate_stack(stack);
    }
}