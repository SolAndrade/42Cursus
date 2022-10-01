/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:33:12 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:17:38 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Applies the function 'f' to every character from string 's', given 
/// as parameters the position of every character of 's' and the characteri 
/// itself. It generates a new string with the result of the use from 'f'.
/// @param s String to iterate.
/// @param f Function applied to every character from 's'.
/// @return The string created as a result of applying 'f' to every character 
/// of 's' or NULL if the memory reservation fails.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	str = (char *) malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
