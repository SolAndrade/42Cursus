#include "push_swap.h"

void ft_swap_b(t_stacks *bstack, int *count)
{
    int aux;
    int aux_index;

    aux = bstack[0].data;
    aux_index = bstack[0].index;
    bstack[0].data = bstack[1].data;
    bstack[0].index = bstack[1].index;
    bstack[1].data = aux;
    bstack[1].index = aux_index;
    write(1, "sb", 2);
    write(1, "\n", 1);
    *count = *count + 1;
}

void ft_rotate_b(t_stacks *bstack, int blength, int *count)
{
    int aux;
    int aux_index;
    int i = 0;

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
    write(1, "rb", 2);
    write(1, "\n", 1);
    *count = *count + 1;
}

void ft_rotate_reverse_b(t_stacks *bstack, int blength, int *count)
{
    int aux;
    int aux_index;

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
    write(1, "rrb", 3);
    write(1, "\n", 1);
    *count = *count + 1;
}

void ft_push_b(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count)
{
    int aux;
    int aux_index;
    int i = 0;
    int a_length_aux = *alength;
    int b_length_aux = *blength;

    a_length_aux--;
    aux = astack[0].data;
    aux_index = astack[0].index;
    while(i < a_length_aux)
    {
        astack[i].data = astack[i+1].data;
        astack[i].index = astack[i+1].index;
        i++;
    }
    astack[i].data = '\0';
    astack[i].index = '\0';
    *alength -= 1;
    i = 0;
    while(b_length_aux > 0)
    {
        bstack[b_length_aux].data = bstack[b_length_aux-1].data;
        bstack[b_length_aux].index = bstack[b_length_aux-1].index;
        b_length_aux--;
    }
    bstack[0].data = aux;
    bstack[0].index = aux_index;
    *blength += 1;
    write(1, "pb", 2);
    write(1, "\n", 1);
    *count = *count + 1;
}
