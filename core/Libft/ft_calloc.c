/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:41:00 by soandrad          #+#    #+#             */
/*   Updated: 2022/09/29 20:13:11 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Allocates enough space for count objects that are size 
/// bytes of memory. The allocated memory is filled with bytes of value zero.
/// @param count Number of elements to be allocated.
/// @param size Size of elements.
/// @return A pointer to the allocated memory
void	*ft_calloc(size_t count, size_t size)
{
	int		*arr;

	arr = (int *) malloc (count * size);
	if (arr)
		ft_bzero(arr, (count * size));
	return (arr);
}
