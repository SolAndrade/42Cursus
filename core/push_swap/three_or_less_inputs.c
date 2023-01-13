/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_or_less_inputs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:03:34 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/11 18:04:39 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_or_less_inputs(t_stacks *astack, int *alength)
{
	if (*alength == 2)
		ft_compare_two_a(astack);
	if (*alength == 3)
		ft_three_inputs_a(astack, *alength);
}

void	ft_three_inputs_a(t_stacks *astack, int alength)
{
	if (astack[0].data > astack[1].data && astack[0].data > astack[2].data)
	{
		ft_rotate_a(astack, alength);
		ft_compare_two_a(astack);
	}
	else if (astack[1].data > astack[0].data && astack[1].data > astack[2].data)
	{
		ft_rotate_reverse_a(astack, alength);
		ft_compare_two_a(astack);
	}
	else if (astack[2].data > astack[0].data && astack[2].data > astack[1].data)
		ft_compare_two_a(astack);
}

void	ft_compare_two_a(t_stacks *astack)
{
	if (astack[0].data > astack[1].data)
		ft_swap_a(astack);
}
