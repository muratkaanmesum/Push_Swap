/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:03:46 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/09 16:18:12 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int			calculate_min_steps(t_stack *stack_a, t_stack *stack_b,
				int *sorted_arr, int size);
int			find_biggest(t_stack *stack);
int			find_smallest(t_stack *stack);
int			find_index(t_stack *stack, int value);
int			*get_sorted_arr(t_stack *stack);
void		push_min_step(t_stack *stack_a, t_stack *stack_b, int *sorted_arr,
				int size);
void		smart_rotate_both(t_stack *stack_a, t_stack *stack_b);
void		smart_reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void		free_all(t_stack *stack_a, t_stack *stack_b);
#endif
