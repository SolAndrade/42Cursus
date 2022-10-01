/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:05:20 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:12:58 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief Writes n zeroed bytes to the string s. If n is zero, 
/// bzero() does nothing.
/// @param s 
/// @param n
void	ft_bzero(void *s, size_t n)
{
	int				zero;
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	zero = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
