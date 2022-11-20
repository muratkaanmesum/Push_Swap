#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
void error(int error_type)
{
	if (error_type == 1)
		printf("invalid input");
	else if (error_type == 2)
		printf("duplicate input");
	exit(0);
}
int check_num(char *str)
{
	int i;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
int get_num_count(char **argv)
{
	int count = 0;
	int i = 1;
	int j = 0;
	char **temp;
	while (argv[i])
	{
		j = 0;
		temp = ft_split(argv[i], ' ');
		while (temp[j])
		{
			if (!check_num(temp[j]))
				error(1);
			j++;
			count++;
		}
		i++;
		free(temp);
	}
	return (count);
}
static void check_dup(int *arr, int argc)
{
	int i;
	int j;
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (arr[i] == arr[j])
				error(2);
			j++;
		}
		i++;
	}
}
int *get_args(int argc, char **argv)
{
	int i;
	int j = 0;
	int *arr;
	int numcount = get_num_count(argv);
	int t = 0;
	arr = malloc(sizeof(int) * numcount);
	i = 1;
	while (i < argc)
	{
		char **split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			arr[t] = ft_atoi(split[j]);
			j++;
			t++;
		}
		i++;
	}
	check_dup(arr, numcount);

	return (arr);
}
