#include "push_swap.h"

void ft_swap_stacks(int *astack, int *bstack)
{
    int aux;

    aux = astack[0];
    astack[0] = astack[1];
    astack[1] = aux;

    aux = bstack[0];
    bstack[0] = bstack[1];
    bstack[1] = aux;

    write(1, "ss", 2);
    write(1, "\n", 1);
}

void ft_rotate_stacks(int *astack, int *bstack, int alength, int blength)
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
    i = 0;
    aux = bstack[i];
    while(i < blength - 1)
    {
        bstack[i] = bstack[i+1];
        i++;
    }
    bstack[i] = aux;
    write(1, "rr", 2);
    write(1, "\n", 1);
}

void ft_rotate_reverse_stacks(int *astack, int *bstack, int alength, int blength)
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
    blength--;
    aux = bstack[blength];
    while(blength > 0)
    {
        bstack[blength] = bstack[blength-1];
        blength--;
    }
    bstack[0] = aux;
    write(1, "rrr", 3);
    write(1, "\n", 1);
}
