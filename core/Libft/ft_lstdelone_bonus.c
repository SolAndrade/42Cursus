/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:06:49 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 17:13:42 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Takes as a parameter a node 'lst' and releases the memory 
/// content using the function 'del' given as a parameter, releasing 
/// the node as well. The memory of 'next' doesn't has to be released.
/// @param lst The node to be released.
/// @param del  A ponter to the function used to release the content of 
/// the node.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
