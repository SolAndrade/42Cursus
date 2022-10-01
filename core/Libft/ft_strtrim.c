/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:01:03 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:18:26 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Eliminates every character found in 'set' from the begining and 
/// from the end of 's1', until it finds a character that is not included in 
/// 'set'. The string is then allocated in a substring with malloc.
/// @param s1 String to be cut.
/// @param set Characters to be eliminated from s1.
/// @return The cut string or NULL if the memory reservation fails.
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!set)
		return (ft_strdup((char *)s1));
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	str = ft_substr(s1, i, (len - i + 1));
	return (str);
}
