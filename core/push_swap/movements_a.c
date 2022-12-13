#include "push_swap.h"

void ft_swap_a(int *astack)
{
    int aux;

    aux = astack[0];
    astack[0] = astack[1];
    astack[1] = aux;
    write(1, "sa", 2);
    write(1, "\n", 1);
}

void ft_rotate_a(int *astack, int alength)
{
    int aux;
    int i = 0;

    aux = astack[i];
    while(i < alength - 1)
    {
        astack[i] = astack[i+1];
        i++;
    }
    astack[i] = aux;
    write(1, "ra", 2);
    write(1, "\n", 1);
}

void ft_rotate_reverse_a(int *astack, int alength)
{
    int aux;

    alength--;
    aux = astack[alength];
    while(alength > 0)
    {
        astack[alength] = astack[alength-1];
        alength--;
    }
    astack[0] = aux;
    write(1, "rra", 3);
    write(1, "\n", 1);
}

void ft_push_a(int *astack, int *bstack, int *alength, int *blength)
{
    int aux;
    int i = 0;
    int a_length_aux = *alength;
    int b_length_aux = *blength;

    b_length_aux--;
    aux = bstack[0];
    while(i < b_length_aux)
    {
        bstack[i] = bstack[i+1];
        i++;
    }
    bstack[i] = '\0';
    *blength -= 1;
    i = 0;
    while(a_length_aux > 0)
    {
        astack[a_length_aux] = astack[a_length_aux-1];
        a_length_aux--;
    }
    astack[0] = aux;
    *alength += 1;
    write(1, "pa", 2);
    write(1, "\n", 1);
}
