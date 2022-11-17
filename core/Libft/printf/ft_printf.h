/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:23:26 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/10 18:28:52 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *type, ...);
// -------------------------------- CHAR --------------------------------
void	ft_putstr(char *s, int *count);
void	ft_putchar(char c, int *count);
// ------------------------------- DECIMAL ------------------------------
void	ft_putnbr(int n, int *count);
void	ft_putunsigned(long int n, int *count);
// -------------------------------- HEXA --------------------------------
void	ft_puthexa(unsigned long int n, int *count, int type);
// ---------------------------- FORMAT CASES ----------------------------
int		ft_formats(va_list arg, const char *format, int *count, int *i);

#endif