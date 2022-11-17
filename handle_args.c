#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
void	error(int error_type)
{
	if (error_type == 1)
		printf("invalid input");
	exit(0);
}
int	get_num_count(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;
	int	isnewnum;

	printf("get_num_count\n");
	isnewnum = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[j][i] != '\0')
		{
			while (argv[j][i] == ' ')
				i++;
			if (!ft_isdigit(argv[j][i]))
				error(1);
			else if (ft_isdigit(argv[j][i]))
				count++;
			while (argv[j][i] != ' ')
				i++;
		}
		i++;
	}
	return (count);
}
void	get_args(int argc, char **argv)
{
	int		i;
	char	**arr;
	int		numcount;

	numcount = get_num_count(argc, argv);
	printf("%d", numcount);
	i = 0;
}
//"    1 2 3   "
