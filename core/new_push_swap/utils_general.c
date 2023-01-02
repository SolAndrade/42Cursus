#include "push_swap.h"

int ft_checker_a(t_stacks *astack, int *alength)
{
	int i = *alength - 1;
	int min = astack[i].data;
	i--;
	while(i >= 0)
	{
		if(astack[i].data > min)
			return(0);
		else
			min = astack[i].data;
		i--;
	}
	return(1);
}

int ft_get_max(t_stacks *stack, int *length)
{
    int i = 1;
    int max = stack[0].data;

    while(i < *length)
    {
        if(stack[i].data > max)
            max = stack[i].data;
        i++;
    }
    return(max);
}

int ft_get_max_index(t_stacks *stack, int *length)
{
    int i = 1;
    int index;
    int max; 
    
    max = stack[0].data;
    index = 0;
    while(i < *length)
    {
        if(stack[i].data > max)
        {
            max = stack[i].data;
            index = i;
        }
        i++;
    }
    return(index);
}

void    ft_order_final_a(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
    int minpos = 0;
    int i = 0;
    while(i < *alength)
    {
        if(astack[i].data < astack[minpos].data)
            minpos = i;
        i++;
    }
    if(minpos > *alength / 2)
    {
        while(ft_checker_a(astack, alength) == 0)
            ft_rotate_reverse_a(astack, *alength, count);
    }
    else
    {
        while(ft_checker_a(astack, alength) == 0)
            ft_rotate_a(astack, *alength, count);
    }
}

int ft_is_there_a_minor(t_stacks *stack, int *length, int media)
{
    int i = 0;

    while(i < *length)
    {
        if(stack[i].index <= media)
            return(i);
        i++;
    }
    return(-1);
}