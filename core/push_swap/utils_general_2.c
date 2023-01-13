/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:05:32 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:06:11 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fill_stacks(t_stacks *astack, int argc, char **argv)
{
	int	arg;
	int	nbr;
	int	iarr;

	arg = 1;
	iarr = 0;
	if (argc == 2)
	{
		if (ft_split(argv[1], astack) == 1)
			return (1);
	}
	else
	{
		while (arg < argc)
		{
			if (ft_check_int(argv[arg]) == 1)
				return (1);
			nbr = ft_atol(argv[arg++]);
			if (nbr > 2147483647)
				return (1);
			astack[iarr++].data = nbr;
		}
	}
	return (0);
}

void	ft_free_ps(t_stacks *astack, t_stacks *bstack, int *alength)
{
	ft_empty_struct(astack, bstack, *alength);
	free(astack);
	free(bstack);
}
