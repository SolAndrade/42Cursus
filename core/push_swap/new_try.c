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

