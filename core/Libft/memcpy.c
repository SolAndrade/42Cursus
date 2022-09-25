/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:24:42 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/23 14:09:15 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

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

// int main()
// {
//     char dst[50];
//     char src[] = "www.intra42.com";
//     size_t n = 8;
//     printf("MEMCPY %s", memcpy(dst, src, n));
//     printf("\nFT_MEMCPY %s", ft_memcpy(dst, src, n));
// }