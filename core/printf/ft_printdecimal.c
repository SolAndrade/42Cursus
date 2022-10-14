/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:14:22 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/10 18:14:34 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Decompreses 'n' in base 10.
/// @param n Number to be printed.
/// @param count Counter for the amount of characters already printed.
void	ft_putnbr(int n, int *count)
{
	char	c;

	if (n == -2147483648)
		ft_putstr("-2147483648", count);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', count);
			n *= -1;
		}
		if (n > 9)
			ft_putnbr(n / 10, count);
		c = (n % 10) + 48;
		ft_putchar(c, count);
	}
}

/// @brief Decompreses 'n' of (long) in base 10.
/// @param n Number to be printed.
/// @param count Counter for the amount of characters already printed.
void	ft_putunsigned(long int n, int *count)
{
	if (n < 0)
		n = 4294967296 + n;
	if (n > 9)
		ft_putunsigned(n / 10, count);
	ft_putchar((n % 10) + 48, count);
}
