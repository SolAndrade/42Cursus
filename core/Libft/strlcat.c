/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:46:30 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/24 17:46:47 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// int main()
// {
//     char strdest[20] = "hola";
//     char strsrc[] = "uno dos";
//     printf("\nFT_STRLCAT %zu", ft_strlcat(strdest, strsrc, 7));
//     printf("\n%s", strdest);
// }
