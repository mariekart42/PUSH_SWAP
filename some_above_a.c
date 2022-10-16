/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_above_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:11:01 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/16 10:15:29 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_tmp_b_start(t_holder *l_hold)
{
	if (l_hold->b_start != NULL \
		&& l_hold->b != place(l_hold->b, l_last(l_hold->b_start)) \
		&& l_hold->b != place(l_hold->b, l_last(l_hold->tmp_b_start)))
	{
		if (l_hold->tmp_b_start == NULL)
			l_hold->tmp_b_start = new_node((l_hold->b)->val);
		else
			(l_last(l_hold->tmp_b_start))->next = new_node((l_hold->b)->val);
	}
}

bool	decider_hc_above_a(t_holder *l_hold)
{
	if (range(l_hold->a, l_hold->a, l_last(l_hold->a_start)) < 6)
	{
		hardcode_func(&l_hold->a, &l_hold->b, l_last(l_hold->a_start));
		(l_last(l_hold->a_start))->next = new_node((l_hold->a)->val);
		return (true);
	}
	else
		return (false);
}

void	some_above_a(t_holder *l_hold)
{
	int		pivot;
	t_list	*temp_a;

	pivot = 0;
	temp_a = l_hold->a;
	if (decider_hc_above_a(l_hold) == true)
		return ;
	update_tmp_b_start(l_hold);
	pivot = perfect_pivot(l_hold->a, l_last(l_hold->a_start));
	while (temp_a->val != (l_last(l_hold->a_start))->val)
	{
		if (temp_a->val >= pivot)
		{
			temp_a = temp_a->next;
			ra(&l_hold->a, true);
		}
		else if (temp_a->val < pivot)
		{
			temp_a = temp_a->next;
			pb(&l_hold->a, &l_hold->b);
			if (l_hold->b_start == NULL)
				l_hold->b_start = new_node((l_hold->b)->val);
		}
	}
}
