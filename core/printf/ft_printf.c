/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:07:34 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/07 17:10:20 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void    ft_putstr(char *s, int *cont);
void    ft_putnbr(int n, int *cont);
void    ft_putchar(char c, int *cont);
void	ft_putdecimal(int n, int *cont);
char	ft_puthexa(int n, int *cont);
void	ft_tolower(char c, int *cont);
void	ft_toupper(char c, int *cont);

int ft_printf(char const *type, ...)
{
    int i;
    unsigned int integer;
    char *s;
    int cont;

    cont = 0;
    i = 0;
    va_list arg;
    va_start(arg, type);
    while(type[i] != '\0')
    {
        while(type[i] != '%' && type[i] != '\0')
        {
            ft_putchar(type[i], &cont);
            i++;
        }
        if (type[i] == '%' && type[i] != '\0')
        {
            i++;
            if (type[i] == 'c')
            {
                integer = va_arg(arg, int);
                ft_putchar(integer, &cont);
            }
            else if (type[i] == 's')
            {
                s = va_arg(arg, char *);
                ft_putstr(s, &cont);
            }
            else if (type[i] == 'p')
            {
                integer = va_arg(arg, int);
                ft_puthexa(integer, &cont);
            }
            else if (type[i] == 'i' || type[i] == 'd')
            {
                integer = va_arg(arg, int);
                ft_putnbr(integer, &cont);
            }
            else if (type[i] == 'u')
            {
                integer = va_arg(arg, int);
                ft_putdecimal(integer, &cont);
            }
            else if (type[i] == 'x')
            {
                integer = va_arg(arg, int);
                ft_puthexa(integer, &cont);
            }
            else if (type[i] == 'X')
            {
                integer = va_arg(arg, int);
                ft_puthexa(integer, &cont);
            }
            else
                ft_putchar(type[i], &cont);
            i++;
        }
    }
    va_end(arg);
    return (cont);
}

int main()
{
    //printf("%d", ft_istype("a%  d"));
    // printf("%c", 'e');
    // printf("\n%i", ft_printf(" NULL %s NULL ", NULL));
    // int x = 123;
    // unsigned int *ptr = &x;
    // printf("The address is: %p, the value is %d", ptr, *ptr);
    //ft_printf("ft%p", -1);
    //printf("print\n%p", -1);
    // printf(" %x ", 29);

}