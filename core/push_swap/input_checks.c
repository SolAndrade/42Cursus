/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:28:06 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:48:06 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int i)
{
	write(2, "Error\n", 6);
	return (i);
}

int	ft_check_errors(char *string)
{
	if (string[0] == '\0')
		return (1);
	return (0);
}

int	ft_check_int(char *string)
{
	int	i;

	i = 0;
	if (string[i] == 43 || string[i] == 45 || string[i] == 32)
		i++;
	if (string[i] == '\0')
		return (1);
	while (string[i] != '\0')
	{
		if (!(string[i] >= 48 && string[i] <= 57) && string[i] != 32)
			return (1);
		i++;
	}
	return (0);
}

void	ft_empty_struct(t_stacks *astack, t_stacks *bstack, int alength)
{
	int	i;

	i = 0;
	while (i < alength)
	{
		astack[i].data = 0;
		astack[i].index = 0;
		astack[i].target_pos = 0;
		astack[i].moves = 0;
		astack[i].moves_a = 0;
		astack[i].moves_b = 0;
		bstack[i].data = 0;
		bstack[i].index = 0;
		bstack[i].target_pos = 0;
		bstack[i].moves = 0;
		bstack[i].moves_a = 0;
		bstack[i].moves_b = 0;
		i++;
	}
}

int	ft_count_numbers_string(char *s)
{
	int	numbers;
	int	i;

	i = 0;
	numbers = 0;
	while (s[i] && s[i] == 32)
		i++;
	while (s[i])
	{
		if (s[i] == 32 && s[i + 1] != '\0' && s[i + 1] != 32)
			numbers++;
		i++;
	}
	return (numbers + 1);
}
