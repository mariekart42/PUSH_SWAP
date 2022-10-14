/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marie_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:06 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/14 15:59:04 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void marie_sort(t_holder *l_hold)
{
	t_list  *last_a;

	last_a = lst_last(l_hold->a);
	while ((stack_sorted(&l_hold->a) == false) || (list_len(l_hold->b) != 0))
	{
		if ((l_hold->a)->val != last_node_content(l_hold->a_start) && lst_last(l_hold->a) != last_a)
			special_case(&l_hold->a, &l_hold->b, last_a, &l_hold->tmp_b_start, &l_hold->b_start);
		else if ((l_hold->a)->val != last_node_content(l_hold->a_start))
			some_above_a(l_hold);
		else if (lst_last(l_hold->a) != last_a)
		{
			if (range(l_hold->a, last_a->next, lst_last(l_hold->a)) <= 4)
				push_all_to_a("under_a", place(l_hold->a, l_hold->a_start), NULL, &l_hold->a, &l_hold->b);
			else
				some_under_a(l_hold);
		}
		else if (l_hold->b_start == NULL && list_len(l_hold->b) != 0)
			b_start_empty(l_hold);
		else if (l_hold->b->val != last_node_content(l_hold->b_start) && !(l_hold->b_start != NULL && after(l_hold->b, l_hold->b_start) != NULL && (l_hold->b)->val < last_node_content(l_hold->b)))
			some_above_b(l_hold);
		else if ((l_hold->b_start)->val != (lst_last(l_hold->b))->val)
			some_under_b(l_hold);
		else 
			del_last(&l_hold->b_start);
	}
}

void b_start_empty(t_holder *l_hold)
{
	int pivot = 0;
	t_list *temp_b = NULL;

	if ((l_hold->b_down == NULL && range(l_hold->b, l_hold->b, lst_last(l_hold->b)) <= 4))
	{
		if (l_hold->b_down == NULL)
			push_all_to_a("make_b_empty", l_hold->b, NULL, &l_hold->a, &l_hold->b);
		else if (l_hold->b_down != NULL)
			push_all_to_a("under_b", place(l_hold->b, lst_last(l_hold->b_down)), NULL, &l_hold->a, &l_hold->b);
		del_last(&l_hold->b_down);
		return ;
	}
	else if (l_hold->b_down != NULL && range(l_hold->b, (place(l_hold->b, lst_last(l_hold->b_down)))->next, lst_last(l_hold->b)) <= 4)
	{
		if (l_hold->b_down == NULL)
			push_all_to_a("make_b_empty", l_hold->b, NULL, &l_hold->a, &l_hold->b);
		else if (l_hold->b_down != NULL)
			push_all_to_a("under_b", place(l_hold->b, lst_last(l_hold->b_down)), NULL, &l_hold->a, &l_hold->b);
		del_last(&l_hold->b_down);
		return ;
		
	}
	int len = 0;
	if (l_hold->b_down == NULL)
	{
		pivot = perfect_pivot(l_hold->b, NULL);
		temp_b = l_hold->b;
		len = range(l_hold->b, l_hold->b, lst_last(l_hold->b));
	}
	else if (l_hold->b_down != NULL)
	{
		pivot = perfect_pivot(place(l_hold->b, (lst_last(l_hold->b_down)))->next, NULL);
		temp_b = (lst_last(l_hold->b_down))->next;
		len = range(l_hold->b, lst_last(l_hold->b_down), lst_last(l_hold->b)) - 1;
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


void some_above_a(t_holder *l_hold)
{    
	int pivot = 0;
	if (range(l_hold->a, l_hold->a, lst_last(l_hold->a_start)) < 6)
	{
		hardcode_func(&l_hold->a, &l_hold->b, lst_last(l_hold->a_start));
		(lst_last(l_hold->a_start))->next = new_node((l_hold->a)->val); 
		return ;
	}
	t_list *temp_a = l_hold->a;

	if (l_hold->b_start != NULL && l_hold->b != place(l_hold->b, lst_last(l_hold->b_start)) && l_hold->b != place(l_hold->b, lst_last(l_hold->tmp_b_start)))
	{
		if (l_hold->tmp_b_start == NULL)
			l_hold->tmp_b_start = new_node((l_hold->b)->val);
		else
			(lst_last(l_hold->tmp_b_start))->next = new_node((l_hold->b)->val);
	}
	pivot = perfect_pivot(l_hold->a, lst_last(l_hold->a_start));
	while (temp_a->val != (lst_last(l_hold->a_start))->val)
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


void some_under_a(t_holder *l_hold)
{
	int pivot = 0;
	t_list *temp_a = place(l_hold->a, l_hold->a_start);

	if (l_hold->b != lst_last(l_hold->b_start) || l_hold->b != lst_last(l_hold->tmp_b_start))
	{
		if (l_hold->tmp_b_start == NULL)
			l_hold->tmp_b_start = new_node((l_hold->b)->val);
		else
			(lst_last(l_hold->tmp_b_start))->next = new_node((l_hold->b)->val);
	}
	pivot = perfect_pivot((place(l_hold->a, l_hold->a_start))->next, NULL);
	while (temp_a->next != NULL)
	{
		rra(&l_hold->a, true);
		if ((l_hold->a)->val < pivot)
			pb(&l_hold->a, &l_hold->b);
	}
}


void some_above_b(t_holder *l_hold)
{
	int pivot = 0;

	if ((l_hold->tmp_b_start != NULL) && (range(l_hold->b, l_hold->b, prev(l_hold->b, lst_last(l_hold->tmp_b_start))) <= 4))
	{
		push_all_to_a("above_b", l_hold->b, place(l_hold->b, lst_last(l_hold->tmp_b_start)), &l_hold->a, &l_hold->b);
		del_last(&l_hold->tmp_b_start);
		return ;
	}
	else if ((list_len(l_hold->b_start) > 1 && range(l_hold->b, l_hold->b, lst_last(l_hold->b_start)) <= 5) || (list_len(l_hold->b_start) == 1 && range(l_hold->b, l_hold->b, lst_last(l_hold->b_start)) <= 4))
	{
		push_all_to_a("above_b", l_hold->b, place(l_hold->b, lst_last(l_hold->b_start)), &l_hold->a, &l_hold->b);
		if ((l_hold->b)->val == (l_hold->b_start)->val)
		{
			pa(&l_hold->a, &l_hold->b);
			del_last(&l_hold->b_start);
		}
		return ;
	}
	if ((l_hold->b_start)->val != (lst_last(l_hold->b))->val)
	{
		if (l_hold->b_down == NULL)
			l_hold->b_down = new_node(last_node_content(l_hold->b));
		else
			(lst_last(l_hold->b_down))->next = new_node(last_node_content(l_hold->b));
	}
	t_list *temp_b = l_hold->b;

	if (l_hold->tmp_b_start != NULL)
		pivot = perfect_pivot(l_hold->b, lst_last(l_hold->tmp_b_start));
	else if (list_len(l_hold->b_start) == 1)
		pivot = perfect_pivot(l_hold->b, (place(l_hold->b, lst_last(l_hold->b_start)))->next);
	else
		pivot = perfect_pivot(l_hold->b, lst_last(l_hold->b_start));

	while (temp_b != NULL && temp_b->val != lst_last(l_hold->b_start)->val)
	{
		if (l_hold->tmp_b_start != NULL && temp_b->val == lst_last(l_hold->tmp_b_start)->val)
			break ;
		if (temp_b->val >= pivot)
		{
			temp_b = temp_b->next;
			pa(&l_hold->a, &l_hold->b);
		}
		else if (temp_b->val < pivot)
		{
			temp_b = temp_b->next;
			rb(&l_hold->b, true);
		}
	}
	if (temp_b->val == (l_hold->b_start)->val)
	{
		del_last(&l_hold->b_start);
		if (temp_b->val > pivot)
			pa(&l_hold->a, &l_hold->b);
		else
			rb(&l_hold->b, true);
	}
	del_last(&l_hold->tmp_b_start);
}

void some_under_b(t_holder *l_hold)
{
	t_list *temp_b = NULL;
	int pivot = 0;

	if (l_hold->b_down != NULL && range(l_hold->b, lst_last(l_hold->b_down), lst_last(l_hold->b)) <= 5)
	{
		push_all_to_a("under_b", place(l_hold->b, lst_last(l_hold->b_down)), NULL, &l_hold->a, &l_hold->b);
		del_last(&l_hold->b_down);
		return ;
	}
	else if (l_hold->b_down == NULL && l_hold->b_start!= NULL && range(l_hold->b, place(l_hold->b, l_hold->b_start)->next, lst_last(l_hold->b)) < 5)
	{
		push_all_to_a("under_b", place(l_hold->b, l_hold->b_start), NULL, &l_hold->a, &l_hold->b);
		return ;
	}
	if (l_hold->b_down == NULL)
	{
		pivot = perfect_pivot((place(l_hold->b, l_hold->b_start))->next, NULL);
		temp_b = (place(l_hold->b, l_hold->b_start))->next;
	}
	else if (l_hold->b_down != NULL)
	{
		pivot = perfect_pivot((place(l_hold->b, lst_last(l_hold->b_down)))->next, NULL);
		temp_b = (place(l_hold->b, lst_last(l_hold->b_down)))->next;
	}
	if (l_hold->tmp_b_start == NULL)
		l_hold->tmp_b_start = new_node((l_hold->b)->val);
	else 
		(lst_last(l_hold->tmp_b_start))->next = new_node((l_hold->b)->val);
	while (temp_b->next != NULL)
		rrb(&l_hold->b, true);
	rrb(&l_hold->b, true);
	del_last(&l_hold->b_down);
}

void quick_to_b(t_holder *l_hold)
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
			l_hold->b_start = new_node((lst_last(l_hold->b))->val);
		(lst_last(l_hold->b_start))->next = new_node((l_hold->b)->val);
	}
	hc_quick(l_hold);
	l_hold->a_start = new_node((lst_last(l_hold->a))->val);
	(l_hold->a_start)->next = new_node((l_hold->a)->val);
	del_last(&l_hold->b_start);
}
