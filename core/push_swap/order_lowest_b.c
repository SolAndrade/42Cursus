#include "push_swap.h"

void ft_send_lowest_b(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    ft_order_by_stacks_b(astack, bstack, alength, blength, count);
}

void ft_order_by_stacks_b(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int main_media;
    int media;
    int min_a;
    int i = 0;
    int minorpos;
    int pos_a;
    int pos_b;
    int max_a;

    max_a = ft_get_max(astack, alength);
    min_a = ft_get_min(astack, alength);
    main_media = ft_get_media(astack, alength);
    media = min_a + main_media;
    while(media <= (min_a + (main_media * 2)))
    {
        // printf("media: %i\n", media);
        while(is_minor(astack, alength, media) > -1)
        {
            // printf("is_minor_b: %i", is_minor(astack, alength, media));
            pos_a = is_minor(astack, alength, media);
            // printf("is_minor_b %i", pos_a);
            pos_b = get_pos_nbr_b(astack, bstack, blength);
            if(pos_a > 0 && pos_b > 0)
            {
                if(pos_a > *alength / 2 && pos_b > *blength / 2)
                {
                    while(pos_a++ < *alength && pos_b++ < *blength)
                        ft_rotate_reverse_stacks(astack, bstack, *alength, *blength, count);
                }
                else if(pos_a <= *alength / 2 && pos_b <= *blength / 2)
                {
                    while(pos_a-- > 0 && pos_b-- > 0)
                        ft_rotate_stacks(astack, bstack, *alength, *blength, count);
                }
            }
            else
            {
                if(pos_a > *alength / 2)
                {
                    while(pos_a++ < *alength)
                        ft_rotate_reverse_a(astack, *alength, count);
                }
                else
                {
                    while(pos_a-- > 0)
                        ft_rotate_a(astack, *alength, count);
                }
            }
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
    int from_up = -1;
    int from_down = -1;

    while(i < *alength && from_up == -1)
    {
        if(astack[i] <= media)
            from_up = i;
        i++;
    }
    // printf("from_up: %i", from_up);
    i = *alength;
    i--;
    // printf("alength: %i\n", *alength);
    if(from_up == -1)
        return(-1);
    while(i > 0 && from_down == -1)
    {
        if(astack[i] <= media)
            from_down = i;
        i--;
    }
    // printf("from_down: %i", from_down);
    if(*alength - from_down < from_up)
        return(from_down);
    else
        return(from_up);
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