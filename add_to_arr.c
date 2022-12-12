/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:23:26 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/12 13:23:27 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	add_to_arr(int *arr, char **split, int *j)
{
	int	i;

	i = 0;
	while (split[i])
	{
		arr[*j] = ft_atoi(split[i]);
		free(split[i]);
		i++;
		*j = *j + 1;
	}
}
