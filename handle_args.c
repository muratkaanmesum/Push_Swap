/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:56:29 by mmesum            #+#    #+#             */
/*   Updated: 2022/11/24 12:43:35 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	error(int error_type)
{
	if (error_type == 1)
		printf("Invalid input");
	else if (error_type == 2)
		printf("Duplicate input");
	exit(0);
}

int	check_num(char *str)
{
	int	i;

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
				error(1);
			j++;
			count++;
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
				error(2);
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
		}
		i++;
	}
	check_dup(arr, get_num_count(argv));
	return (arr);
}
