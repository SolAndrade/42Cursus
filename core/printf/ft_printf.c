/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:07:34 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/06 20:55:35 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_putstr(char *s);
void	ft_putnbr(int n);
int ft_valid_convertion(char c, void *param);

int ft_printf(char const *type, ...)
{
    int i;
    unsigned int integer;
    char *s;

    i = 0;
    va_list arg;
    va_start(arg, type);
    while(type[i] != '\0')
    {
        while(type[i] != '%')
        {
            write(1, &type[i], 1);
            i++;
        }
        i++;
        if (type[i] == 'c')
        {
            integer = va_arg(arg, int);
            write(1, &integer, 1);
            i++;
        }
        else if (type[i] == 's')
        {
            s = va_arg(arg, char *);
            ft_putstr(s);
            i++;
        }
        else if (*type == 'p')
            return (1);
        else if (type[i] == 'i' || type[i] == 'd')
        {
            integer = va_arg(arg, int);
            ft_putnbr(integer);
        }
        else if (*type == 'u')
            return (1);
        else if (*type == 'x')
            return (1);
        else if (*type == 'X')
            return (1);
        // else
        //     write (1, &type[i], 1);
        // i++;
    }
    va_end(arg);
    return (0);
}

// int ft_valid_convertion(char c, void *param)
// {
//     if (c == 'c')
//         write(1, &c, 1);
//     else if (c == 's')
//         ft_putstr((char *)param);
//     else if (c == 'p')
//         return (1);
//     else if (c == 'd')
//         return (1);
//     else if (c == 'i')
//         return (1);
//     else if (c == 'u')
//         return (1);
//     else if (c == 'x')
//         return (1);
//     else if (c == 'X')
//         return (1);
//     return (0);
// }

int main()
{
    //printf("%d", ft_istype("a%  d"));
    // printf("esto %s frase\n", "es una");
    ft_printf("%s", "123");
}