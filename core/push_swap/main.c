/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:56:00 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:53:06 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_main		tm;
	t_stacks	*astack;
	t_stacks	*bstack;

	tm.bl = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			if (ft_check_errors(argv[1]) == 1)
				return (ft_error(1));
			tm.al = ft_count_numbers_string(argv[1]);
		}
		else
			tm.al = argc - 1;
		astack = malloc((tm.al) * sizeof(t_stacks));
		bstack = malloc((tm.al) * sizeof(t_stacks));
		ft_empty_struct(astack, bstack, tm.al);
		if (ft_fill_stacks(astack, argc, argv) == 1)
			return (ft_free_ps(astack, bstack, &tm.al), ft_error(1));
		if (ft_checks(astack, bstack, &tm.al, &tm.bl) == 1)
			return (ft_error(1));
	}
	return (0);
}

int	ft_checks(t_stacks *astack, t_stacks *bstack, int *al, int *bl)
{
	if (ft_check_doubles(astack, al) == 1)
	{
		ft_free_ps(astack, bstack, al);
		return (1);
	}
	if (ft_checker_a(astack, al) == 0)
	{
		if (*al <= 3)
			ft_three_or_less_inputs(astack, al);
		else
			ft_sorting_number(astack, bstack, al, bl);
	}
	ft_free_ps(astack, bstack, al);
	return (0);
}
