/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:11:42 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:18:51 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Converts lowercase letter to uppercase.
/// @param c Letter to be converted to uppercase.
/// @return Uppercase equivalent to c, if such value exists, else c remains 
/// unchanged. The value is returned as an int value that can be implicitly 
/// casted to char.
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	else
		return (c);
}
