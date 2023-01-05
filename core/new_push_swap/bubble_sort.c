#include "push_swap.h"

void ft_bubble_sort(t_stacks *astack, int *alength)
{
    int pos_to_swap;
    int i = 0;
    t_stacks astack_aux[*alength];

    while(i < *alength)
    {
        astack_aux[i].data = astack[i].data;
        i++;
    }
    while(ft_checker_a(astack_aux, alength) == 0)
    {
        i = 0;
        while(i < *alength - 1)
        {
            if(astack_aux[i].data > astack_aux[i + 1].data)
                ft_swap_bubble(astack_aux, i);
            i++;
        }
    }
    ft_assign_final_pos(astack, astack_aux, alength);
}

void ft_swap_bubble(t_stacks *astack_aux, int pos)
{
    int aux;

    aux = astack_aux[pos].data;
    astack_aux[pos].data = astack_aux[pos + 1].data;
    astack_aux[pos + 1].data = aux;
}