/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:37:53 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/11 18:01:27 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_stacks(t_stacks *astack, t_stacks *bstack, int *count)
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
	*count = *count + 1;
}

void	ft_rotate_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength, int *count)
{
	t_movements	tm;

	tm.i = 0;
	tm.aux = astack[tm.i].data;
	tm.aux_index = astack[tm.i].index;
	while (tm.i < alength - 1)
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
	while (tm.i < blength - 1)
	{
		bstack[tm.i].data = bstack[tm.i + 1].data;
		bstack[tm.i].index = bstack[tm.i + 1].index;
		tm.i++;
	}
	bstack[tm.i].data = tm.aux;
	bstack[tm.i].index = tm.aux_index;
	write(1, "rr\n", 3);
	*count = *count + 1;
}

void	ft_rotate_reverse_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength, int *count)
{
	t_movements	tm;

	alength--;
	tm.aux = astack[alength].data;
	tm.aux_index = astack[alength].index;
	while (alength > 0)
	{
		astack[alength].data = astack[alength - 1].data;
		astack[alength].index = astack[alength - 1].index;
		alength--;
	}
	astack[0].data = tm.aux;
	astack[0].index = tm.aux_index;
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
	write(1, "rrr\n", 4);
	*count = *count + 1;
}
