/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:57:56 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 18:01:08 by soandrad         ###   ########.fr       */
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
		ft_checker(astack, bstack, &tm.al, &tm.bl);
		ft_free_ps(astack, bstack, &tm.al);
	}
	return (0);
}

void	ft_checker(t_stacks *astack, t_stacks *bstack, int *al, int *bl)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	if (ft_checker_a(astack, al) == 0)
	{	
		while (flag == 0)
		{
			if (ft_read_movement(astack, bstack, al, bl) == 1)
				flag = 1;
		}
		flag = 0;
		while (i < *bl && flag == 0)
		{
			if (bstack[i].data != '\0')
				flag = 1;
			i++;
		}
		ft_checker_response(astack, al, flag);
	}
	else
		write(1, "OK\n", 3);
}

int	ft_checker_response(t_stacks *astack, int *alength, int flag)
{
	if (ft_checker_a(astack, alength) == 1 && flag == 0)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	else
	{
		write(1, "KO\n", 3);
		return (1);
	}
	return (0);
}
