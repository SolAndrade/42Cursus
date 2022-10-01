/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:22:24 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:16:51 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Searches for the first occurrence of the character c (an unsigned 
/// char) in the string pointed to by the argument str.
/// @param s The string to be scanned.
/// @param c Character to be searched in str.
/// @return A pointer to the first occurrence of the character c in the 
/// string str, or NULL if the character is not found.
char	*ft_strchr(const char *s, int c)
{
	unsigned char	ret;

	ret = (unsigned char)c;
	if (ret >= 0 && ret <= 255)
	{
		while (*s != ret)
		{
			if (*s == '\0')
				return (0);
			s++;
		}
	}
	return ((char *)s);
}
