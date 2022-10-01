/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:34:40 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 17:22:50 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares the first n bytes of memory area str1 and
/// memory area str2.
/// @param s1 Pointer to a block of memory.
/// @param s2 Pointer to a block of memory.
/// @param n Number of bytes to be compared.
/// @return If < 0 it indicates str1 is less than str2. 
/// If > 0 it indicates str2 is less than str1. 
/// If = 0 it indicates str1 is equal to str2.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0)
	{
		while (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
