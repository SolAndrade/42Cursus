/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:55:31 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:27:44 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	t_at_dt	ad;

	ad = ft_assign_values_atol();
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
	{
		str++;
		ad.s = 1;
	}
	if (*str == '-' && ad.s == 0)
	{
		ad.sign = -1;
		str++;
	}
	else if (*str == '-' && ad.s == 1)
		ad.sign = 0;
	while (*str >= '0' && *str <= '9')
	{
		ad.result = ad.result * 10 + (*str - 48);
		str++;
	}
	if (ft_check_errors_atol(str, ad) != 0)
		return (2147483648);
	return (ad.result * ad.sign);
}

t_at_dt	ft_assign_values_atol(void)
{
	t_at_dt	ad;

	ad.result = 0;
	ad.sign = 1;
	ad.s = 0;
	return (ad);
}

int	ft_check_errors_atol(const char *str, t_at_dt ad)
{	
	ad.i = 0;
	while (str[ad.i] != '\0')
	{
		if ((str[ad.i] <= 47 || str[ad.i] >= 58) || str[ad.i] == 32)
			return (1);
		ad.i++;
	}
	if (ad.result * ad.sign > 2147483647)
		return (1);
	else if (ad.result * ad.sign < -2147483648)
		return (1);
	return (0);
}
