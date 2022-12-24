#include "push_swap.h"

void ft_sort(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    ft_three_first(astack, bstack, alength, blength, count);
    ft_print_stacks(astack, bstack, *alength, *blength);
    while(*blength > 0)
    {
        ft_position_nbr(astack, bstack, alength, blength, count);
    }
    ft_order_final(astack, bstack, alength, blength, count);
}

void    ft_order_final(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int minpos = 0;
    int i = 0;
    while(i < *alength)
    {
        if(astack[i] < astack[minpos])
            minpos = i;
        i++;
    }
    if(minpos > *alength / 2)
    {
        while(ft_checker(astack, alength) == 0)
            ft_rotate_reverse_a(astack, *alength, count);
    }
    else
    {
        while(ft_checker(astack, alength) == 0)
            ft_rotate_a(astack, *alength, count);
    }
}

void ft_three_first(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    while (*alength > 3)
        ft_push_b(astack, bstack, alength, blength, count);
    ft_three_inputs_a(astack, *alength, count);
}

void ft_first_or_last(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int flag = 0;
    while(flag == 0)
    {
        if(bstack[0] < astack[0])
            ft_push_a(astack, bstack, alength, blength, count);
        else if(bstack[0] > astack[*alength - 1])
        {
            ft_push_a(astack, bstack, alength, blength, count);
            ft_rotate_a(astack, *alength, count);
        }
        else
            flag = 1;
    }
}

void ft_position_nbr(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int pos = -1;
    int i = 0;
    ft_print_stacks(astack, bstack, *alength, *blength);
    if(bstack[0] < astack[0] && bstack[0] > astack[*alength - 1])
        ft_push_a(astack, bstack, alength, blength, count);
    while (i < *alength && pos == -1)
    {
        if(bstack[0] > astack[i] && bstack[0] < astack[i + 1])
            pos = i + 1;
        i++;
    }
    if(pos == -1)
    {
        i = 0;
        pos = 0;
        while(i < *alength)
        {
            if(astack[i] > astack[pos])
                pos = i;
            i++;
        }
        pos++;
    }
    if(pos > *alength / 2)
    {
        while(pos < *alength)
        {
            ft_rotate_reverse_a(astack, *alength, count);
            pos++;
        }
        ft_push_a(astack, bstack, alength, blength, count);
    }
    else
    {
        while(pos > 0)
        {
            ft_rotate_a(astack, *alength, count);
            pos--;
        }
        ft_push_a(astack, bstack, alength, blength, count);
    }
}

int ft_checker(int *astack, int *alength)
{
	int i = *alength;
	i--;
	int min = astack[i];
	i--;
	while(i > 0)
	{
		if(astack[i] > min)
			return(0);
		else
			min = astack[i];
		i--;
	}
	return(1);
}