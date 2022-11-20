typedef struct s_stack
{
	int *stack;
	int size;
	char name;
} t_stack;
#define DEBUG printf("line: %d\n", __LINE__);
void swap_stacks(t_stack *stack);
t_stack *init_stack(int *arr, int argc);
void rotate_stack(t_stack *stack);
void reverse_rotate_stack(t_stack *stack);
void sort_three_numbers(t_stack *stack);
void sort_five_numbers(t_stack *stack_a, t_stack *stack_b);
void push_to_stack(t_stack *src, t_stack *dest);
void print_stack(t_stack *stack);
int *get_args(int argc, char **argv);
