#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//-------- Movements --------

// -- Stack A --
void    ft_swap_a(int *astack);
void    ft_push_a(int *astack, int  *bstack, int *alength, int *blength);
void    ft_rotate_a(int *astack, int alength);
void    ft_rotate_reverse_a(int *astack, int alength);

// -- Stack B --
void    ft_swap_b(int *bstack);
void    ft_rotate_b(int *bstack, int blength);
void    ft_rotate_reverse_b(int *bstack, int blength);
void    ft_push_b(int *astack, int *bstack, int *alength, int *blength);

// -- Stack A && Stack B --
void    ft_swap_stacks(int *astack, int *bstack);
void    ft_rotate_stacks(int *astack, int *bstack, int alength, int blength);
void    ft_rotate_reverse_stacks(int *astack, int *bstack, int alength, int blength);

//-------- Less Than 10 Inputs --------
void    ft_less_than_ten_inputs(int *astack, int *bstack, int *alength, int *blength);
void    ft_three_inputs(int *astack, int alength);
void    ft_compare_two(int *astack);
void    ft_five_inputs(int *astack, int *bstack, int *alength, int *blength);

//Utils
int     ft_atoi(const char *str);

//For Tests
void ft_print_stacks(int *astack, int *bstack, int alength, int blength);


#endif