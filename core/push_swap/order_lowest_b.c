#include "push_swap.h"

void ft_send_lowest_b(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    ft_calculate_media(astack, bstack, alength, blength, count);
}

void ft_calculate_media(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int min = astack[0];
    int max = astack[0];
    int i = 1;
    int media;
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
    media = (max - min) / 2;
    i = 0;
    while(*alength > 3)
    {
        while(is_minor(astack, alength, media) == 1)
        {
            if(astack[0] <= media)
            {   
                if(*blength < 3)
                    ft_push_b(astack, bstack, alength, blength, count);
                else
                    ft_position_nbr_b(astack, bstack, alength, blength, count);
            }
            else
                ft_rotate_a(astack, *alength, count);
            if(*blength == 3)
                ft_three_inputs_b(bstack, *blength, count);
            // if(*blength > 3)
            //     ft_position_nbr_b(astack, bstack, alength, blength, count);
        }
        ft_sort(astack, bstack, alength, blength, count);
        // ft_print_stacks(astack, bstack, *alength, *blength);
    }
    ft_print_stacks(astack, bstack, *alength, *blength);
}

int is_minor(int *astack, int *alength, int media)
{
    int i = 0;

    while(i < *alength)
    {
        if(astack[i] <= media)
            return (1);
        i++;
    }
    return(0);
}

void ft_position_nbr_b(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int pos = -1;
    int i = 0;
    // printf("begin");
    // ft_first_near(astack, bstack, alength, blength, count);
    if(astack[0] > bstack[0] && astack[0] < bstack[*blength - 1])
        ft_push_b(astack, bstack, alength, blength, count);
    // ft_print_stacks(astack, bstack, *alength, *blength);
    // ft_first_or_last(astack, bstack, alength, blength, count);
    if(*alength > 3)
    {
        while (i < *blength && pos == -1)
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
            pos++;
        }
        printf("pos: %i", pos);
        if(pos > *blength / 2)
        {
            while(pos++ < *blength)
                ft_rotate_reverse_b(bstack, *blength, count);
            ft_push_b(astack, bstack, alength, blength, count);
        }
        else
        {
            while(pos-- > 0)
                ft_rotate_b(bstack, *blength, count);
            ft_push_b(astack, bstack, alength, blength, count);
        }
    }
}