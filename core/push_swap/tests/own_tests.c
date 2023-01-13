/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   own_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:06:33 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:07:35 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stacks
{
	int				data;
	int				index;
	int				target_pos;
	int				moves;
	int				moves_a;
	int				moves_b;
}	t_stacks;

void	ft_print_stacks(t_stacks *astack, t_stacks *bstack, int al, int bl)
{
	int	i;

	i = 0;
	printf("astack\n");
	while (i < al)
	{
		printf("%d\n", astack[i].data);
		i++;
	}
	i = 0;
	printf("bstack\n");
	while (i < bl)
	{
		printf("%d\n", bstack[i].data);
		i++;
	}
}

void	ft_print_all_data(t_stacks *astack, t_stacks *bstack, int al, int bl)
{
	int	i;

	i = 0;
	printf("astack\n");
	while (i < al)
	{
		printf("Pos: %d		Data: %d	Index: %d\n", i, astack[i].data, astack[i].index);
		i++;
	}
	i = 0;
	printf("bstack\n");
	while (i < bl)
	{
		printf("Pos: %d   Data: %d    Index: %d     Target_pos: %d      Moves: %d       Moves_a: %d     Moves_b: %d\n", i, bstack[i].data, bstack[i].index, bstack[i].target_pos, bstack[i].moves, bstack[i].moves_a, bstack[i].moves_b);
		i++;
	}
}
