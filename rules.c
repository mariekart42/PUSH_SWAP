/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:43:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/23 00:39:28 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// swap first 2 elements of stack a
void sa(l_list *stack_a)
{
	int temp = 0;
	if (list_len(stack_a) < 2)
		return ;
	temp = stack_a->next->val;
	stack_a->next->val = stack_a->val;
	stack_a->val = temp;
}

// swap first 2 elements of stack b
void sb(l_list *stack_b)
{
	int temp = 0;
	if (list_len(stack_b) < 2)
		return ;
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

// --------- pa & pb ---------------------------------------------
// first element of stack b to stack a
// Do nothing if b is empty
// double pointers cause we want to pass the address in the main
// to actually change the value of the pointers value
// -> arguments needs to be passed with '&' to the function
void pa(l_list **stack_a, l_list **stack_b)
{
	int temp;
	
	temp = 0;
	l_list *temp_a = NULL;
	if (stack_b == NULL) // if stack_b is empty
		return ;
	temp = (*stack_b)->val;
	temp_a = (*stack_a);
	(*stack_a) = new_node(temp);
	(*stack_a)->next = temp_a;
}
// the swap is working correctly but is return right?


// first element of stack a to stack b
// Do nothing if a is empty
void pb(l_list **stack_a, l_list **stack_b)
{
	int temp;
	
	temp = 0;
	l_list *temp_b = NULL;
	if(stack_b == NULL) // if stack_a is empty
		return ;
	temp = (*stack_b)->val;
	temp_b = (*stack_b);
	(*stack_b) = new_node(temp);
	(*stack_b)->next = temp_b;
}
// the swap is working correctly but is return right?
// ----------------------------------------------------------
// ----------- ra & rb --------------------------------------
// Shift up all elements of stack a by 1
// The first element becomes the last one.
void ra(l_list **stack_a)
{
	int last_node;
	l_list *rm_last = NULL;
	l_list *temp_a = NULL;
	last_node = last_nodes_content(* stack_a);
	temp_a = (*stack_a);
	printf("last_node: %d\n", last_node);
	printf("stack_a->val: %d\n", (*stack_a)->val);
	(*stack_a) = new_node(last_node);
	(*stack_a)->next = temp_a;
}
// not working dunno maybe stack heap shit
// compare to others code 



// main for ra and rb
int main()
{
	l_list *node = NULL;
	int array[3] = {1, 2, 5};
	node = create_list_alone(3, array);
	printf("BEFORE\npos 1: %d\npos 2: %d\npos 3: %d\n\n", node->val, node->next->val, node->next->next->val);
	ra(&node);
	printf("AFTER\npos 1: %d\npos 2: %d\npos 3: %d\n\n", node->val, node->next->val, node->next->next->val);
}




// // main for pa and pb
// int main()
// {
// 	//before
// 	printf("BEFORE\n");
// 	l_list *stack_a = NULL;
// 	int array_a[3] = {1, 2, 3};
// 	stack_a = create_list_alone(3, array_a);
// 	printf("stack_a:\npos 1: %d\npos 2: %d\npos 3: %d\n\n", stack_a->val, stack_a->next->val, stack_a->next->next->val);

// 	l_list *stack_b = NULL;
// 	int array_b[4] = {2, 8, 7, 6};
// 	stack_b = create_list_alone(4, array_b);
// 	printf("stack_b:\npos 1: %d\npos 2: %d\npos 3: %d\n\n", stack_b->val, stack_b->next->val, stack_b->next->next->val);
	
// 	//using pa rule
// 	pa(&stack_a, &stack_b);
// 	printf("AFTER\n");
// 	printf("stack_a:\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\n\n", stack_a->val, stack_a->next->val, stack_a->next->next->val, stack_a->next->next->next->val);
// 	printf("stack_b:\npos 1: %d\npos 2: %d\npos 3: %d\n\n", stack_b->val, stack_b->next->val, stack_b->next->next->val);
// }