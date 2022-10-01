/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:24:42 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 17:22:58 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies n characters from memory area src to memory area dest.
/// @param dst Pointer to the destination array where the content 
/// is to be copied, type-casted to a pointer of type void*.
/// @param src Pointer to the source of data to be copied, 
/// type-casted to a pointer of type void*.
/// @param n Number of bytes to be copied.
/// @return A pointer to destination, which is str1.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst2 == NULL && src2 == NULL)
		return (dst);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}
