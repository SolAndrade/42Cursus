/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:09:48 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 17:23:06 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies n characters from str2 to str1, but for overlapping memory 
/// blocks, memmove() is a safer approach than memcpy().
/// @param dst Pointer to the destination array where the content is to be 
/// copied, type-casted to a pointer of type void*.	
/// @param src Pointer to the source of data to be copied, type-casted to a 
/// pointer of type void*.
/// @param len Number of bytes to be copied.
/// @return A pointer to the destination, which is str1.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (i < len)
	{
		if (dst < src)
			dst2[i] = src2[i];
		else
			dst2[len - i - 1] = src2[len - i - 1];
		i++;
	}
	return (dst);
}
