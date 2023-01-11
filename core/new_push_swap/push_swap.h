/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:02:36 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/11 18:01:41 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

//-------- Movements --------

typedef struct s_stacks
{
	int			data;
	int				index;
	int				target_pos;
	int				moves;
	int				moves_a;
	int				moves_b;
}	t_stacks;

typedef struct s_movements
{
	int				aux;
	int				aux_index;
	int				i;
}	t_movements;

typedef struct s_main
{
	int			arg;
	int			iarr;
	long		nbr;
	int			al;
	int			bl;
	int			count;
}	t_main;

// -- Stack A --
void	ft_swap_a(t_stacks *astack, int *count);
void	ft_push_a(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count);
void	ft_rotate_a(t_stacks *astack, int alength, int *count);
void	ft_rotate_reverse_a(t_stacks *astack, int alength, int *count);

// -- Stack B --
void	ft_swap_b(t_stacks *bstack, int *count);
void	ft_rotate_b(t_stacks *bstack, int blength, int *count);
void	ft_rotate_reverse_b(t_stacks *bstack, int blength, int *count);
void	ft_push_b(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count);

// -- Stack A && Stack B --
void	ft_swap_stacks(t_stacks *astack, t_stacks *bstack, int *count);
void	ft_rotate_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength, int *count);
void	ft_rotate_reverse_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength, int *count);

//-------- Less Than 3 Inputs --------
void	ft_three_or_less_inputs(t_stacks *astack, int *alength, int *count);
void	ft_compare_two_a(t_stacks *astack, int *count);
void	ft_three_inputs_a(t_stacks *astack, int alength, int *count);

// --------------- Bubble Sort --------------
void	ft_bubble_sort(t_stacks *astack, int *alength);
void	ft_swap_bubble(t_stacks *astack, int pos);

void	ft_sorting_numbers(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count);
void	ft_assign_final_pos(t_stacks *astack, t_stacks *astack_aux, int *alength);
void	ft_assing_target_pos(t_stacks *astack, t_stacks *bstack, int *alength, int *blength);
void	ft_send_all_to_b(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count);
void	ft_calculate_moves(t_stacks *bstack, int *alength, int *blength);
void	ft_accomodate_number(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count);
void	ft_accomodate_number_2(t_stacks *astack, t_stacks *bstack, int *alength, int *blength, int *count);
void	ft_accomodate_number_3(t_stacks *bstack, int *blength, int *count);
int		ft_get_min_movements(t_stacks *bstack, int *blength);

// ------------------ Utils --------------------
long		ft_atol(const char *str);
int		ft_get_max(t_stacks *stack, int *length);
int		ft_get_max_index(t_stacks *stack, int *length);
void	ft_order_final_a(t_stacks *astack, int *alength, int *count);
int		ft_is_there_a_minor(t_stacks *stack, int *length, int media);
void	ft_empty_struct(t_stacks *astack, t_stacks *bstack, int alength);

// -------------------- Split --------------------
int	ft_count_numbers(const char *s);
int		ft_split(char const *s, t_stacks *alength);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_split(const char *str);
char	*ft_strdup(char *src);
int	ft_count_numbers_string(char *s);

//For Tests
void	ft_print_stacks(t_stacks *astack, t_stacks *bstack, int alength, int blength);
int		ft_checker_a(t_stacks *astack, int *alength);
int		ft_check_int(char *string);
void	ft_print_stacks_all_data(t_stacks *astack, t_stacks *bstack, int alength, int blength);
int ft_check_doubles(t_stacks *astack, int *alength);
int ft_check_errors(char *string);
int ft_error();

#endif
