#include "push_swap.h"

int get_pos_nbr_b(int *astack, int *bstack, int *blength)
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
    return(pos);
}

int get_pos_nbr_a(int *astack, int *bstack, int *alength, int *blength)
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
    return(pos);
}

void ft_order_by_stacks_a(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int main_media;
    int media;
    int min_b;
    int i = 0;
    int minorpos;
    int loop;
    int pos_a;
    int pos_b;

    // ft_print_stacks(astack, bstack, *alength, *blength);
    min_b = ft_get_min_for_media(bstack, blength);
    printf("min_b: %i\n", min_b);
    main_media = ft_get_media(bstack, blength);
    printf("main_media: %i\n", main_media);
    media = min_b + (main_media * 3);
    printf("media: %i\n", media);
    if(*alength <= 100)
        loop = min_b + (main_media * 4);
    else if(*alength <= 300)
        loop = min_b + (main_media * 5);
    else
        loop = min_b + (main_media * 10);
    printf("loop %i\n", loop);
    while(*blength > 0)
    {
        // printf("media: %i\n", media);
        while(is_minor(bstack, blength, media) > -1)
        {
            pos_b = is_minor(bstack, blength, media);
            pos_a = get_pos_nbr_a(astack, bstack, alength, blength);
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
                if(pos_b > *blength / 2)
                {
                    while(pos_b++ < *blength)
                        ft_rotate_reverse_b(bstack, *blength, count);
                }
                else
                {
                    while(pos_b-- > 0)
                        ft_rotate_b(bstack, *blength, count);
                }
            }
            if(bstack[0] <= media)
            {
                if(*alength < 3)
                    ft_push_a(astack, bstack, alength, blength, count);
                else
                {
                    if(bstack[0] > astack[0] && bstack[0] < astack[*alength - 1])
                        ft_push_a(astack, bstack, alength, blength, count);
                    else
                        ft_position_nbr(astack, bstack, alength, blength, count);
                }
            }
            else
                ft_rotate_b(bstack, *blength, count);
            if(*alength == 3)
                ft_three_inputs_a(astack, *alength, count);
        }
        ft_print_stacks(astack, bstack, *alength, *blength);
        media = media + main_media;
    }
    while(*blength > 0)
        ft_position_nbr(astack, bstack, alength, blength, count);
}