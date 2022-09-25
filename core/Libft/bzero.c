/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:05:20 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/22 18:21:38 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	int				zero;
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	zero = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// int main()
// {
//     char b[] = "hola";
// 	size_t n = 4;
// 	printf("BZERO %s", bzero(b, n));
// 	//printf("\nFT_BZERO %s", ft_bzero(b, n));
// 	ft_bzero(b, n);
// }
