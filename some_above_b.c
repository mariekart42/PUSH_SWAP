/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_above_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:33:48 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/14 18:15:31 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	decider_push_to_a(t_holder *l_hold)
{
	if ((l_hold->tmp_b_start != NULL) && (range(l_hold->b, l_hold->b, \
		prev(l_hold->b, l_last(l_hold->tmp_b_start))) <= 4))
	{
		push_to_a("above_b", l_hold->b, place(l_hold->b, \
			l_last(l_hold->tmp_b_start)), &l_hold->a, &l_hold->b);
		del_last(&l_hold->tmp_b_start);
		return (true);
	}
	else if ((list_len(l_hold->b_start) > 1 \
		&& range(l_hold->b, l_hold->b, l_last(l_hold->b_start)) <= 5) \
		|| (list_len(l_hold->b_start) == 1 \
		&& range(l_hold->b, l_hold->b, l_last(l_hold->b_start)) <= 4))
	{
		push_to_a("above_b", l_hold->b, \
			place(l_hold->b, l_last(l_hold->b_start)), &l_hold->a, &l_hold->b);
		if ((l_hold->b)->val == (l_hold->b_start)->val)
		{
			pa(&l_hold->a, &l_hold->b);
			del_last(&l_hold->b_start);
		}
		return (true);
	}
	else
		return (false);
}

int	decider_pivot_above_b(t_holder *l_hold)
{
	if (l_hold->tmp_b_start != NULL)
		return (perfect_pivot(l_hold->b, l_last(l_hold->tmp_b_start)));
	else if (list_len(l_hold->b_start) == 1)
		return (perfect_pivot(l_hold->b, (place(l_hold->b, \
				l_last(l_hold->b_start)))->next));
	else
		return (perfect_pivot(l_hold->b, l_last(l_hold->b_start)));
}	

void update_b_down(t_holder *l_hold)
{
	if ((l_hold->b_start)->val != (l_last(l_hold->b))->val)
	{
		if (l_hold->b_down == NULL)
			l_hold->b_down = new_node(last_node_content(l_hold->b));
		else
			(l_last(l_hold->b_down))->next \
				= new_node(last_node_content(l_hold->b));
	}
}

void end_of_b_start(t_holder *l_hold, int temp_b_val, int pivot)
{
	if (temp_b_val == (l_hold->b_start)->val)
	{
		del_last(&l_hold->b_start);
		if (temp_b_val > pivot)
			pa(&l_hold->a, &l_hold->b);
		else
			rb(&l_hold->b, true);
	}
}

void	some_above_b(t_holder *l_hold, t_list *l)
{
	t_list	*temp_b;

	temp_b = l_hold->b;
	if (decider_push_to_a(l_hold) == true)
		return ;
	update_b_down(l_hold);
	l->pivot = decider_pivot_above_b(l_hold);
	while (temp_b != NULL && temp_b->val != l_last(l_hold->b_start)->val)
	{
		if (l_hold->tmp_b_start != NULL \
			&& temp_b->val == l_last(l_hold->tmp_b_start)->val)
			break ;
		if (temp_b->val >= l->pivot)
		{
			temp_b = temp_b->next;
			pa(&l_hold->a, &l_hold->b);
		}
		else if (temp_b->val < l->pivot)
		{
			temp_b = temp_b->next;
			rb(&l_hold->b, true);
		}
	}
	end_of_b_start(l_hold, temp_b->val, l->pivot);
	del_last(&l_hold->tmp_b_start);
}
