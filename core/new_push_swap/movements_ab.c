#include "push_swap.h"

void ft_swap_stacks(t_stacks *astack, t_stacks *bstack, int *count)
{
    int aux;
    int aux_index;

    aux = astack[0].data;
    aux_index = astack[0].index;
    astack[0].data = astack[1].data;
    astack[0].index = astack[1].index;
    astack[1].data = aux;
    astack[1].index = aux_index;

    aux = bstack[0].data;
    aux_index = bstack[0].index;
    bstack[0].data = bstack[1].data;
    bstack[0].index = bstack[1].index;
    bstack[1].data = aux;
    bstack[1].index = aux_index;

    write(1, "ss", 2);
    write(1, "\n", 1);
    *count = *count + 1;
}

void ft_rotate_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength, int *count)
{
    int aux;
    int aux_index;
    int i = 0;
    
    aux = astack[i].data;
    aux_index = astack[i].index;
    while(i < alength - 1)
    {
        astack[i].data = astack[i+1].data;
        astack[i].index = astack[i+1].index;
        i++;
    }
    astack[i].data = aux;
    astack[i].index = aux_index;
    i = 0;
    aux = bstack[i].data;
    aux_index = bstack[i].index;
    while(i < blength - 1)
    {
        bstack[i].data = bstack[i+1].data;
        bstack[i].index = bstack[i+1].index;
        i++;
    }
    bstack[i].data = aux;
    bstack[i].index = aux_index;
    write(1, "rr", 2);
    write(1, "\n", 1);
    *count = *count + 1;
}

void ft_rotate_reverse_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength, int *count)
{
    int aux;
    int aux_index;

    alength--;
    aux = astack[alength].data;
    aux_index = astack[alength].index;
    while(alength > 0)
    {
        astack[alength].data = astack[alength-1].data;
        astack[alength].index = astack[alength-1].index;
        alength--;
    }
    astack[0].data = aux;
    astack[0].index = aux_index;
    blength--;
    aux = bstack[blength].data;
    aux_index = bstack[blength].index;
    while(blength > 0)
    {
        bstack[blength].data = bstack[blength-1].data;
        bstack[blength].index = bstack[blength-1].index;
        blength--;
    }
    bstack[0].data = aux;
    bstack[0].index = aux_index;
    write(1, "rrr", 3);
    write(1, "\n", 1);
    *count = *count + 1;
}
