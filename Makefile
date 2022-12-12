SRCS = init_stacks.c push_swap.c sort_three_numbers.c \
stack_operations.c sort_small_numbers.c handle_args.c \
big_stack_utils.c sort_big_stack.c calculate_min_steps.c \
get_sorted_arr.c push_min_step.c smart_rotate_both.c \
free_all.c add_to_arr.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME			= push_swap
AR_NAME 		= push_swap.a
RM				= rm -f

OBJS			= $(SRCS:.c=.o)


all:			$(NAME)

$(NAME):		$(OBJS)
	make -C libft/
	ar rcs $(AR_NAME) $(OBJS) ./libft/*.o
	gcc -o push_swap $(AR_NAME)

clean:
	make clean -C libft/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft/
	$(RM) $(AR_NAME)
	$(RM) $(NAME)
re: fclean all
