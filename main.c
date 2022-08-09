/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/09 21:20:36 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking for valid arguments
// -> no duplicates
// -> nothing else than numbers
// -> integer max/min

int main(int argc, char *argv[])
{
	l_list *stack_a = NULL;
	l_list *stack_b = NULL;
	stack_a = create_list(argc, argv);
	int array[4] = {4, 2, 0, 4};
	stack_b = create_list_alone(argc, array);
	printf("list_len_a: %d\n", list_len(stack_a));
	printf("list_len_b: %d\n", list_len(stack_b));
	printf("BEFORE_a:\npos 1: %d\npos 1: %d\npos 1: %d\npos 1: %d\n\n", stack_a->val, stack_a->next->val, stack_a->next->next->val, stack_a->next->next->next->val);
	printf("BEFORE:_b\npos 1: %d\npos 1: %d\npos 1: %d\npos 1: %d\n\n", stack_b->val, stack_b->next->val, stack_b->next->next->val, stack_b->next->next->next->val);
	pa(stack_a, stack_b);
	printf("AFTER_a:\npos 1: %d\npos 1: %d\npos 1: %d\npos 1: %d\n\n", stack_a->val, stack_a->next->val, stack_a->next->next->val, stack_a->next->next->next->val);
	printf("AFTER_b:\npos 1: %d\npos 1: %d\npos 1: %d\npos 1: %d\n\n", stack_b->val, stack_b->next->val, stack_b->next->next->val, stack_b->next->next->next->val);
	
	// sa(stack_a);
	// printf("AFTER 1:\npos 1: %d\npos 1: %d\npos 1: %d\npos 1: %d\n\n", stack_a->val, stack_a->next->val, stack_a->next->next->val, stack_a->next->next->next->val);
	// sa(stack_a);
	// printf("AFTER 2:\npos 1: %d\npos 1: %d\npos 1: %d\npos 1: %d\n\n", stack_a->val, stack_a->next->val, stack_a->next->next->val, stack_a->next->next->next->val);
	
}