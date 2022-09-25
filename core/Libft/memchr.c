/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:04:14 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/24 18:25:48 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

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

// int main()
// {
//     char *s = "hola";
//     int c = 'o';
//     size_t n = 4;
//     printf("MEMCHR %s", memchr(s, c, n));
//     printf("\nFT_MEMCHR %s", ft_memchr(s, c, n));
// }
