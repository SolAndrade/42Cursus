/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:01:51 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/06 21:39:20 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c, int cont)
{
	write(1, &c, 1);
	cont++;
	return (cont);
}

int ft_putstr(char *s, int cont)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		cont = ft_putchar(s[i], cont);
		i++;
	}
	return (cont);
}

int	ft_putnbr(int n, int cont)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			cont = ft_putchar('-', cont);
			// write(1, "-", 1);
			n *= -1;
		}
		if (n > 9)
			cont = ft_putnbr(n / 10, cont);
		c = (n % 10) + 48;
		
		write(1, &c, 1);
	}
}
