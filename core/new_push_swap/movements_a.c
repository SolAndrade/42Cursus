/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:19:32 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/11 18:01:24 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stacks *astack, int *count)
{
	t_movements	tm;

	tm.aux = astack[0].data;
	tm.aux_index = astack[0].index;
	astack[0].data = astack[1].data;
	astack[0].index = astack[1].index;
	astack[1].data = tm.aux;
	astack[1].index = tm.aux_index;
	write(1, "sa\n", 3);
	*count = *count + 1;
}

void	ft_rotate_a(t_stacks *astack, int alength, int *count)
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
	write(1, "ra\n", 3);
	*count = *count + 1;
}

void	ft_rotate_reverse_a(t_stacks *astack, int alength, int *count)
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
	write(1, "rra\n", 4);
	*count = *count + 1;
}

void	ft_push_a(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
	t_movements	tm;

	tm.i = 0;
	tm.aux = bstack[0].data;
	tm.aux_index = bstack[0].index;
	while (tm.i < *blength - 1)
	{
		bstack[tm.i].data = bstack[tm.i + 1].data;
		bstack[tm.i].index = bstack[tm.i + 1].index;
		tm.i++;
	}
	bstack[tm.i].data = '\0';
	bstack[tm.i].index = '\0';
	*blength -= 1;
	tm.i = *alength;
	while (tm.i > 0)
	{
		astack[tm.i].data = astack[tm.i - 1].data;
		astack[tm.i].index = astack[tm.i - 1].index;
		tm.i--;
	}
	astack[0].data = tm.aux;
	astack[0].index = tm.aux_index;
	*alength += 1;
	write(1, "pa\n", 3);
	*count = *count + 1;
}
