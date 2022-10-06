/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:07:34 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/06 21:38:36 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(char *s, int cont);
int	ft_putnbr(int n, int cont);
int     ft_putchar(char c, int cont);

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
            cont = ft_putchar(type[i], cont);
            i++;
        }
        if (type[i] == '%' && type[i] != '\0')
        {
            i++;
            if (type[i] == 'c')
            {
                integer = va_arg(arg, int);
                cont = ft_putchar(integer, cont);
            }
            else if (type[i] == 's')
            {
                s = va_arg(arg, char *);
                cont = ft_putstr(s, cont);
            }
            else if (*type == 'p')
                return (1);
            else if (type[i] == 'i' || type[i] == 'd')
            {
                integer = va_arg(arg, int);
                ft_putnbr(integer, cont);
            }
            else if (*type == 'u')
                return (1);
            else if (*type == 'x')
                return (1);
            else if (*type == 'X')
                return (1);
            else
                ft_putchar(type[i], cont);
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
    // ft_printf("abc %s", "123");
    // printf("printf NULL %s NULL ", NULL);
    printf("\n%i", ft_printf(" NULL %s NULL ", NULL));
}