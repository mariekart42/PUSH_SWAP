/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:11:42 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/15 16:17:34 by mmensing         ###   ########.fr       */
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
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->val = content;
	new->next = NULL;
	return (new);
}

void	free_list(t_list *head)
{
	t_list	*temp;

	if (!head)
		return ;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	del_last(t_list **node)
{
	t_list	*temp;

	temp = *node;
	if (*node == NULL)
		return ;
	if ((*node)->next == NULL)
	{
		*node = NULL;
		return ;
	}
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	(temp)->next = NULL;
}
