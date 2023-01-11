/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:58:36 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/11 16:03:43 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_numbers(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
	ft_bubble_sort(astack, alength);
	if(ft_checker_a(astack, alength) == 0)
	{
		ft_send_all_to_b(astack, bstack, alength, blength, count);
		while (*blength > 0)
		{
			ft_assing_target_pos(astack, bstack, alength, blength);
			ft_calculate_moves(bstack, alength, blength);
			ft_accomodate_number(astack, bstack, alength, blength, count);
			ft_push_a(astack, bstack, alength, blength, count);
		}
		ft_order_final_a(astack, alength, count);
	}
}

void	ft_assign_final_pos(t_stacks *astack, t_stacks *astack_aux, int *alength)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < *alength)
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
	ft_empty_struct(astack_aux, astack_aux, *alength);
	free(astack_aux);
}

void	ft_send_all_to_b(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
	int	media;
	int	main_media;
	int	total_numbers;

	total_numbers = *alength;
	main_media = total_numbers / 2;
	media = main_media;
	while (*alength > 3)
	{
		while (ft_is_there_a_minor(astack, alength, media) != -1 && *alength > 3)
		{
			if (astack[0].index <= media)
				ft_push_b(astack, bstack, alength, blength, count);
			else
				ft_rotate_a(astack, *alength, count);
		}
		media += main_media;
	}
	ft_three_inputs_a(astack, *alength, count);
}

void	ft_assing_target_pos(t_stacks *astack, t_stacks *bstack, int *alength, int *blength)
{
	int	ib;
	int	ia;
	int	most_near;

	ib = 0;
	while (ib < *blength)
	{
		most_near = (ft_get_max(astack, alength) + 1) - bstack[ib].data;
		ia = 0;
		while (ia < *alength)
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
		if (most_near == (ft_get_max(astack, alength) + 1) - bstack[ib].data)
			bstack[ib].target_pos = ft_get_max_index(astack, alength) + 1;
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
