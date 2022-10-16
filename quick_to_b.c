/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:17:52 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/16 13:09:14 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	quick_to_b(t_holder *l_hold)
{
	t_list	l;

	l.guard = 999999999999;
	if (list_len(l_hold->a) == 5)
		return (hc_quick_5(&l_hold->a, &l_hold->b));
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
