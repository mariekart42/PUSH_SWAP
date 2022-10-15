/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:33:47 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/15 16:38:19 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t	list_len(t_list *head)
{
	int32_t	len;

	len = 0;
	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		len++;
		head = head->next;
	}
	return (len + 1);
}

int32_t	last_node_content(t_list *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head->val);
}

// function calculates the amount of nodes(including end)
int32_t	range(t_list *stack, t_list *begin, t_list *end)
{
	int	count;

	count = 1;
	while (stack->val != begin->val)
		stack = stack->next;
	while (stack->val != end->val)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

// checks if th stack is sorted
bool	stack_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->val > temp->next->val)
			return (false);
		temp = temp->next;
	}
	return (true);
}
