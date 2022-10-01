/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:27:06 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:17:45 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Compares at most the first n bytes of str1 and str2.
/// @param s1 First string to be compared.
/// @param s2 Second string to be compared.
/// @param n Number of characters to be compared.
/// @return If < 0 it indicates str1 is less than str2. If > 0 it indicates 
/// str2 is less than str1. If = 0 it indicates str1 is equal to str2.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
