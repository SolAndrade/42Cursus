#include "push_swap.h"

void ft_send_lowest_b(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    // ft_calculate_media(astack, bstack, alength, blength, count);
    ft_order_by_stacks_b(astack, bstack, alength, blength, count);
}

void ft_order_by_stacks_b(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int main_media;
    int media;
    int stack_media;
    int i = 0;
    int minorpos;

    stack_media = ft_get_min_for_media(astack, alength);
    main_media = ft_get_media(astack, alength);
    media = stack_media + main_media;
    while(media <= stack_media + (main_media * 3))
    {
        // printf("media: %i\n", media);
        while(is_minor(astack, alength, media) > -1)
        {
            // optimiza pero no tanto -------------------------------
            minorpos = is_minor(astack, alength, media);
            if(minorpos > *alength / 2)
            {
                while(minorpos++ < *alength)
                    ft_rotate_reverse_a(astack, *alength, count);
            }
            else
            {
                while(minorpos-- > 0)
                    ft_rotate_a(astack, *alength, count);
            }
            // ------------------------------------------------------
            if(astack[0] <= media)
            {
                if(*blength < 3)
                    ft_push_b(astack, bstack, alength, blength, count);
                else
                {
                    if(astack[0] > bstack[0] && astack[0] < bstack[*blength - 1])
                        ft_push_b(astack, bstack, alength, blength, count);
                    else
                        ft_position_nbr_b(astack, bstack, alength, blength, count);
                }
            }
            else
                ft_rotate_a(astack, *alength, count);
            if(*blength == 3)
                ft_three_first_not_so_order_b(bstack, *blength, count);
        }
        if(*blength > 1)
            ft_order_final_b(astack, bstack, alength, blength, count);
        // ft_print_stacks(astack, bstack, *alength, *blength);
        media = media + main_media;
    }
    ft_sort(astack, bstack, alength, blength, count);
}

int ft_get_media(int *astack, int *alength)
{
    int media;
    int i = 1;
    int min = astack[0];
    int max = astack[0];

    while(i < *alength)
    {
        if(astack[i] < min)
            min = astack[i];
        i++;
    }
    i = 1;
    while(i < *alength)
    {
        if(astack[i] > max)
            max = astack[i];
        i++;
    }
    if(min < 0)
    {
        if(max < 0)
            media = ((min - max) / 2) + max;
        else
            media = min + max;
    }
    else
        media = (max - min) / 2;
    media = (max - min) / 4;
    return(media);
}

int ft_get_min_for_media(int *astack, int *alength)
{
    int i = 1;
    int min = astack[0];

    while(i < *alength)
    {
        if(astack[i] < min)
            min = astack[i];
        i++;
    }
    return(min);
}

void ft_three_first_not_so_order_b(int *bstack, int blength, int *count)
{
	if(bstack[0] > bstack[1] && bstack[0] > bstack[2])
	{
		if(bstack[1] < bstack[2])
        {
            ft_rotate_b(bstack, blength, count);
            ft_compare_two_b(bstack, count);
        }
	}
	else if(bstack[1] > bstack[0] && bstack[1] > bstack[2])
	{
        if(bstack[0] > bstack[2])
        {
		    ft_rotate_reverse_b(bstack, blength, count);
		    ft_compare_two_b(bstack, count);
        }
	}
	else if(bstack[2] > bstack[0] && bstack[2] > bstack[1])
        ft_compare_two_b(bstack, count);
}

int is_minor(int *astack, int *alength, int media)
{
    int i = 0;

    while(i < *alength)
    {
        if(astack[i] <= media)
            return (i);
        i++;
    }
    return(-1);
}

void ft_position_nbr_b(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int pos = -1;
    int i = 0;

    while (i < (*blength - 1) && pos == -1)
    {
        if(astack[0] < bstack[i] && astack[0] > bstack[i + 1])
            pos = i + 1;
        i++;
    }
    if(pos == -1)
    {
        i = 0;
        pos = 0;
        while(i < *blength)
        {
            if(bstack[i] < bstack[pos])
                pos = i;
            i++;
        }
        if(astack[0] < bstack[pos])
        {
            pos = 0;
            i = 0;
            while(i < *blength)
            {
                if(bstack[i] > bstack[pos])
                    pos = i;
                i++;
            }
        }
        else
            pos++;
    }
    if(pos > *blength / 2)
    {
        while(pos++ < *blength)
            ft_rotate_reverse_b(bstack, *blength, count);
    }
    else
    {
        while(pos-- > 0)
            ft_rotate_b(bstack, *blength, count);
    }
    ft_push_b(astack, bstack, alength, blength, count);
}

void    ft_order_final_b(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int maxpos = 0;
    int i = 0;
    while(i < *blength)
    {
        if(bstack[i] > bstack[maxpos])
            maxpos = i;
        i++;
    }
    if(maxpos > *blength / 2)
    {
        while(ft_checker_b(bstack, blength) == 0)
            ft_rotate_reverse_b(bstack, *blength, count);
    }
    else
    {
        while(ft_checker_b(bstack, blength) == 0)
            ft_rotate_b(bstack, *blength, count);
    }
}

int ft_checker_b(int *bstack, int *blength)
{
	int i = *blength - 1;
	int max = bstack[i];
	i--;
	while(i >= 0)
	{
		if(bstack[i] < max)
			return(0);
		else
			max = bstack[i];
		i--;
	}
	return(1);
}