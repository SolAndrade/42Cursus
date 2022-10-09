/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:13:25 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/09 20:44:21 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Prints a single character 'c' and iterates the value of the 
/// pointer 'count'.
/// @param c Character to be printed.
/// @param count Counter recieved as a pointer to the amount of characters 
/// already printed.
void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

/// @brief Iterates a string 's' and prints character by character with 
/// ft_putchar().
/// @param s String to be printed.
/// @param count Counter recieved as a pointer to the amount of characters 
/// already printed.
void ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}