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

//-------- This Works--------
void ft_three_first(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_sort(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_position_nbr(int *astack, int *bstack, int *alength, int *blength, int *count);
void    ft_order_final(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_first_near(int *stack_one, int *stack_two, int *count);
void ft_three_inputs_b(int *bstack, int blength, int *count);
void ft_compare_two_b(int *bstack, int *count);
void ft_position_nbr_b(int *astack, int *bstack, int *alength, int *blength, int *count);
int is_minor(int *astack, int *alength, int media);
void ft_send_lowest_b(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_sort_new(int *astack, int *bstack, int *alength, int *blength, int *count);
void    ft_order_final_b(int *astack, int *bstack, int *alength, int *blength, int *count);

//-------- This Actually works--------
void ft_order_by_stacks_b(int *astack, int *bstack, int *alength, int *blength, int *count);
void ft_three_first_not_so_order_b(int *bstack, int blength, int *count);
int ft_get_min_for_media(int *astack, int *alength);
int ft_get_media(int *astack, int *alength);

// ------------- New Try -----------------
int get_pos_nbr_b(int *astack, int *bstack, int *blength);
// void ft_order_by_stacks_a(int *astack, int *bstack, int *alength, int *blength, int *count);
int get_pos_nbr_a(int *astack, int *bstack, int *alength, int *blength);
void ft_order_by_stacks_a(int *astack, int *bstack, int *alength, int *blength, int *count);

// ------------ OLD ----------
int ft_get_media_old(int *astack, int *alength);


//Utils
int     ft_atoi(const char *str);

//For Tests
void ft_print_stacks(int *astack, int *bstack, int alength, int blength);
int ft_checker(int *astack, int *alength);
int ft_checker_b(int *bstack, int *blength);


#endif