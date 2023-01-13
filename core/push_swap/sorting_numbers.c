/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:58:36 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:02:58 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_number(t_stacks *astack, t_stacks *bstack, int *al, int *bl)
{
	ft_bubble_sort(astack, al);
	if (ft_checker_a(astack, al) == 0)
	{
		ft_send_all_to_b(astack, bstack, al, bl);
		while (*bl > 0)
		{
			ft_target_pos(astack, bstack, al, bl);
			ft_calculate_moves(bstack, al, bl);
			ft_accom_number(astack, bstack, al, bl);
			ft_push_a(astack, bstack, al, bl);
		}
		ft_order_final_a(astack, al);
	}
}

void	ft_assign_final_pos(t_stacks *astack, t_stacks *astack_aux, int *al)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < *al)
	{
		if (astack_aux[j].data == astack[i].data)
		{
			astack[i].index = j;
			j++;
			i = 0;
		}
		else
			i++;
	}
	ft_empty_struct(astack_aux, astack_aux, *al);
	free(astack_aux);
}

void	ft_send_all_to_b(t_stacks *astack, t_stacks *bstack, int *al, int *bl)
{
	int	media;
	int	main_media;
	int	total_numbers;

	total_numbers = *al;
	main_media = total_numbers / 2;
	media = main_media;
	while (*al > 3)
	{
		while (ft_is_there_a_minor(astack, al, media) != -1 && *al > 3)
		{
			if (astack[0].index <= media)
				ft_push_b(astack, bstack, al, bl);
			else
				ft_rotate_a(astack, *al);
		}
		media += main_media;
	}
	ft_three_inputs_a(astack, *al);
}

void	ft_target_pos(t_stacks *astack, t_stacks *bstack, int *al, int *bl)
{
	int	ib;
	int	ia;
	int	most_near;

	ib = 0;
	while (ib < *bl)
	{
		most_near = (ft_get_max(astack, al) + 1) - bstack[ib].data;
		ia = 0;
		while (ia < *al)
		{
			if (astack[ia].data > bstack[ib].data)
			{
				if (abs(astack[ia].data - bstack[ib].data) < most_near)
				{
					most_near = abs(astack[ia].data - bstack[ib].data);
					bstack[ib].target_pos = ia;
				}
			}
			ia++;
		}
		if (most_near == (ft_get_max(astack, al) + 1) - bstack[ib].data)
			bstack[ib].target_pos = ft_get_max_index(astack, al) + 1;
		ib++;
	}
}

void	ft_calculate_moves(t_stacks *bstack, int *alength, int *blength)
{
	int	i;

	i = 0;
	while (i < *blength)
	{
		if (bstack[i].target_pos <= *alength / 2)
			bstack[i].moves_a = bstack[i].target_pos;
		else
			bstack[i].moves_a = (*alength - bstack[i].target_pos) * -1;
		if (i <= *blength / 2)
			bstack[i].moves_b = i;
		else if (*blength > 1)
			bstack[i].moves_b = (*blength - i) * -1;
		else
			bstack[i].moves_b = 0;
		bstack[i].moves = abs(bstack[i].moves_a) + abs(bstack[i].moves_b);
		i++;
	}
}
