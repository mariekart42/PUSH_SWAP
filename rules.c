/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:35:35 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/08 12:37:33 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/**
 * @brief	Swap the first 2 elements at the top of stack a
 *			Do nothing if there is only one or no elements.
 * @param head root of stack_a
 * @return Node* swaped elements
 */
stack_a *sa(stack_a *head)
{
	int temp = 0;
	if(list_len(head) < 2)
		return(NULL);
	//printf("before:\npos 1: %d\npos 2: %d\npos 3: %d\n\n", head->value, head->next->value, head->next->next->value);
	temp = head->next->val_a;
	head->next->val_a = head->val_a;
	head->val_a = temp;
	//printf("after:\npos 1: %d\npos 2: %d\npos 3: %d\n\n", head->value, head->next->value, head->next->next->value);	
	return(head);
}

stack_b *sb(stack_b *head)
{
	
}

