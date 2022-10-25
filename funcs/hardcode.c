/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:48:48 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/25 13:54:52 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

void	hardcode_func(t_list**a, t_list **b, t_list *end)
{
	int		len;
	t_list	*temp;

	len = 0;
	temp = *a;
	while (temp->val != end->val)
	{
		temp = temp->next;
		len++;
	}
	if (len == 2)
	{
		if ((*a)->val > (*a)->next->val)
			sa(a, true);
	}
	else if (len == 3)
		hc_three(a);
	else if (len == 4)
		hc_four(a, b);
}

void	hc_three(t_list **a)
{
	if ((*a)->next->next->val < (*a)->val \
	|| (*a)->next->next->val < (*a)->next->val)
	{
		if ((*a)->val > (*a)->next->val)
			sa(a, true);
		ra(a, true);
		if ((*a)->val > (*a)->next->val)
			sa(a, true);
		rra(a, true);
		if ((*a)->val > (*a)->next->val)
			sa(a, true);
	}
	else if ((*a)->val > (*a)->next->val)
		sa(a, true);
}

// function returns the fist found number that is smollest or second smollest
int	smol(t_list *a)
{
	t_list	*temp;

	temp = a;
	if ((temp->val < a->next->next->next->val \
	&& temp->val < a->next->val) \
	|| (temp->val < a->next->next->next->val \
	&& temp->val < a->next->next->val) \
	|| (temp->val < a->next->next->val \
	&& temp->val < a->next->val))
		return (temp->val);
	else if ((temp->next->val < a->next->next->val \
	&& temp->next->val < a->val) \
	|| (temp->next->val < a->next->next->next->val \
	&& temp->next->val < a->val))
		return (temp->next->val);
	else
		return (temp->next->next->val);
}

void	hc_four(t_list **a, t_list **b)
{
	int	smolst_int;

	smolst_int = smol(*a);
	if ((*a)->next->next->val == smolst_int)
	{
		ra(a, true);
		sa(a, true);
		rra(a, true);
		sa(a, true);
		ra(a, true);
	}
	else if ((*a)->next->val == smolst_int)
	{
		sa(a, true);
		ra(a, true);
	}
	else if ((*a)->val == smolst_int)
		ra(a, true);
	hc_three(a);
	rra(a, b);
	if ((*a)->val > (*a)->next->val)
		sa(a, true);
}
