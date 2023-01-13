/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:02:36 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:26:15 by soandrad         ###   ########.fr       */
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
	int				data;
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
}	t_main;

typedef struct atoi_data
{
	long	result;
	int		sign;
	int		s;
	int		p;
	int		i;
}	t_at_dt;

// -- Stack A --
void	ft_swap_a(t_stacks *astack);
void	ft_push_a(t_stacks *astack, t_stacks *bstack, int *al, int *bl);
void	ft_rotate_a(t_stacks *astack, int alength);
void	ft_rotate_reverse_a(t_stacks *astack, int alength);

// -- Stack B --
void	ft_swap_b(t_stacks *bstack);
void	ft_rotate_b(t_stacks *bstack, int blength);
void	ft_rotate_reverse_b(t_stacks *bstack, int blength);
void	ft_push_b(t_stacks *astack, t_stacks *bstack, int *al, int *bl);

// -- Stack A && Stack B --
void	ft_swap_stacks(t_stacks *astack, t_stacks *bstack);
void	ft_rotate_stacks(t_stacks *astack, t_stacks *bstack, int al, int bl);
void	ft_rotate_re_stacks(t_stacks *astack, t_stacks *bstack, int al, int bl);

//-------- Less Than 3 Inputs --------
void	ft_three_or_less_inputs(t_stacks *astack, int *alength);
void	ft_compare_two_a(t_stacks *astack);
void	ft_three_inputs_a(t_stacks *astack, int alength);

// --------------- Bubble Sort --------------
void	ft_bubble_sort(t_stacks *astack, int *alength);
void	ft_swap_bubble(t_stacks *astack, int pos);

void	ft_sorting_number(t_stacks *astack, t_stacks *bstack, int *al, int *bl);
void	ft_assign_final_pos(t_stacks *astack, t_stacks *astack_aux, int *al);
void	ft_target_pos(t_stacks *astack, t_stacks *bstack, int *al, int *bl);
void	ft_send_all_to_b(t_stacks *astack, t_stacks *bstack, int *al, int *bl);
void	ft_calculate_moves(t_stacks *bstack, int *alength, int *blength);
void	ft_accom_number(t_stacks *astack, t_stacks *bstack, int *al, int *bl);
void	ft_accom_number_2(t_stacks *astack, t_stacks *bstack, int *al, int *bl);
void	ft_accom_number_3(t_stacks *bstack, int *blength);
int		ft_get_min_movements(t_stacks *bstack, int *blength);

// ------------------ Utils --------------------
long	ft_atol(const char *str);
int		ft_get_max(t_stacks *stack, int *length);
int		ft_get_max_index(t_stacks *stack, int *length);
void	ft_order_final_a(t_stacks *astack, int *alength);
int		ft_is_there_a_minor(t_stacks *stack, int *length, int media);
void	ft_empty_struct(t_stacks *astack, t_stacks *bstack, int alength);
int		ft_fill_stacks(t_stacks *astack, int argc, char **argv);
void	ft_free_ps(t_stacks *astack, t_stacks *bstack, int *alength);
int		ft_fill_stacks(t_stacks *astack, int argc, char **argv);
t_at_dt	ft_assign_values_atol(void);

// -------------------- Split --------------------
int		ft_count_numbers(const char *s);
int		ft_split(char const *s, t_stacks *alength);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_split(const char *str);
int		ft_count_numbers_string(char *s);
char	*ft_strdup_split(char *src);

// -------------------- Input Checks ------------------------
int		ft_check_errors_atol(const char *str, t_at_dt ad);
int		ft_checker_a(t_stacks *astack, int *alength);
int		ft_check_int(char *string);
int		ft_check_doubles(t_stacks *astack, int *alength);
int		ft_check_errors(char *string);
int		ft_error(int i);
int		ft_checks(t_stacks *astack, t_stacks *bstack, int *al, int *bl);

// ----------------------- Checker -------------------------
void	ft_empty_struct(t_stacks *astack, t_stacks *bstack, int alength);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_read_movement(t_stacks *astack, t_stacks *bstack, int *al, int *bl);
int		ft_read_movement_a(t_stacks *astack, int *alength, char *line);
int		ft_read_movement_b(t_stacks *bstack, int *blength, char *line);
void	ft_checker(t_stacks *astack, t_stacks *bstack, int *al, int *bl);
int		ft_checker_response(t_stacks *astack, int *alength, int flag);
char	*get_next_line(int fd);

#endif
