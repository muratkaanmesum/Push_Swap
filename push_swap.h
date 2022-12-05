typedef struct s_stack
{
	int		*stack;
	int		size;
	char	name;
}			t_stack;

typedef struct s_pos
{
	int		start;
	int		end;
}			t_pos;
#define DEBUG printf("line: %d\n", __LINE__);
void		swap_stacks(t_stack *stack);
int			get_num_count(char **argv);
t_stack		*init_stack(int *arr, int argc);
void		rotate_stack(t_stack *stack);
void		reverse_rotate_stack(t_stack *stack);
void		sort_three_numbers(t_stack *stack);
void		sort_five_numbers(t_stack *stack_a, t_stack *stack_b);
void		push_to_stack(t_stack *src, t_stack *dest);
void		print_stack(t_stack *stack);
int			*get_args(int argc, char **argv);
void		smart_rotate_stack(t_stack *stack, int value);
void		sort_big_stack(t_stack *stack_a, t_stack *stack_b);
t_pos		*find_sorted_section(t_stack *stack);
int			calculate_min_steps(t_stack *stack_a, t_stack *stack_b);
int			find_biggest(t_stack *stack);
int			find_smallest(t_stack *stack);
int			find_index(t_stack *stack, int value);
int			*get_sorted_arr(t_stack *stack);
