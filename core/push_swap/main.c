#include "push_swap.h"

int main(int argc, char **argv)
{
    int arg = 1;
    int iarr = 0;
    int astack[argc - 1];
    int bstack[argc - 1];
    int nbr;
    int i = 0;
    int alength = argc-1;
    int blength = 0;

    if(argc > 1)
    {
        while(arg < argc)
        {
            nbr = ft_atoi(argv[arg++]);
            astack[iarr++] = nbr;
        }
    }
    if (argc <= 6)
        ft_less_than_ten_inputs(astack, bstack, &alength, &blength);
    // ft_push_b(astack, bstack, &alength, &blength);
    // ft_print_stacks(astack, bstack, alength, blength);
    // ft_push_a(astack, bstack, &alength, &blength);
    ft_print_stacks(astack, bstack, alength, blength);
}

void ft_print_stacks(int *astack, int *bstack, int alength, int blength)
{
    int i = 0;

    printf("astack\n");
    while(i < alength)
    {
        printf("%d\n", astack[i]);
        i++;
    }
    i = 0;
    printf("bstack\n");
    while(i < blength)
    {
        printf("%d\n", bstack[i]);
        i++;
    }
}
