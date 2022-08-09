/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:43:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/09 21:24:43 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// swap first 2 elements of stack a
void sa(l_list *stack_a)
{
	int temp = 0;
	if (list_len(stack_a) < 2)
		return;
	temp = stack_a->next->val;
	stack_a->next->val = stack_a->val;
	stack_a->val = temp;
}

// swap first 2 elements of stack b
void sb(l_list *stack_b)
{
	int temp = 0;
	if (list_len(stack_b) < 2)
		return;
	temp = stack_b->next->val;
	stack_b->next->val = stack_b->val;
	stack_b->val = temp;
}

// rule sa and sb at the same time
void ss(l_list *stack_a, l_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

// first element of stack b to stack a
void pa(l_list *stack_a, l_list *stack_b)
{
	int temp = 0;
	l_list *temp_a = NULL;
	if (stack_b == NULL) // if stack_b is empty
		return ;
	temp = stack_b->val;
	
	stack_b = stack_b->next;
	printf("stack_b->next->val: %d\n", stack_b->val);
	temp_a = stack_a;
	temp_a = new_node(temp);
	stack_a->next = stack_a;
}
// the swap is not working correctly!!

