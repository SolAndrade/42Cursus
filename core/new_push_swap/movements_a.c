#include "push_swap.h"

void ft_swap_a(t_stacks *astack, int *count)
{
    int aux;
    int aux_index;

    aux = astack[0].data;
    aux_index = astack[0].index;
    astack[0].data = astack[1].data;
    astack[0].index = astack[1].index;
    astack[1].data = aux;
    astack[1].index = aux_index;
    write(1, "sa\n", 2);
    *count = *count + 1;
}

void ft_rotate_a(t_stacks *astack, int alength, int *count)
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
    write(1, "ra\n", 3);
    *count = *count + 1;
}

void ft_rotate_reverse_a(t_stacks *astack, int alength, int *count)
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
    write(1, "rra\n", 4);
    *count = *count + 1;
}

void ft_push_a(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
    int aux;
    int aux_index;
    int i = 0;
    int a_length_aux = *alength;
    int b_length_aux = *blength;

    b_length_aux--;
    aux = bstack[0].data;
    aux_index = bstack[0].index;
    while(i < b_length_aux)
    {
        bstack[i].data = bstack[i+1].data;
        bstack[i].index = bstack[i+1].index;
        i++;
    }
    bstack[i].data = '\0';
    *blength -= 1;
    i = 0;
    while(a_length_aux > 0)
    {
        astack[a_length_aux].data = astack[a_length_aux-1].data;
        astack[a_length_aux].index = astack[a_length_aux-1].index;
        a_length_aux--;
    }
    astack[0].data = aux;
    astack[0].index = aux_index;
    *alength += 1;
    write(1, "pa\n", 3);
    *count = *count + 1;
}
