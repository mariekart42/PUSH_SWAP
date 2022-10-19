/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:27:44 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/19 14:17:55 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_(void **toFree)
{
	if (*toFree)
	{
		free(*toFree);
		*toFree = NULL;
	}
}

/**
 * @brief Deletes and frees the given node and every successor of that node, 
 * using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
 * 
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void **))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(lst, del);
		(*lst) = temp;
	}
}

/**
 * @brief Takes as parameter a node and frees the memory of the node’s 
 * content using the function ’del’ given as a parameter and free the node. 
 * The memory of ’next’ must not be freed.
 * 
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list **lst, void (*del)(void **))
{
	if (!lst || !del)
		return ;
	del((void **)&(*lst)->all);
	free_((void **)lst);
}
