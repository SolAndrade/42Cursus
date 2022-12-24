#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//-------- Movements --------

// -- Stack A --
void    ft_swap_a(int *astack, int *count);
void    ft_push_a(int *astack, int  *bstack, int *alength, int *blength, int *count);
void    ft_rotate_a(int *astack, int alength, int *count);
void    ft_rotate_reverse_a(int *astack, int alength, int *count);

// -- Stack B --
void    ft_swap_b(int *bstack, int *count);
void    ft_rotate_b(int *bstack, int blength, int *count);
void    ft_rotate_reverse_b(int *bstack, int blength, int *count);
void    ft_push_b(int *astack, int *bstack, int *alength, int *blength, int *count);

// -- Stack A && Stack B --
void    ft_swap_stacks(int *astack, int *bstack, int *count);
void    ft_rotate_stacks(int *astack, int *bstack, int alength, int blength, int *count);
void    ft_rotate_reverse_stacks(int *astack, int *bstack, int alength, int blength, int *count);

//-------- Less Than 10 Inputs --------
void ft_less_than_ten_inputs(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_get_min(int *astack, int *alength, int *count);
void ft_get_max(int *astack, int *alength, int *count);
void ft_compare_two_a(int *astack, int *count);
void ft_four_five_inputs(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_three_inputs_a(int *astack, int alength, int *count);

//-------- New Try --------
void ft_three_first(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_sort(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_position_nbr(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_first_or_last(int *astack, int *bstack, int *alength, int *blength, int *count);
void    ft_order_final(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_first_near(int *astack, int *bstack, int *alength, int *blength, int *count);

//-------- Try of Try --------
void ft_three_inputs_b(int *bstack, int blength, int *count);
void ft_compare_two_b(int *bstack, int *count);
void ft_position_nbr_b(int *astack, int *bstack, int *alength, int *blength, int *count);
int is_minor(int *astack, int *alength, int media);
void ft_calculate_media(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_send_lowest_b(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_sort_new(int *astack, int *bstack, int *alength, int *blength, int *count);

//Utils
int     ft_atoi(const char *str);

//For Tests
void ft_print_stacks(int *astack, int *bstack, int alength, int blength);
int ft_checker(int *astack, int *alength);


#endif