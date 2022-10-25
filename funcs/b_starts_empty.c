/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_starts_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:53:59 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/25 13:52:31 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

bool	decider_push_to_a_b_starts_empty(t_holder *l_hold)
{
	if ((l_hold->b_down == NULL \
	&& range(l_hold->b, l_hold->b, l_last(l_hold->b)) <= 4))
	{
		if (l_hold->b_down == NULL)
			push_to_a("make_b_empty", l_hold->b, NULL, l_hold);
		else if (l_hold->b_down != NULL)
			push_to_a("under_b", place(l_hold->b, l_last(l_hold->b_down)), \
			NULL, l_hold);
		del_last(&l_hold->b_down);
		return (true);
	}
	else if (l_hold->b_down != NULL && range(l_hold->b, \
	(place(l_hold->b, l_last(l_hold->b_down)))->next, l_last(l_hold->b)) <= 4)
	{
		if (l_hold->b_down == NULL)
			push_to_a("make_b_empty", l_hold->b, NULL, l_hold);
		else if (l_hold->b_down != NULL)
			push_to_a("under_b", place(l_hold->b, l_last(l_hold->b_down)), \
			NULL, l_hold);
		del_last(&l_hold->b_down);
		return (true);
	}
	else
		return (false);
}

int32_t	decider_pivot(t_holder *l_hold)
{
	if (l_hold->b_down == NULL)
		return (perfect_pivot(l_hold->b, NULL));
	else
		return (perfect_pivot(place(l_hold->b, \
		(l_last(l_hold->b_down)))->next, NULL));
}

int32_t	decider_len(t_holder *l_hold)
{
	if (l_hold->b_down == NULL)
		return (range(l_hold->b, l_hold->b, l_last(l_hold->b)));
	else
		return (range(l_hold->b, l_last(l_hold->b_down), \
		l_last(l_hold->b)) - 1);
}

void	b_start_empty(t_holder *l_hold)
{
	int		pivot;
	t_list	*temp_b;
	int		len;

	pivot = 0;
	temp_b = NULL;
	len = 0;
	if (decider_push_to_a(l_hold) == true)
		return ;
	pivot = decider_pivot(l_hold);
	len = decider_len(l_hold);
	if (l_hold->b_down == NULL)
		temp_b = l_hold->b;
	else if (l_hold->b_down != NULL)
		temp_b = (l_last(l_hold->b_down))->next;
	while (len > 0)
	{
		rrb(&l_hold->b, true);
		if ((l_hold->b)->val > pivot)
			pa(&l_hold->a, &l_hold->b);
		else if (l_hold->b_start == NULL)
			l_hold->b_start = new_node((l_hold->b)->val);
		len--;
	}
	del_last(&l_hold->b_down);
}
