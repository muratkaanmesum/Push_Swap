#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *arr = malloc(sizeof(int) * argc);
    char **values = malloc(sizeof(char *) * 6);
    values[0] = "16";
    values[1] = "3";
    values[2] = "4";
    values[3] = "7";
    values[4] = "15";

    argc = 6;

    int i = 0;
    // while (argc > 1)
    // {
    //     int value = ft_atoi(argv[argc - 1]);
    //     arr[argc - 2] = value;
    // }

    while (i < 5)
    {
        int value = ft_atoi(values[i]);
        if (value == 0 && values[i][0] != '0')
        {
            printf("Error\n");
            free(arr);
            return 0;
        }
        arr[i] = value;
        i++;
    }
    t_stack *stack_a = init_stack(arr, argc);
    t_stack *stack_b = malloc(sizeof(t_stack));
    stack_a->name = 'a';
    stack_b->stack = malloc(sizeof(int) * argc);
    stack_b->size = 0;
    stack_b->name = 'b';
    sort_five_numbers(stack_a, stack_b);
    return 0;
}
