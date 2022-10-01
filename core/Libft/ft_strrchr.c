/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:03:07 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:18:14 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief searches for the last occurrence of the character c (an unsigned 
/// char) in the string pointed to, by the argument str.
/// @param s The string.
/// @param c Character to be located. It is passed as its int promotion, but 
/// it is internally converted back to char.
/// @return A pointer to the last occurrence of character in str. If the value 
/// is not found, the function returns a null pointer.
char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}
