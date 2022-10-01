/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:46:30 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:17:13 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Copies and concatenates strings with the same input parameters 
/// and output result.
/// @param dst First string.
/// @param src Second string.
/// @param size Number of bytes to be concatenated.
/// @return The total length of the string they tried to create 
/// (initial length of dst plus the length of src).
size_t	ft_strlcat( char *dst, const char *src, size_t size )
{
	unsigned int	sdest;
	unsigned int	ssrc;
	unsigned int	dstlen;
	unsigned int	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	sdest = dstlen;
	ssrc = srclen;
	if (size == 0 || sdest >= size)
		return (size + ssrc);
	srclen = 0;
	while ((src[srclen] != '\0') && (srclen < size - sdest - 1))
	{
		dst[dstlen] = src[srclen];
		++dstlen;
		++srclen;
	}
	dst[dstlen] = '\0';
	return (sdest + ssrc);
}
