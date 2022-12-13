#include "push_swap.h"

void    ft_less_than_ten_inputs(int *astack, int *bstack, int *alength, int *blength)
{
    // int a_length_aux = *alength;
    // int b_length_aux = *blength;

    if(*alength == 2)
         ft_compare_two(astack);
    if(*alength == 3)
        ft_three_inputs(astack, *alength);
    if(*alength == 4 || *alength == 5)
        ft_five_inputs(astack, bstack, alength, blength);
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

void ft_five_inputs(int *astack, int *bstack, int *alength, int *blength)
{
    int flag = 1;
    int a_length_aux = *alength;
    int b_length_aux = *blength;

    ft_compare_two(astack);
    while(flag == 1)
    {
        if(astack[1] > astack[2])
        {
            if(astack[1] > astack[3])
                flag = 0;
            else
            {
                ft_rotate_a(astack, *alength);
                ft_compare_two(astack);
            }
        }
        else
            flag = 0;
    }
    if(astack[2] > astack[3])
    {
        if(*alength == 5)
        {
            ft_rotate_reverse_a(astack, *alength);
            ft_rotate_reverse_a(astack, *alength);
        }
        else
            ft_rotate_reverse_a(astack, *alength);
    }
}

void ft_compare_two(int *astack)
{
    if(astack[0] > astack[1])
        ft_swap_a(astack);
}

// 4 --> 8 6 
// 8 --> 6 8 
// 6 --> 7 7 
// 7 --> 2 2 
// 2 --> 4 4 

