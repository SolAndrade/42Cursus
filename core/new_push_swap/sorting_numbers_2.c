/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_numbers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:00:39 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/10 20:38:30 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_movements(t_stacks *bstack, int *blength)
{
	int	i;
	int	min_moves;
	int	index_min_moves;

	i = 1;
	min_moves = bstack[0].moves;
	index_min_moves = 0;
	while (i < *blength)
	{
		if (bstack[i].moves < min_moves)
		{
			index_min_moves = i;
			min_moves = bstack[i].moves;
		}
		i++;
	}
	return (index_min_moves);
}

void	ft_accomodate_number(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
	int	index;

	index = ft_get_min_movements(bstack, blength);
	if (bstack[index].moves_a >= 1 && bstack[index].moves_b >= 1)
	{
		while (bstack[index].moves_a != 0 && bstack[index].moves_b != 0)
		{
			ft_rotate_stacks(astack, bstack, *alength, *blength, count);
			bstack[index].moves_a--;
			bstack[index].moves_b--;
		}
	}
	else if (bstack[index].moves_a < 0 && bstack[index].moves_b < 0)
	{
		while (bstack[index].moves_a != 0 && bstack[index].moves_b != 0)
		{
			ft_rotate_reverse_stacks(astack, bstack, *alength, *blength, count);
			bstack[index].moves_a++;
			bstack[index].moves_b++;
		}
	}
	ft_accomodate_number_2(astack, bstack, alength, blength, count);
	ft_accomodate_number_3(bstack, blength, count);
}

void	ft_accomodate_number_2(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
	int	index;

	index = ft_get_min_movements(bstack, blength);
	if (bstack[index].moves_a > 0)
	{
		while (bstack[index].moves_a != 0)
		{
			ft_rotate_a(astack, *alength, count);
			bstack[index].moves_a--;
		}
	}
	else if (bstack[index].moves_a < 0)
	{
		while (bstack[index].moves_a != 0)
		{
			ft_rotate_reverse_a(astack, *alength, count);
			bstack[index].moves_a++;
		}
	}
}

void	ft_accomodate_number_3(t_stacks *bstack, int *blength, int *count)
{
	int	index;

	index = ft_get_min_movements(bstack, blength);
	if (bstack[index].moves_b > 0)
	{
		while (bstack[index].moves_b != 0)
		{
			ft_rotate_b(bstack, *blength, count);
			bstack[index].moves_b--;
		}
	}
	else if (bstack[index].moves_b < 0)
	{
		while (bstack[index].moves_b != 0)
		{
			ft_rotate_reverse_b(bstack, *blength, count);
			bstack[index].moves_b++;
		}
	}
}
