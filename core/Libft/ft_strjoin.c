/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:39:59 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 19:54:56 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Reserves (with malloc) a new string, made up by ’s1’ and ’s2’.
/// @param s1 First string
/// @param s2 Second string
/// @return The string made up by 's1' and 's2'.
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (str && (s1 || s2))
	{
		while (*s1)
		{
			str[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			str[i] = *s2++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
