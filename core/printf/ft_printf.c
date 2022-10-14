/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:07:34 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/10 18:32:18 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct printf_data
{
	unsigned int	integer;
	char			*s;
}	t_printf_data;

<<<<<<< HEAD
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
=======
/// @brief Iterates 'format' to know whether the thing to be printed is 
/// a character, a string, a decimal or an hexadecimal and if it is valid.
/// @param format Format of the thing to be printed.
/// @param ... Arguments used every time a data type wants to be printed.
/// @return Amount of characters printed.
int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ft_putchar(format[i++], &count);
		if (format[i] == '%' && format[i] != '\0')
		{
			i++;
			if (!ft_formats(arg, format, &count, &i))
				ft_putchar(format[i], &count);
			i++;
		}
	}
	va_end(arg);
	return (count);
>>>>>>> 5a8cc785945cc64485c43cf87be70bd996045704
}

/// @brief Checks if the format required is valid.
/// @param arg List of arguments passed as parameters in ft_printf.
/// @param format Format of the thing to be printed.
/// @param count Counter for the amount of characters already printed.
/// @param i Iterator for format.
/// @return 0 if false 1 if true.
int	ft_formats(va_list arg, const char *format, int *count, int *i)
{
<<<<<<< HEAD
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
=======
	t_printf_data	pd;

	if (format[*i] == 'c')
		ft_putchar(va_arg(arg, int), count);
	else if (format[*i] == 's')
		ft_putstr(va_arg(arg, char *), count);
	else if (format[*i] == 'i' || format[*i] == 'd')
		ft_putnbr(va_arg(arg, int), count);
	else if (format[*i] == 'u')
		ft_putunsigned(va_arg(arg, int), count);
	else if (format[*i] == 'p')
		ft_puthexa(va_arg(arg, unsigned long), count, 2);
	else if (format[*i] == 'x')
		ft_puthexa(pd.integer = va_arg(arg, int), count, 0);
	else if (format[*i] == 'X')
		ft_puthexa(pd.integer = va_arg(arg, int), count, 1);
	else
		return (0);
	return (1);
}
>>>>>>> 5a8cc785945cc64485c43cf87be70bd996045704
