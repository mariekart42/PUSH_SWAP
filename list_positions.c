/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:19:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/19 13:24:43 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Returns the last node of the list.
 * 
 * @param head The beginning of the list.
 * @return t_list* Last node of the list
 */
t_list	*l_last(t_list *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

// function returns pointer to place in given stack of content node
t_list	*place(t_list*stack, t_list*node)
{
	if (stack == NULL)
		return (NULL);
	if (node == NULL)
		return (NULL);
	while (stack->val != node->val)
		stack = stack->next;
	return (stack);
}

//prev returns the previouse content of node in stack
//if node is NULL, function returns the content before NULL 
//  in the current stack
//function doesnt handle cases where there is no prev of node
//  or node or stack are NULL!
t_list	*prev(t_list *stack, t_list*node)
{
	if (stack == node)
		return (NULL);
	while (stack->next != NULL && stack->next->val != node->val)
		stack = stack->next;
	return (stack);
}

t_list	*after(t_list *stack, t_list *node)
{
	if (stack == node)
		return (NULL);
	while (stack != NULL && stack->val != node->val)
		stack = stack->next;
	if (stack != NULL)
		stack = stack->next;
	return (stack);
}
