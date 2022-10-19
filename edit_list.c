/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:11:42 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/19 13:28:30 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function creates linked list and adds content to it
t_list	*create_list(int32_t len, char **content)
{
	t_list	*p;
	t_list	*temp;
	t_list	*head;
	int32_t	i;

	p = NULL;
	head = NULL;
	i = 1;
	while (i < len)
	{
		temp = new_node(atoi(content[i]));
		if (head == NULL)
			head = temp;
		else
		{
			if (p == NULL)
				p = head;
			else
				p = p->next;
			p->next = temp;
		}		
		i++;
	}
	return (head);
}

t_list	*new_node(int32_t content)
{
	t_list	*new;

	new = NULL;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->val = content;
	new->next = NULL;
	new->all = NULL;
	return (new);
}

void	del_last(t_list **node)
{
	t_list	*temp;

	temp = *node;
	if (*node == NULL)
		return ;
	if ((*node)->next == NULL)
	{
		ft_lstdelone(node, free_);
		*node = NULL;
		return ;
	}
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_lstdelone(&temp->next, free_);
	(temp)->next = NULL;
}

/**
 * @brief Adds the node ’new’ at the end of the list
 * 
 * @param lst  The address of a pointer to the first link of a list
 * @param new  The address of a pointer to the node to be added to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}	
	last = l_last(*lst);
	last->next = new;
}
