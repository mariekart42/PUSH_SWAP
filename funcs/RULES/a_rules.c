/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:01:44 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/25 14:09:21 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

// swap first 2 elements of stack a
// Do nothing if there is only one or no element in a
void	sa(t_list **a, bool output)
{
	t_list	*head;

	head = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->next;
	head->next = (*a)->next;
	(*a)->next = head;
	if (output == true)
		write(1, "sa\n", 3);
	else
		write(1, "ss\n", 3);
}

// first element of stack b to top of stack a
// first element of stack a gets removed!
// Do nothing if b is empty
void	pa(t_list **a, t_list **b)
{
	t_list	*head;
	t_list	*prev_content;

	head = *b;
	prev_content = *a;
	if (*b == NULL)
		return ;
	*b = (*b)->next;
	*a = head;
	(*a)->next = prev_content;
	write(1, "pa\n", 3);
}

// Shift up all elements of stack a by 1
// The first element becomes the last one
void	ra(t_list **a, bool output)
{
	t_list	*temp;
	t_list	*first_node;

	temp = *a;
	first_node = *a;
	if ((*a)->next == NULL)
		return ;
	*a = (*a)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first_node;
	first_node->next = NULL;
	if (output == true)
		write(1, "ra\n", 3);
	else
		write(1, "rr\n", 3);
}

// shift down all elements of stack a by 1
// the last element becomes the first one
void	rra(t_list **a, bool output)
{
	t_list	*head;
	t_list	*second_last;

	second_last = *a;
	head = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while ((*a)->next->next != NULL)
		*a = (*a)->next;
	second_last = *a;
	*a = (*a)->next;
	second_last->next = NULL;
	(*a)->next = head;
	if (output == true)
		write(1, "rra\n", 4);
	else
		write(1, "rrr\n", 4);
}
