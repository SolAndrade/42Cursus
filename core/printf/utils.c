/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:01:51 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/07 17:22:11 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_check(char *base);


void	ft_putchar(char c, int *cont)
{
	write(1, &c, 1);
	*cont = *cont + 1;
}

void ft_putstr(char *s, int *cont)
{
	int	i;

	i = 0;
	// if (!s)
	// 	return (0);
	while (s[i])
	{
		ft_putchar(s[i], cont);
		i++;
	}
}

void	ft_putnbr(int n, int *cont)
{
	char	c;

	if (n == -2147483648)
		ft_putstr("-2147483648", cont);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', cont);
			n *= -1;
		}
		if (n > 9)
			ft_putnbr(n / 10, cont);
		c = (n % 10) + 48;
		ft_putchar(c, cont);
	}
}

void	ft_putdecimal(unsigned char n, int *cont)
{
	long k;
	if (n >= 0)
		ft_putnbr(n, cont);
	else
	{
		k = n;
		ft_putnbr(k, cont);
	}
}

void	ft_tolower(char c, int *cont)
{
	if (c >= 65 && c <= 90)
	{
		ft_putchar(c + 32, cont);
	}
	else
		ft_putchar(c, cont);
}

void	ft_toupper(char c, int *cont)
{
	if (c >= 97 && c <= 122)
	{
		ft_putchar(c - 32, cont);
	}
	else
		ft_putchar(c, cont);
}

void	ft_puthexa(int n, int *cont)
{
	
}