#include "push_swap.h"

void    ft_three_or_less_inputs(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
	if(*alength == 2)
		 ft_compare_two_a(astack, count);
	if(*alength == 3)
		ft_three_inputs_a(astack, *alength, count);
}

void ft_three_inputs_a(t_stacks *astack, int alength, int *count)
{
	if(astack[0].data > astack[1].data && astack[0].data > astack[2].data)
	{
		ft_rotate_a(astack, alength, count);
		ft_compare_two_a(astack, count);
	}
	else if(astack[1].data > astack[0].data && astack[1].data > astack[2].data)
	{
		ft_rotate_reverse_a(astack, alength, count);
		ft_compare_two_a(astack, count);
	}
	else if(astack[2].data > astack[0].data && astack[2].data > astack[1].data)
		ft_compare_two_a(astack, count);
}

void ft_compare_two_a(t_stacks *astack, int *count)
{
	if(astack[0].data > astack[1].data)
		ft_swap_a(astack, count);
}