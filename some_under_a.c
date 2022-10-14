/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_under_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:32:11 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/14 17:38:37 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	some_under_a(t_holder *l_hold)
{
	int		pivot;
	t_list	*temp_a;

	pivot = 0;
	temp_a = place(l_hold->a, l_hold->a_start);
	if (l_hold->b != l_last(l_hold->b_start) \
		|| l_hold->b != l_last(l_hold->tmp_b_start))
	{
		if (l_hold->tmp_b_start == NULL)
			l_hold->tmp_b_start = new_node((l_hold->b)->val);
		else
			(l_last(l_hold->tmp_b_start))->next = new_node((l_hold->b)->val);
	}
	pivot = perfect_pivot((place(l_hold->a, l_hold->a_start))->next, NULL);
	while (temp_a->next != NULL)
	{
		rra(&l_hold->a, true);
		if ((l_hold->a)->val < pivot)
			pb(&l_hold->a, &l_hold->b);
	}
}