/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:29:16 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 18:54:21 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterates the list 'lst' and applies the function 'f' to the content
/// of every node. Creates a list as a result of the correct aplication of the 
/// function 'f' in every node. The funciton 'del' is used to eliminate the
/// content of every node, if needed.
/// @param lst A pointer to a node.
/// @param f  The direction of a pointr to a function used in the iteration 
// of every element of a list.
/// @param del A pointer to a function used to eliminate the content of a 
/// node, if needed.
/// @return The new list or NULL if the memory reservation fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_ft;
	t_list	*final_lst;

	if (!lst || !f)
		return (0);
	final_lst = 0;
	while (lst != 0)
	{
		new_ft = (t_list *) malloc (sizeof(t_list));
		if (!new_ft)
		{
			ft_lstclear(&final_lst, del);
			return (0);
		}
		new_ft->content = f(lst->content);
		new_ft->next = NULL;
		ft_lstadd_back(&final_lst, new_ft);
		lst = lst->next;
	}
	return (final_lst);
}
