/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/04 17:25:16 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new node (ptr).
 * The variable ’content’ (in t_list) is initialized with the value of ’content’
 * The variable ’next’ is initialized to NULL.
 * 
 * @param content The content to create the node with.
 * @return t_list* 
 */
Node	*ft_lstnew(int content)
{
	Node	*ptr;

	ptr = (Node *)malloc(sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	ptr->value = content;
	ptr->next = NULL;
	return (ptr);
}