/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:19:32 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 17:23:17 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies the character c (an unsigned char) to the first n characters 
/// of the string pointed to, by the argument str.
/// @param b Pointer to the block of memory to fill.
/// @param c Value to be set. The value is passed as an int, but the function 
/// fills the block of memory using the unsigned char conversion of this value.
/// @param len Number of bytes to be set to the value.
/// @return A pointer to the memory area str.
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
