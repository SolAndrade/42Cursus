#include "push_swap.h"

void    ft_less_than_ten_inputs(int *astack, int *bstack, int alength, int blength)
{
    if(alength == 2)
         ft_compare_two(astack);
    if(alength == 3)
        ft_three_inputs(astack, alength);
    if(alength == 4 || alength == 5)
        ft_five_inputs(astack, alength);
}

void ft_three_inputs(int *astack, int alength)
{
    if(astack[0] > astack[1] && astack[0] > astack[2])
    {
        ft_swap_a(astack);
        ft_rotate_reverse_a(astack, alength);
    }
    else if(astack[1] > astack[0] && astack[1] > astack[2])
    {
        ft_rotate_reverse_a(astack, alength);
        ft_compare_two(astack);
    }
    else if(astack[2] > astack[0] && astack[2] > astack[1])
        ft_compare_two(astack);
}

void ft_five_inputs(int *astack, int alength)
{
    ft_compare_two(astack);
    if(astack[alength - 3] < astack[alength - 4])
    {
        if(astack[alength - 2] < astack[alength - 3])
        {
            if(alength == 5)
            {
                ft_rotate_a(astack, alength);
                ft_compare_two(astack);
                if(astack[1] > astack[alength - 1])
                {
                    ft_rotate_a(astack, alength);
                    ft_rotate_a(astack, alength);
                    ft_compare_two(astack);
                }
            }
            else if(alength == 4)
                ft_rotate_a(astack, alength);
            ft_compare_two(astack);
        }
        else if (astack[alength - 3] < astack[alength - 4])
        {
            ft_rotate_reverse_a(astack, alength);
            ft_rotate_reverse_a(astack, alength);
            ft_compare_two(astack);
            ft_rotate_reverse_a(astack, alength);
        }
    }
}

void ft_compare_two(int *astack)
{
    if(astack[0] > astack[1])
        ft_swap_a(astack);
}

// 5 3 5 4 5 2
// 3 5 4 5 2 1
// 4 4 2 2 1 3
// 2 2 1 1 3 4
// 1 1 3 3 4 5