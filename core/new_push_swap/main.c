#include "push_swap.h"

int main(int argc, char **argv)
{
    int arg = 1;
    int iarr = 0;
    t_stacks astack[argc - 1];
    t_stacks bstack[argc - 1];
    int nbr;
    int alength = argc-1;
    int blength = 0;
    int count;

    count = 0;
    ft_empty_struct(astack, bstack, alength);
    if(argc > 1)
    {
        while(arg < argc)
        {
            nbr = ft_atoi(argv[arg++]);
            astack[iarr++].data = nbr;
        }
        if (argc <= 3)
            ft_three_or_less_inputs(astack, bstack, &alength, &blength, &count);
        else
            ft_sorting_numbers(astack, bstack, &alength, &blength, &count);
    }
    // ft_print_stacks(astack, bstack, alength, blength);
    // printf("count: %i", count);
}

void ft_empty_struct(t_stacks *astack, t_stacks *bstack, int alength)
{
    int i = 0;

    while(i < alength)
    {
        astack[i].data = 0;
        astack[i].index = 0;
        astack[i].target_pos = 0;
        astack[i].moves = 0;
        astack[i].moves_a = 0;
        astack[i].moves_b = 0;
        bstack[i].data = 0;
        bstack[i].index = 0;
        bstack[i].target_pos = 0;
        bstack[i].moves = 0;
        bstack[i].moves_a = 0;
        bstack[i].moves_b = 0;
        i++;
    }
}

void ft_print_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength)
{
    int i = 0;

    printf("astack\n");
    while(i < alength)
    {
        printf("%d\n", astack[i].data);
        i++;
    }
    i = 0;
    printf("bstack\n");
    while(i < blength)
    {
        printf("%d\n", bstack[i].data);
        i++;
    }
}

void ft_print_stacks_all_data(t_stacks *astack, t_stacks *bstack, int alength, int blength)
{
    int i = 0;

    printf("astack\n");
    while(i < alength)
    {
        printf("Pos: %d   Data: %d    Index: %d\n", i, astack[i].data, astack[i].index);
        i++;
    }
    i = 0;
    printf("bstack\n");
    while(i < blength)
    {
        printf("Pos: %d   Data: %d    Index: %d     Target_pos: %d      Moves: %d       Moves_a: %d     Moves_b: %d\n", i, bstack[i].data, bstack[i].index, bstack[i].target_pos, bstack[i].moves, bstack[i].moves_a, bstack[i].moves_b);
        i++;
    }
}

