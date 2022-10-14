/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:01:51 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/10 18:29:46 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief Decompreses 'n' to know the amount of digits in it.
/// @param n Number its length to be known.
/// @return Amount of digits in the number.
int	ft_num_len(int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

/// @brief Decompreses 'n' (unsigned long) in base 16 (hexadecimal).
/// @param n Number to be printed.
/// @param count Counter for the amount of characters already printed.
/// @param type 1 if the char needs to be upcase or 0 if not, 2 if the 
/// result needs to have '0x' at the beginning.
void	ft_puthexa(unsigned long int n, int *count, int type)
{
	if (n == 0 && ft_num_len(n) == 1)
		ft_putchar('0', count);
	if (type == 2)
	{
		ft_putstr("0x", count);
		type = 0;
	}
	if (n < 0)
		n = 4294967296 + n;
	if (n >= 16)
		ft_puthexa(n / 16, count, type);
	if (n % 16 < 10)
		ft_putchar((n % 16) + 48, count);
	else if (type == 1)
		ft_putchar((n % 16) + 55, count);
	else if (type == 0)
		ft_putchar((n % 16) + 87, count);
}
