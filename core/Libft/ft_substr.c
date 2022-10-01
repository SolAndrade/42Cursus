/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:20:13 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:18:36 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Reserves (with malloc) and returns a substring of the string ’s’. 
/// The substring begins in 'start’ and has a max ’len’.
/// @param s The string from where to create the substring. 
/// @param start The index of the character in 's' from where to begin the 
/// substring.
/// @param len The max length of the substring.
/// @return The substring of NULL if the memory reservation fails.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*str;
	size_t	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	i = 0;
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len && s[i + start])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
