#include "push_swap.h"

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

int ft_get_max(int *stack, int *length)
{
    int i = 1;
    int max = stack[0];

    while(i < *length)
    {
        if(stack[i] > max)
            max = stack[i];
        i++;
    }
    return(max);
}

int ft_get_min(int *stack, int *length)
{
    int i = 1;
    int min = stack[0];

    while(i < *length)
    {
        if(stack[i] < min)
            min = stack[i];
        i++;
    }
    return(min);
}

int ft_get_media(int *stack, int *length)
{
    int media;
    int i = 1;
    int min = stack[0];
    int max = stack[0];

    while(i < *length)
    {
        if(stack[i] < min)
            min = stack[i];
        i++;
    }
    i = 1;
    while(i < *length)
    {
        if(stack[i] > max)
            max = stack[i];
        i++;
    }
    if(*length <= 100)
        media = (max - min) / 4;
    else if(*length <= 300)
        media = (max - min) / 6;
    else
        media = (max - min) / 11;
    return(media);
}