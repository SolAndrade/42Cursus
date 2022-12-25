#include "push_swap.h"

void ft_get_max(int *astack, int *alength, int *count)
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

void ft_get_min(int *astack, int *alength, int *count)
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

void ft_three_inputs_b(int *bstack, int blength, int *count)
{
	if(bstack[0] > bstack[1] && bstack[0] > bstack[2])
	{
		if(bstack[1] < bstack[2])
        {
            ft_rotate_b(bstack, blength, count);
            ft_compare_two_b(bstack, count);
        }
        ft_rotate_reverse_b(bstack, blength, count);
	}
	else if(bstack[1] > bstack[0] && bstack[1] > bstack[2])
	{
        if(bstack[0] > bstack[2])
        {
		    ft_rotate_reverse_b(bstack, blength, count);
		    ft_compare_two_b(bstack, count);
            ft_rotate_reverse_b(bstack, blength, count);
        }
        else
            ft_rotate_b(bstack, blength, count);
	}
	else if(bstack[2] > bstack[0] && bstack[2] > bstack[1])
	{
        ft_compare_two_b(bstack, count);
        ft_rotate_reverse_b(bstack, blength, count);
    }
}

void ft_compare_two_b(int *bstack, int *count)
{
    if(bstack[0] < bstack[1])
        ft_swap_b(bstack, count);
}

void ft_first_near(int *stack_one, int *stack_two, int *count)
{
    if(stack_one[0] > stack_two[0])
    {
        if(stack_one[0] > stack_two[1])
        {
            if(stack_one[0] - stack_two[1] < stack_one[0] - stack_two[0])
                ft_swap_b(stack_two, count);
        }
        else
        {
            if(stack_two[1] - stack_one[0] < stack_one[0] - stack_two[0])
                ft_swap_b(stack_two, count);
        }
    }
    else
    {
        if(stack_one[0] > stack_two[1])
        {
            if(stack_one[0] - stack_two[1] < stack_two[0] - stack_one[0])
                ft_swap_b(stack_two, count);
        }
        else
        {
            if(stack_two[1] - stack_one[0] < stack_two[0] - stack_one[0])
                ft_swap_b(stack_two, count);
        }
    }
}