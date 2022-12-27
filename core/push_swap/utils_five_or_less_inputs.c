#include "push_swap.h"

void ft_get_and_position_max_five_inputs(int *astack, int *alength, int *count)
{
	int i;
	int max;
	
	i = 1;
	max = astack[0];
	while(i < *alength)
	{
		if(astack[i] > max)
			max = astack[i];
		i++;
	}
	i = 0;
	while(astack[i] != max)
		i++;
	max = 0;
	if(i < ((*alength / 2) + 1))
	{
		while(max++ < i)
			ft_rotate_a(astack, *alength, count);
	}
	else
	{
		while(i++ < *alength)
			ft_rotate_reverse_a(astack, *alength, count);
	}
}

void ft_get_and_position_min_five_inputs(int *astack, int *alength, int *count)
{
	int i;
	int min;
	
	i = 1;
	min = astack[0];
	while(i < *alength)
	{
		if(astack[i] < min)
			min = astack[i];
		i++;
	}
	i = 0;
	while(astack[i] != min)
		i++;
	min = 0;
	if(i < ((*alength / 2) + 1))
	{
		while(min++ < i)
			ft_rotate_a(astack, *alength, count);
	}
	else
	{
		while(i++ < *alength)
			ft_rotate_reverse_a(astack, *alength, count);
	}
}
