/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:39:13 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/10 20:38:41 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength)
{
	int	i;

	i = 0;
	printf("astack\n");
	while (i < alength)
	{
		printf("%d\n", astack[i].data);
		i++;
	}
	i = 0;
	printf("bstack\n");
	while (i < blength)
	{
		printf("%d\n", bstack[i].data);
		i++;
	}
}

void	ft_print_stacks_all_data(t_stacks *astack, t_stacks *bstack, int alength, int blength)
{
	int	i;

	i = 0;
	printf("astack\n");
	while (i < alength)
	{
		printf("Pos: %d   Data: %d    Index: %d\n", i, astack[i].data, astack[i].index);
		i++;
	}
	i = 0;
	printf("bstack\n");
	while (i < blength)
	{
		printf("Pos: %d   Data: %d    Index: %d     Target_pos: %d      Moves: %d       Moves_a: %d     Moves_b: %d\n", i, bstack[i].data, bstack[i].index, bstack[i].target_pos, bstack[i].moves, bstack[i].moves_a, bstack[i].moves_b);
		i++;
	}
}

int ft_check_doubles(t_stacks *astack, int *alength)
{
	int i;
	int j;

	i = *alength - 1;
	while(i >= 0)
	{
		j = i - 1;
		while(j >= 0)
		{
			if(astack[i].data == astack[j].data)
				return (1);
			j--;
		}
		i--;
	}
	return (0);
}
