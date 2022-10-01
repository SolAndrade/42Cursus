/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:13:25 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 19:21:25 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Checks if the passed character is alphabetic.
/// @param c Character to be checked.
/// @return Non-zero value if c is an alphabet, else it returns 0.
int	ft_isalpha(int c)
{
	if ((c >= 65) && (c <= 90))
		return (1);
	else if ((c >= 97) && (c <= 122))
		return (1);
	return (0);
}
