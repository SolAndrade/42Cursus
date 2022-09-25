/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:09:48 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/23 14:44:47 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;
	char			*tmp;

	i = 0;
	tmp = (char *)malloc(len * sizeof(char *));
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst2 == NULL && src2 == NULL)
		return (dst);
	while (i < len)
	{
		tmp[i] = src2[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst2[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (dst2);
}

// int main () {
//    char dest[] = "oldstring";
//    const char src[]  = "123456";

//    printf("MEMMOVE %s", memmove(dest, src, 4));
//    printf("\nFT_MEMMOVE %s", ft_memmove(dest, src, 4));

//    return(0);
// }