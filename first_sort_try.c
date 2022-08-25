/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_try.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 23:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/26 00:42:58 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void first_sort_try(l_list **stack_a, l_list **stack_b)
{
	l_list *temp = NULL;
	l_list *stay = NULL;
	
	temp = *stack_a;
	stay = *stack_a;
	while(temp->next != NULL)
	{
		if(temp->next->val < temp->val)
		{
			sa(stack_a);
		}
		else
		{
			pb(stack_a, stack_b);
		}
		temp = temp->next;
	}
}
