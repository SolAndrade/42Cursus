/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:46:00 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 15:54:14 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker_a(t_stacks *astack, int *alength)
{
	int	i;
	int	min;

	i = *alength - 1;
	min = astack[i].data;
	i--;
	while (i >= 0)
	{
		if (astack[i].data > min)
			return (0);
		else
			min = astack[i].data;
		i--;
	}
	return (1);
}

int	ft_get_max(t_stacks *stack, int *length)
{
	int	i;
	int	max;

	i = 1;
	max = stack[0].data;
	while (i < *length)
	{
		if (stack[i].data > max)
			max = stack[i].data;
		i++;
	}
	return (max);
}

int	ft_get_max_index(t_stacks *stack, int *length)
{
	int	i;
	int	index;
	int	max;

	i = 1;
	max = stack[0].data;
	index = 0;
	while (i < *length)
	{
		if (stack[i].data > max)
		{
			max = stack[i].data;
			index = i;
		}
		i++;
	}
	return (index);
}

void	ft_order_final_a(t_stacks *astack, int *alength)
{
	int	minpos;
	int	i;

	minpos = 0;
	i = 0;
	while (i < *alength)
	{
		if (astack[i].data < astack[minpos].data)
			minpos = i;
		i++;
	}
	if (minpos > *alength / 2)
	{
		while (ft_checker_a(astack, alength) == 0)
			ft_rotate_reverse_a(astack, *alength);
	}
	else
	{
		while (ft_checker_a(astack, alength) == 0)
			ft_rotate_a(astack, *alength);
	}
}

int	ft_is_there_a_minor(t_stacks *stack, int *length, int media)
{
	int	i;

	i = 0;
	while (i < *length)
	{
		if (stack[i].index <= media)
			return (i);
		i++;
	}
	return (-1);
}
