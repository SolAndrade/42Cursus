/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:55:39 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:12:48 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct atoi_data
{
	int	result;
	int	sign;
	int	s;
	int	p;
}	t_atoi_data;

/// @brief Converts the initial portion of the string pointed to 
/// by str to int representation.
/// @param str String representation of an integral number.
/// @return The converted integral number as an int value. If no valid 
/// conversion could be performed, it returns zero.
int	ft_atoi(const char *str)
{
	t_atoi_data	ad;

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
	return (ad.result * ad.sign);
}
