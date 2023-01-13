/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:36:57 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 16:55:01 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_stacks *bstack)
{
	t_movements	tm;

	tm.aux = bstack[0].data;
	tm.aux_index = bstack[0].index;
	bstack[0].data = bstack[1].data;
	bstack[0].index = bstack[1].index;
	bstack[1].data = tm.aux;
	bstack[1].index = tm.aux_index;
	write(1, "sb\n", 3);
}

void	ft_rotate_b(t_stacks *bstack, int bl)
{
	t_movements	tm;

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
	write(1, "rb\n", 3);
}

void	ft_rotate_reverse_b(t_stacks *bstack, int bl)
{
	t_movements	tm;

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
	write(1, "rrb\n", 4);
}

void	ft_push_b(t_stacks *astack, t_stacks *bstack, int *al, int *bl)
{
	t_movements	tm;

	tm.i = 0;
	tm.aux = astack[0].data;
	tm.aux_index = astack[0].index;
	while (tm.i < *al - 1)
	{
		astack[tm.i].data = astack[tm.i + 1].data;
		astack[tm.i].index = astack[tm.i + 1].index;
		tm.i++;
	}
	astack[tm.i].data = '\0';
	astack[tm.i].index = '\0';
	*al -= 1;
	tm.i = *bl;
	while (tm.i > 0)
	{
		bstack[tm.i].data = bstack[tm.i - 1].data;
		bstack[tm.i].index = bstack[tm.i - 1].index;
		tm.i--;
	}
	bstack[0].data = tm.aux;
	bstack[0].index = tm.aux_index;
	*bl += 1;
	write(1, "pb\n", 3);
}
