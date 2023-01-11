/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:16:56 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/11 15:54:18 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_stacks *astack, int *alength)
{
	int			i;
	t_stacks	*astack_aux;

	i = 0;
	astack_aux = malloc(*alength * sizeof(t_stacks));
	while (i < *alength)
	{
		astack_aux[i].data = astack[i].data;
		i++;
	}
	while (ft_checker_a(astack_aux, alength) == 0)
	{
		i = 0;
		while (i < *alength - 1)
		{
			if (astack_aux[i].data > astack_aux[i + 1].data)
				ft_swap_bubble(astack_aux, i);
			i++;
		}
	}
	ft_assign_final_pos(astack, astack_aux, alength);
}

void	ft_swap_bubble(t_stacks *astack_aux, int pos)
{
	int	aux;

	aux = astack_aux[pos].data;
	astack_aux[pos].data = astack_aux[pos + 1].data;
	astack_aux[pos + 1].data = aux;
}
