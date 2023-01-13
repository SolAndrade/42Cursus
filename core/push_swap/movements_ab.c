/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:37:53 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 16:55:48 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_stacks(t_stacks *astack, t_stacks *bstack)
{
	t_movements	tm;

	tm.aux = astack[0].data;
	tm.aux_index = astack[0].index;
	astack[0].data = astack[1].data;
	astack[0].index = astack[1].index;
	astack[1].data = tm.aux;
	astack[1].index = tm.aux_index;
	tm.aux = bstack[0].data;
	tm.aux_index = bstack[0].index;
	bstack[0].data = bstack[1].data;
	bstack[0].index = bstack[1].index;
	bstack[1].data = tm.aux;
	bstack[1].index = tm.aux_index;
	write(1, "ss\n", 3);
}

void	ft_rotate_stacks(t_stacks *astack, t_stacks *bstack, int al, int bl)
{
	t_movements	tm;

	tm.i = 0;
	tm.aux = astack[tm.i].data;
	tm.aux_index = astack[tm.i].index;
	while (tm.i < al - 1)
	{
		astack[tm.i].data = astack[tm.i + 1].data;
		astack[tm.i].index = astack[tm.i + 1].index;
		tm.i++;
	}
	astack[tm.i].data = tm.aux;
	astack[tm.i].index = tm.aux_index;
	tm.i = 0;
	tm.aux = bstack[tm.i].data;
	tm.aux_index = bstack[tm.i].index;
	while (tm.i < bl - 1)
	{
		bstack[tm.i].data = bstack[tm.i + 1].data;
		bstack[tm.i].index = bstack[tm.i + 1].index;
		tm.i++;
	}
	bstack[tm.i].data = tm.aux;
	bstack[tm.i].index = tm.aux_index;
	write(1, "rr\n", 3);
}

void	ft_rotate_re_stacks(t_stacks *astack, t_stacks *bstack, int al, int bl)
{
	t_movements	tm;

	al--;
	tm.aux = astack[al].data;
	tm.aux_index = astack[al].index;
	while (al > 0)
	{
		astack[al].data = astack[al - 1].data;
		astack[al].index = astack[al - 1].index;
		al--;
	}
	astack[0].data = tm.aux;
	astack[0].index = tm.aux_index;
	bl--;
	tm.aux = bstack[bl].data;
	tm.aux_index = bstack[bl].index;
	while (bl > 0)
	{
		bstack[bl].data = bstack[bl - 1].data;
		bstack[bl].index = bstack[bl - 1].index;
		bl--;
	}
	bstack[0].data = tm.aux;
	bstack[0].index = tm.aux_index;
	write(1, "rrr\n", 4);
}
