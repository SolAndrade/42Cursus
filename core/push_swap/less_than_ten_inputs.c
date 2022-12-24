#include "push_swap.h"

void    ft_less_than_ten_inputs(int *astack, int *bstack, int *alength, int *blength, int *count)
{
	if(*alength == 2)
		 ft_compare_two_a(astack, count);
	if(*alength == 3)
		ft_three_inputs_a(astack, *alength, count);
	if(*alength == 4 || *alength == 5)
		ft_four_five_inputs(astack, bstack, alength, blength, count);
}

void ft_three_inputs_a(int *astack, int alength, int *count)
{
	if(astack[0] > astack[1] && astack[0] > astack[2])
	{
		ft_rotate_a(astack, alength, count);
		ft_compare_two_a(astack, count);
	}
	else if(astack[1] > astack[0] && astack[1] > astack[2])
	{
		ft_rotate_reverse_a(astack, alength, count);
		ft_compare_two_a(astack, count);
	}
	else if(astack[2] > astack[0] && astack[2] > astack[1])
		ft_compare_two_a(astack, count);
}

void ft_four_five_inputs(int *astack, int *bstack, int *alength, int *blength, int *count)
{
	ft_get_max(astack, alength, count);
	ft_push_b(astack, bstack, alength, blength, count);
	if(*alength == 4)
	{
		ft_get_min(astack, alength, count);
		ft_push_b(astack, bstack, alength, blength, count);
		ft_three_inputs_a(astack, *alength, count);
		ft_push_a(astack, bstack, alength, blength, count);
	}
	else if(*alength == 3)
		ft_three_inputs_a(astack, *alength, count);
	ft_push_a(astack, bstack, alength, blength, count);
	ft_rotate_a(astack, *alength, count);
}

void ft_compare_two_a(int *astack, int *count)
{
	if(astack[0] > astack[1])
		ft_swap_a(astack, count);
}