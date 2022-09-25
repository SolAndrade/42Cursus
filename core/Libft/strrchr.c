/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:03:07 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/22 16:58:50 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}

// int main()
// {
//     const char str[] = "http://www.tutorialspoint.com";
//     const char ch = 'w';
//     char *ret;
//     char *retft;

//     ret = strrchr(str, ch);
//     retft = ft_strrchr(str, ch);

//     printf("String after |%c| in strrchr is - |%s|\n", ch, ret);
//     printf("String after |%c| in ft_strrchr is - |%s|\n", ch, retft);

//     return(0);
// }
