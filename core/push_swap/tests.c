/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:39:13 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:04:47 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_doubles(t_stacks *astack, int *alength)
{
	int	i;
	int	j;

	i = *alength - 1;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (astack[i].data == astack[j].data)
				return (1);
			j--;
		}
		i--;
	}
	return (0);
}
