/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:17:13 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:18:43 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts a given letter to lowercase.
/// @param c The letter to be converted to lowercase.
/// @return Lowercase equivalent to c, if such value exists, else c remains 
/// unchanged. The value is returned as an int value that can be implicitly 
/// casted to char.
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	else
		return (c);
}
