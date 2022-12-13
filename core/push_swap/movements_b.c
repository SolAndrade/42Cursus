#include "push_swap.h"

void ft_swap_b(int *bstack)
{
    int aux;

    aux = bstack[0];
    bstack[0] = bstack[1];
    bstack[1] = aux;
    write(1, "sb", 2);
    write(1, "\n", 1);
}

void ft_rotate_b(int *bstack, int blength)
{
    int aux;
    int i = 0;

    aux = bstack[i];
    while(i < blength - 1)
    {
        bstack[i] = bstack[i+1];
        i++;
    }
    bstack[i] = aux;
    write(1, "rb", 2);
    write(1, "\n", 1);
}

void ft_rotate_reverse_b(int *bstack, int blength)
{
    int aux;

    blength--;
    aux = bstack[blength];
    while(blength > 0)
    {
        bstack[blength] = bstack[blength-1];
        blength--;
    }
    bstack[0] = aux;
    write(1, "rrb", 3);
    write(1, "\n", 1);
}

void ft_push_b(int *astack, int *bstack, int *alength, int *blength)
{
    int aux;
    int i = 0;
    int a_length_aux = *alength;
    int b_length_aux = *blength;

    a_length_aux--;
    aux = astack[0];
    while(i < a_length_aux)
    {
        astack[i] = astack[i+1];
        i++;
    }
    astack[i] = '\0';
    *alength -= 1;
    i = 0;
    while(b_length_aux > 0)
    {
        bstack[b_length_aux] = bstack[b_length_aux-1];
        b_length_aux--;
    }
    bstack[0] = aux;
    *blength += 1;
    write(1, "pb", 2);
    write(1, "\n", 1);
}
