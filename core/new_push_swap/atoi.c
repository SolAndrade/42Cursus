/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:55:31 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/11 16:20:03 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


typedef struct atoi_data
{
	long	result;
	int		sign;
	int		s;
	int		p;
	int  	i;
}	t_atoi_data;

int	ft_check_errors_atol(const char *str, t_atoi_data ad);

/// @brief Converts the initial portion of the string pointed to 
/// by str to int representation.
/// @param str String representation of an integral number.
/// @return The converted integral number as an int value. If no valid 
/// conversion could be performed, it returns zero.
long	ft_atol(const char *str)
{
	t_atoi_data	ad;

	ad.i = 0;
	ad.result = 0;
	ad.sign = 1;
	ad.s = 0;
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
	if(ft_check_errors_atol(str, ad) != 0)
		return (2147483648);
	return (ad.result * ad.sign);
}

int	ft_check_errors_atol(const char *str, t_atoi_data ad)
{	
	while(str[ad.i] != '\0')
	{
		if((str[ad.i] <= 47 || str[ad.i] >= 58) || str[ad.i] == 32)
			return (1);
		ad.i++;
	}
	if((ad.result * ad.sign > 2147483647) || (ad.result * ad.sign < -2147483648))
		return (1);
	return (0);
}