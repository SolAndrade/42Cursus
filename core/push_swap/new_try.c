#include "push_swap.h"

//falta gestionar la ida de la mitad de los numeros cuando hay 500 inputs

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

int ft_is_minor_a(int *bstack, int *blength, int media, int starting)
{
    int i = 0;
    int from_up = -1;
    int from_down = -1;

    while(i < *blength && from_up == -1)
    {
        if(bstack[i] <= media && bstack[i] > starting)
            from_up = i;
        i++;
    }
    i = *blength;
    i--;
    if(from_up == -1)
        return(-1);
    while(i > 0 && from_down == -1)
    {
        if(bstack[i] <= media && bstack[i] > starting)
            from_down = i;
        i--;
    }
    if(*blength - from_down < from_up)
        return(from_down);
    else
        return(from_up);
    return(-1);
}

void ft_order_by_stacks_a(int *astack, int *bstack, int *alength, int *blength, int *count)
{
    int main_media;
    int media;
    int min_b;
    int max_b;
    int i = 0;
    int minorpos;
    int pos_a;
    int pos_b;
    int starting;

    ft_print_stacks(astack, bstack, *alength, *blength);
    max_b = ft_get_max(bstack, blength);
    printf("max_b: %i\n", max_b);
    min_b = ft_get_min(bstack, blength);
    printf("min_b: %i\n", min_b);
    main_media = ft_get_media(bstack, blength);
    printf("main_media: %i\n", main_media);
    starting = min_b + (main_media * 2);
    printf("starting: %i\n", starting);
    // media = starting + main_media; ----
    media = max_b;
    // printf("media: %i\n", media);
    // while(media <= max_b) ----
    while(media >= starting)
    {
        // printf("media: %i\n", media);
        printf("is_minor_a: %i", ft_is_minor_a(bstack, blength, media, media - main_media));
        // while(ft_is_minor_a(bstack, blength, media, starting) > -1) ----
        while(ft_is_minor_a(bstack, blength, media, media - main_media) > -1)
        {
            // pos_b = ft_is_minor_a(bstack, blength, media, starting); ----
            pos_b = ft_is_minor_a(bstack, blength, media, media - main_media);
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
            // if(bstack[0] <= media) ----
            if(bstack[0] <= media)
            {
                if(*alength < 3)
                    ft_push_a(astack, bstack, alength, blength, count);
                else
                {
                    if(bstack[0] < astack[0] && bstack[0] > astack[*alength - 1])
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
        ft_order_final(astack, bstack, alength, blength, count);
        ft_print_stacks(astack, bstack, *alength, *blength);
        // media = media + main_media; ----
        media = media - main_media;
    }
    ft_print_stacks(astack, bstack, *alength, *blength);
    ft_order_final(astack, bstack, alength, blength, count);
    while(*blength > 0)
        ft_push_a(astack, bstack, alength, blength, count);
}