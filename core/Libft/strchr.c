/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:22:24 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/22 16:59:39 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ret;

	ret = (unsigned char)c;
	if (ret >= 0 && ret <= 255)
	{
		while (*s != ret)
		{
			if (*s == '\0')
				return (0);
			s++;
		}
	}
	return ((char *)s);
}

// int main()
// {
//     const char str[] = "www.test.com";
//     const char ch = '.';
//     char *ret;
//     char *retft;

//     ret = strchr(str, ch);
//     retft = ft_strchr(str, ch);

//     printf("String after |%c| in strchr is - |%s|\n", ch, ret);
//     printf("String after |%c| in ft_strchr is - |%s|\n", ch, retft);

//     return(0);
// }
