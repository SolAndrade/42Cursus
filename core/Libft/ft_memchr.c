/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:04:14 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 17:22:40 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Searches for the first occurrence of the character c 
/// (an unsigned char) in the first n bytes of the string pointed 
/// to, by the argument str.
/// @param s Pointer to the block of memory where the search is performed.
/// @param c Value to be passed as an int, but the function performs 
/// a byte per byte search using the unsigned char conversion of this value.
/// @param n Bumber of bytes to be analyzed.
/// @return A pointer to the matching byte or NULL if the character 
/// does not occur in the given memory area.
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ret;
	unsigned char	*str;

	ret = (unsigned char)c;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == ret)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
