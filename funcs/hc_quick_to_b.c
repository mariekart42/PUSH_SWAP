/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hc_quick_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:32:47 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/25 13:54:56 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	hc_quick(t_holder *l_hold)
{
	if (stack_sorted(&l_hold->a))
		return ;
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
	free_((void **)&temp);
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

void	hc_quick_5(t_list **a, t_list **b)
{
	int	pivot;
	int	i;

	pivot = perfect_pivot(*a, NULL);
	i = 1;
	while (list_len(*b) != 2)
	{
		if ((*a)->val < pivot)
			pb(a, b);
		else
			ra(a, true);
	}
	if ((*b)->val < (*b)->next->val)
		rb(b, true);
	hc_quick_3(a);
	pa(a, b);
	pa(a, b);
}
