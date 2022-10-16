/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_under_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:32:11 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/16 10:15:47 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	some_under_a(t_holder *l_hold, t_list *l)
{
	t_list	*temp_a;

	temp_a = place(l_hold->a, l_hold->a_start);
	if (range(l_hold->a, l->last_a->next, l_last(l_hold->a)) <= 4)
	{
		push_to_a("under_a", place(l_hold->a, l_hold->a_start), NULL, \
			l_hold);
		return ;
	}
	if (l_hold->b != l_last(l_hold->b_start) \
		|| l_hold->b != l_last(l_hold->tmp_b_start))
	{
		if (l_hold->tmp_b_start == NULL)
			l_hold->tmp_b_start = new_node((l_hold->b)->val);
		else
			(l_last(l_hold->tmp_b_start))->next = new_node((l_hold->b)->val);
	}
	l->pivot = perfect_pivot((place(l_hold->a, l_hold->a_start))->next, NULL);
	while (temp_a->next != NULL)
	{
		rra(&l_hold->a, true);
		if ((l_hold->a)->val < l->pivot)
			pb(&l_hold->a, &l_hold->b);
	}
}
