SRCS = init_stacks.c push_swap.c sort_three_numbers.c stack_operations.c sort_five_numbers.c

OBJS			= $(SRCS:.c=.o)

NAME			= push_swap.a

all:			$(NAME)

$(NAME):		$(OBJS)
	make -C libft/

clean:
	make clean -C libft/
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
