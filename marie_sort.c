/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marie_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:06 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/14 18:49:06 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	marie_sort(t_holder *l_hold, t_list *list)
{
	list->last_a = l_last(l_hold->a);
	while ((stack_sorted(&l_hold->a) == false) || (list_len(l_hold->b) != 0))
	{
		if ((l_hold->a)->val != last_node_content(l_hold->a_start) \
		&& l_last(l_hold->a) != list->last_a)
			special_case(&l_hold->a, &l_hold->b, list->last_a, \
			&l_hold->tmp_b_start, &l_hold->b_start);
		else if ((l_hold->a)->val != last_node_content(l_hold->a_start))
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

void b_start_empty(t_holder *l_hold)
{
	int pivot = 0;
	t_list *temp_b = NULL;

	if ((l_hold->b_down == NULL && range(l_hold->b, l_hold->b, l_last(l_hold->b)) <= 4))
	{
		if (l_hold->b_down == NULL)
			push_to_a("make_b_empty", l_hold->b, NULL, &l_hold->a, &l_hold->b);
		else if (l_hold->b_down != NULL)
			push_to_a("under_b", place(l_hold->b, l_last(l_hold->b_down)), NULL, &l_hold->a, &l_hold->b);
		del_last(&l_hold->b_down);
		return ;
	}
	else if (l_hold->b_down != NULL && range(l_hold->b, (place(l_hold->b, l_last(l_hold->b_down)))->next, l_last(l_hold->b)) <= 4)
	{
		if (l_hold->b_down == NULL)
			push_to_a("make_b_empty", l_hold->b, NULL, &l_hold->a, &l_hold->b);
		else if (l_hold->b_down != NULL)
			push_to_a("under_b", place(l_hold->b, l_last(l_hold->b_down)), NULL, &l_hold->a, &l_hold->b);
		del_last(&l_hold->b_down);
		return ;
		
	}
	int len = 0;
	if (l_hold->b_down == NULL)
	{
		pivot = perfect_pivot(l_hold->b, NULL);
		temp_b = l_hold->b;
		len = range(l_hold->b, l_hold->b, l_last(l_hold->b));
	}
	else if (l_hold->b_down != NULL)
	{
		pivot = perfect_pivot(place(l_hold->b, (l_last(l_hold->b_down)))->next, NULL);
		temp_b = (l_last(l_hold->b_down))->next;
		len = range(l_hold->b, l_last(l_hold->b_down), l_last(l_hold->b)) - 1;
	}

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

void	quick_to_b(t_holder *l_hold)
{
	t_list	l;
	t_list	*temp_a;

	l.guard = 999999999999;
	temp_a = l_hold->a;
	while (list_len(l_hold->a) > 4)
	{
		l.pivot = perfect_pivot(l_hold->a, NULL);
		while (temp_a->next != NULL)
		{
			if (l.pivot >= temp_a->val)
			{
				temp_a = temp_a->next;
				pb(&l_hold->a, &l_hold->b);
			}
			else if (l.pivot < temp_a->val)
			{
				if (l.guard == temp_a->val)
					break ;
				if (l.guard == 999999999999)
					l.guard = temp_a->val;
				temp_a = temp_a->next;
				ra(&l_hold->a, true);
			}
		}
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
