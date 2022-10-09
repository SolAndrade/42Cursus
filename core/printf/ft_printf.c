/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:07:34 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/09 20:58:39 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct printf_data
{
    unsigned int integer;
    char *s;
}   t_printf_data;

/// @brief Main function of the program. Iterates 'format' o know 
/// whether the thing to be printed is a character, a string, a decimal 
/// or an hexadecimal and if it is valid.
/// @param format Format of the thing to be printed.
/// @param ... Arguments used every time a data type wants to be printed.
/// @return Amount of characters printed.
int ft_printf(char const *format, ...)
{
    int i;
    int count;

    count = 0;
    i = 0;
    va_list arg;
    va_start(arg, format);
    while(format[i] != '\0')
    {    
        while(format[i] != '%' && format[i] != '\0')
                ft_putchar(format[i++], &count);
        if (format[i] == '%' && format[i] != '\0')
        {
            i++;
            if (ft_ischar(arg, format, &count, &i));
            else if (ft_isdecimal(arg, format, &count, &i));
            else if (ft_ishexa(arg, format, &count, &i));
            else
                ft_putchar(format[i], &count);
            i++;
        }
    }
    va_end(arg);
    return (count);
}

/// @brief Checks if the format passed as a parameter is a 
/// 'c' for a single character or 
/// 's' for a string.
/// @param arg List of arguments passed as parameters in ft_printf.
/// @param format Format of the thing to be printed.
/// @param count Counter recieved as a pointer to the amount of 
/// characters already printed.
/// @param i Iterator for format.
/// @return 0 if the format passed as a parameter isnt a char nor a 
/// string. 1 if it is.
int ft_ischar(va_list arg, const char *format, int *count, int *i)
{
    t_printf_data pd;
    if (format[*i] == 'c')
        ft_putchar(pd.integer = va_arg(arg, int), count);
    else if (format[*i] == 's')
        ft_putstr(pd.s = va_arg(arg, char *), count);
    else
        return (0);
    return (1);
}

/// @brief Checks if the format passed as a parameter is a 
/// 'i' or 'd' for an int or 
/// 'u' for an unsigned long int.
/// @param arg List of arguments passed as parameters in ft_printf.
/// @param format Format of the thing to be printed.
/// @param count Counter recieved as a pointer to the amount of 
/// characters already printed.
/// @param i Iterator for format.
/// @return 0 if the format passed as a parameter isnt a char 
/// nor a string. 1 if it is.
int ft_isdecimal(va_list arg, const char *format, int *count, int *i)
{
    t_printf_data pd;
    if (format[*i] == 'i' || format[*i] == 'd')
        ft_putnbr(pd.integer = va_arg(arg, int), count);
    else if (format[*i] == 'u')
        ft_putunsigned(pd.integer = va_arg(arg, int), count);
    else
        return (0);
    return (1);
}

/// @brief Checks if the format passed as a parameter is a 
/// 'p' for an unsigned long int, 
/// 'x' for an unsigned long int printed as an hexadecimal in low case letters or 
/// 'X' for an unsigned long int printed as an hexadecimal in up case letters.
/// @param arg List of arguments passed as parameters in ft_printf.
/// @param format Format of the thing to be printed.
/// @param count Counter recieved as a pointer to the amount of 
/// characters already printed.
/// @param i Iterator for format.
/// @return 0 if the format passed as a parameter isnt a char 
/// nor a string. 1 if it is.
int ft_ishexa(va_list arg, const char *format, int *count, int *i)
{
    t_printf_data pd;
    if (format[*i] == 'p')
        ft_puthexa(pd.integer = va_arg(arg, unsigned long), count, 2);
    else if (format[*i] == 'x')
        ft_puthexa(pd.integer = va_arg(arg, int), count, 0);
    else if (format[*i] == 'X')
        ft_puthexa(pd.integer = va_arg(arg, int), count, 1);
    else
        return (0);
    return (1);
}

// int main()
// {
//     ft_printf("%s", "abc");
//     printf("\n%s", "abc");
// }