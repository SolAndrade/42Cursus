/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:52:37 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:18:02 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locates the first occurrence of the null-terminated string s2 in 
/// the string s1, where not more than len characters are searched. Characters 
/// that appear after a '\0' character are not searched.
/// @param s1 First string.
/// @param s2 Second string.
/// @param len Number of bytes to be located.
/// @return s1 if needle is an empty string; if s2 occurs nowhere in s1, NULL 
/// is returned; otherwise a pointer to the first character of the first 
/// occurrence of s2 is returned.
char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)&s1[i]);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s1[i + j] != '\0'
			&& s1[i + j] == s2[j]
			&& i + j < len)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
