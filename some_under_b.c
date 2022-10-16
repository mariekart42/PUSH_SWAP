/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_under_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:23:50 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/16 10:16:00 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decider_pivot_under_b(t_holder *l_hold)
{
	if (l_hold->b_down == NULL)
		return (perfect_pivot((place(l_hold->b, l_hold->b_start))->next, NULL));
	else
		return (perfect_pivot((place(l_hold->b, \
			l_last(l_hold->b_down)))->next, NULL));
}

t_list	*decider_temp_b_under_b(t_holder *l_hold)
{
	if (l_hold->b_down == NULL)
		return ((place(l_hold->b, l_hold->b_start))->next);
	else
		return ((place(l_hold->b, l_last(l_hold->b_down)))->next);
}

bool	decider_push_to_a_under_b(t_holder *l_hold)
{
	if (l_hold->b_down != NULL && range(l_hold->b, l_last(l_hold->b_down), \
		l_last(l_hold->b)) <= 5)
	{
		push_to_a("under_b", place(l_hold->b, l_last(l_hold->b_down)), \
			NULL, l_hold);
		del_last(&l_hold->b_down);
		return (true);
	}
	else if (range(l_hold->b, place(l_hold->b, l_hold->b_start)->next, \
	l_last(l_hold->b)) < 5 && l_hold->b_down == NULL && l_hold->b_start != NULL)
	{
		push_to_a("under_b", place(l_hold->b, l_hold->b_start), \
		NULL, l_hold);
		return (true);
	}
	else
		return (false);
}

void	some_under_b(t_holder *l_hold, t_list *l)
{
	t_list	*temp_b;

	temp_b = NULL;
	if (decider_push_to_a_under_b(l_hold) == true)
		return ;
	l->pivot = decider_pivot_under_b(l_hold);
	temp_b = decider_temp_b_under_b(l_hold);
	if (l_hold->tmp_b_start == NULL)
		l_hold->tmp_b_start = new_node((l_hold->b)->val);
	else
		(l_last(l_hold->tmp_b_start))->next = new_node((l_hold->b)->val);
	while (temp_b->next != NULL)
		rrb(&l_hold->b, true);
	rrb(&l_hold->b, true);
	del_last(&l_hold->b_down);
}
