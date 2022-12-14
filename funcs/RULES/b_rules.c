/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:03:19 by mmensing          #+#    #+#             */
/*   Updated: 2022/12/14 13:04:08 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/push_swap.h"

// swap first 2 elements of stack b
// Do nothing if there is only one or no elements
void	sb(t_list **b, bool output)
{
	t_list	*head;

	head = *b;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	*b = (*b)->next;
	head->next = (*b)->next;
	(*b)->next = head;
	if (output == true)
		write(1, "sa\n", 3);
	else
		write(1, "ss\n", 3);
}

// first element of stack a to stack b
// first element of stack b gets removed!
// Do nothing if a is empty
void	pb(t_list **a, t_list **b)
{
	t_list	*head;
	t_list	*prev_content;

	head = *a;
	prev_content = *b;
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	*b = head;
	(*b)->next = prev_content;
	write(1, "pb\n", 3);
}

// Shift up all elements of stack b by 1
// The first element becomes the last one
void	rb(t_list **b, bool output)
{
	t_list	*temp;
	t_list	*first_node;

	temp = *b;
	first_node = *b;
	if ((*b)->next == NULL)
		return ;
	*b = (*b)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first_node;
	first_node->next = NULL;
	if (output == true)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
}

// shift down all elements of stack b by 1
// the last element becomes the first one
void	rrb(t_list **b, bool output)
{
	t_list	*head;
	t_list	*second_last;

	second_last = *b;
	head = *b;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while ((*b)->next->next != NULL)
		*b = (*b)->next;
	second_last = *b;
	*b = (*b)->next;
	second_last->next = NULL;
	(*b)->next = head;
	if (output == true)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}
