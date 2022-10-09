/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:23:26 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/09 20:44:54 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

#include <unistd.h>
#include <stdarg.h>

int     ft_printf(char const *type, ...);
// -------------------------------- CHAR --------------------------------
void    ft_putstr(char *s, int *count);
void    ft_putchar(char c, int *count);
// ------------------------------- DECIMAL ------------------------------
void    ft_putnbr(int n, int *count);
void	ft_putunsigned(long int n, int *count);
// -------------------------------- HEXA --------------------------------
void	ft_puthexa(unsigned long int n, int *count, int mayus);
// ---------------------------- FORMAT CASES ----------------------------
int     ft_ischar(va_list arg, const char *format, int *count, int *i);
int     ft_isdecimal(va_list arg, const char *format, int *count, int *i);
int     ft_ishexa(va_list arg, const char *format, int *count, int *i);

#endif