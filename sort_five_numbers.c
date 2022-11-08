#include "push_swap.h"
#include "libft/libft.h"
void sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
    int i = 0;
    int min = stack_a->stack[0];
    
    if (stack_a->size < 5)
    return;
    while (i < stack_a->size)
    {
        if (stack_a->stack[i] < min)
            min = stack_a->stack[i];
        i++;
    }
    while (stack_a->stack[0] != min)
        rotate_stack(stack_a);

    push_to_stack(stack_a, stack_b);
    push_to_stack(stack_a, stack_b);
    sort_three_numbers(stack_a);

    while (stack_b->size != 0)
    {
        if (stack_b->stack[0] <= stack_a->stack[0])
            push_to_stack(stack_b, stack_a);

        else
            rotate_stack(stack_a);
    }
    while (stack_a->stack[0] != min)
        rotate_stack(stack_a);
    print_stacks(stack_a);
    print_stacks(stack_b);
}
