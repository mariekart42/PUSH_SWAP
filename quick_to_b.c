/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:17:52 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/15 14:18:17 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hc_quick(t_holder *l_hold)
{
	if (list_len(l_hold->a) == 3)
		hc_quick_3(&l_hold->a);
	else if (list_len(l_hold->a) == 4)
		hc_quick_4(&l_hold->a, l_hold);
	else if (list_len(l_hold->a) == 2 \
	&& ((l_hold->a)->val > (l_hold->a)->next->val))
		ra(&l_hold->a, true);
}

// algo for only 3 digits -> max 2 rules! works
void	hc_quick_3(t_list **node)
{
	while ((*node)->val > ((*node)->next->next)->val)
		ra(node, true);
	if (((*node)->next->next)->val < ((*node)->next)->val)
		rra(node, true);
	if ((*node)->val > ((*node)->next)->val)
		sa(node, true);
}

void	hc_quick_4(t_list **node, t_holder*l_hold)
{
	t_list	*temp;
	int		smallest_val;

	temp = *node;
	smallest_val = temp->val;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->val < smallest_val)
			smallest_val = temp->val;
		temp = temp->next;
	}
	free(temp);
	if ((*node)->next->val == smallest_val)
		sa(node, true);
	else if ((*node)->next->next->val == smallest_val)
	{
		rra(node, true);
		rra(node, true);
	}
	else if ((*node)->next->next->next->val == smallest_val)
		rra(node, true);
	pb(node, &l_hold->b);
	hc_quick_3(node);
	pa(node, &l_hold->b);
}

void	quick_to_b(t_holder *l_hold)
{
	t_list	l;

	l.guard = 999999999999;
	while (list_len(l_hold->a) > 4)
	{
		l.pivot = perfect_pivot(l_hold->a, NULL);
		quick_to_b_algo(l_hold, l.guard, l.pivot);
		l.guard = 999999999999;
		if (l_hold->b_start == NULL)
			l_hold->b_start = new_node((l_last(l_hold->b))->val);
		(l_last(l_hold->b_start))->next = new_node((l_hold->b)->val);
	}
	hc_quick(l_hold);
	l_hold->a_start = new_node((l_last(l_hold->a))->val);
	(l_hold->a_start)->next = new_node((l_hold->a)->val);
	del_last(&l_hold->b_start);
}

void	quick_to_b_algo(t_holder *l_hold, int64_t guard, int32_t pivot)
{
	t_list	*temp_a;

	temp_a = l_hold->a;
	while (temp_a->next != NULL)
	{	
		if (pivot >= temp_a->val)
		{
			temp_a = temp_a->next;
			pb(&l_hold->a, &l_hold->b);
		}
		else if (pivot < temp_a->val)
		{
			if (guard == temp_a->val)
				break ;
			if (guard == 999999999999)
				guard = temp_a->val;
			temp_a = temp_a->next;
			ra(&l_hold->a, true);
		}
	}
}
