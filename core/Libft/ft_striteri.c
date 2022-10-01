/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:31:47 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:17:03 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Applies the function 'f' to every character from string 's', 
/// given as parameters the position of every character of 's' and the direction
/// of the character itself that could be altered if necesary.
/// @param s String to iterate.
/// @param f Function applied to every character of 's'.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (*s)
	{
		f(i, (char *)s);
		i++;
		s++;
	}
}
