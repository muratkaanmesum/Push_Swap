/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:56:29 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/09 16:49:14 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int	check_num(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		error();
	return (1);
}

int	get_num_count(char **argv)
{
	int		count;
	int		i;
	int		j;
	char	**temp;

	count = 0;
	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		temp = ft_split(argv[i], ' ');
		while (temp[j])
		{
			if (!check_num(temp[j]))
				error();
			j++;
			count++;
			free(temp[j - 1]);
		}
		i++;
		free(temp);
	}
	return (count);
}

static void	check_dup(int *arr, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (arr[i] == arr[j])
				error();
			j++;
		}
		i++;
	}
}

int	*get_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		*arr;
	int		t;
	char	**split;

	j = 0;
	t = 0;
	arr = malloc(sizeof(int) * get_num_count(argv));
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			arr[t] = ft_atoi(split[j]);
			j++;
			t++;
			free(split[j - 1]);
		}
		free(split);
		i++;
	}
	check_dup(arr, get_num_count(argv));
	return (arr);
}
