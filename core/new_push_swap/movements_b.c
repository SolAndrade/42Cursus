/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:36:57 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/11 18:01:28 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_stacks *bstack, int *count)
{
	t_movements	tm;

	tm.aux = bstack[0].data;
	tm.aux_index = bstack[0].index;
	bstack[0].data = bstack[1].data;
	bstack[0].index = bstack[1].index;
	bstack[1].data = tm.aux;
	bstack[1].index = tm.aux_index;
	write(1, "sb\n", 3);
	*count = *count + 1;
}

void	ft_rotate_b(t_stacks *bstack, int blength, int *count)
{
	t_movements	tm;

	tm.i = 0;
	tm.aux = bstack[tm.i].data;
	tm.aux_index = bstack[tm.i].index;
	while (tm.i < blength - 1)
	{
		bstack[tm.i].data = bstack[tm.i + 1].data;
		bstack[tm.i].index = bstack[tm.i + 1].index;
		tm.i++;
	}
	bstack[tm.i].data = tm.aux;
	bstack[tm.i].index = tm.aux_index;
	write(1, "rb\n", 3);
	*count = *count + 1;
}

void	ft_rotate_reverse_b(t_stacks *bstack, int blength, int *count)
{
	t_movements	tm;

	blength--;
	tm.aux = bstack[blength].data;
	tm.aux_index = bstack[blength].index;
	while (blength > 0)
	{
		bstack[blength].data = bstack[blength - 1].data;
		bstack[blength].index = bstack[blength - 1].index;
		blength--;
	}
	bstack[0].data = tm.aux;
	bstack[0].index = tm.aux_index;
	write(1, "rrb\n", 4);
	*count = *count + 1;
}

void	ft_push_b(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
	t_movements	tm;

	tm.i = 0;
	tm.aux = astack[0].data;
	tm.aux_index = astack[0].index;
	while (tm.i < *alength - 1)
	{
		astack[tm.i].data = astack[tm.i + 1].data;
		astack[tm.i].index = astack[tm.i + 1].index;
		tm.i++;
	}
	astack[tm.i].data = '\0';
	astack[tm.i].index = '\0';
	*alength -= 1;
	tm.i = *blength;
	while (tm.i > 0)
	{
		bstack[tm.i].data = bstack[tm.i - 1].data;
		bstack[tm.i].index = bstack[tm.i - 1].index;
		tm.i--;
	}
	bstack[0].data = tm.aux;
	bstack[0].index = tm.aux_index;
	*blength += 1;
	write(1, "pb\n", 3);
	*count = *count + 1;
}
