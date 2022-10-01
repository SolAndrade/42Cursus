/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:14:47 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 17:12:05 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Deletes and releases the node 'lst' given and every consecutive of 
/// that node, using the funcion 'del' and free. At the end, the pointer to 
/// the list has to be NULL.
/// @param lst The direction of a pointer to a node.
/// @param del A pointer to afunction used to delete the content of a node.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!*lst)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}		
	free(node);
}
