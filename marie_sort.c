/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marie_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:06 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/15 14:45:30 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	marie_sort(t_holder *l_hold, t_list *list)
{
	list->last_a = l_last(l_hold->a);
	while ((stack_sorted(&l_hold->a) == false) || (list_len(l_hold->b) != 0))
	{
		if ((l_hold->a)->val != last_node_content(l_hold->a_start))
			some_above_a(l_hold);
		else if (l_last(l_hold->a) != list->last_a)
			some_under_a(l_hold, list);
		else if (l_hold->b_start == NULL && list_len(l_hold->b) != 0)
			b_start_empty(l_hold);
		else if (l_hold->b->val != last_node_content(l_hold->b_start) \
		&& !(l_hold->b_start != NULL \
		&& after(l_hold->b, l_hold->b_start) != NULL \
		&& (l_hold->b)->val < last_node_content(l_hold->b)))
			some_above_b(l_hold, list);
		else if ((l_hold->b_start)->val != (l_last(l_hold->b))->val)
			some_under_b(l_hold, list);
		else
			del_last(&l_hold->b_start);
	}
}
