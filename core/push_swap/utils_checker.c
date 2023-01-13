/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:05:05 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:24:27 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

int	ft_read_movement(t_stacks *astack, t_stacks *bstack, int *al, int *bl)
{
	char	*line;

	line = get_next_line(1);
	if (!line)
		return (1);
	if (ft_read_movement_a(astack, al, line) == 1)
	{
		if (ft_read_movement_b(bstack, bl, line) == 1)
		{
			if (ft_strcmp(line, "ss") == 0)
				ft_swap_stacks(astack, bstack);
			else if (ft_strcmp(line, "pa") == 0)
				ft_push_a(astack, bstack, al, bl);
			else if (ft_strcmp(line, "rrr") == 0)
				ft_rotate_re_stacks(astack, bstack, *al, *bl);
			else if (ft_strcmp(line, "rr") == 0)
				ft_rotate_stacks(astack, bstack, *al, *bl);
			else
				return (1);
		}
	}
	return (0);
}

int	ft_read_movement_a(t_stacks *astack, int *alength, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_swap_a(astack);
	else if (ft_strcmp(line, "ra") == 0)
		ft_rotate_a(astack, *alength);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rotate_reverse_a(astack, *alength);
	else
		return (1);
	return (0);
}

int	ft_read_movement_b(t_stacks *bstack, int *blength, char *line)
{
	if (ft_strcmp(line, "sb") == 0)
		ft_swap_a(bstack);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rotate_a(bstack, *blength);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rotate_reverse_a(bstack, *blength);
	else
		return (1);
	return (0);
}
