/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:52:37 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/25 18:49:45 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t s2len;

	i = 0;
	s2len = ft_strlen(s2);
	if (0 == s2len)
		return (char *)s1;
	if (len < s2len)
		return (NULL);
	while (i <= len - s2len)
	{
		if ((s1[0] == s2[0]) &&
			(0 == ft_strncmp(s1, s2, s2len)))
			return (char *)s1;
		s1++;
		i++;
	}
	return NULL;
}

// int main()
// {
//     char *s1 = "lorem ipsum dolor sit amet";
//     char *s2 = "ipsum";
//     printf("STRNSTR %s", strnstr(s1, s2, 15));
//     printf("\nFT_STRNSTR %s", ft_strnstr(s1, s2, 15));
// }
