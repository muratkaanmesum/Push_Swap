SRCS = init_stacks.c push_swap.c sort_three_numbers.c \
stack_operations.c sort_five_numbers.c handle_args.c \
big_stack_utils.c sort_big_stack.c calculate_min_steps.c \
get_sorted_arr.c push_min_step.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJS			= $(SRCS:.c=.o)

NAME			= push_swap
AR_NAME 		= push_swap.a
RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
	make -C libft/
	ar rc $(AR_NAME) $(OBJS) ./libft/*.o
	gcc -o push_swap $(AR_NAME)

clean:
	make clean -C libft/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft/
	$(RM) $(AR_NAME)
	$(RM) $(NAME)
re: fclean all
