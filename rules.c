/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:43:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/23 20:58:10 by mmensing         ###   ########.fr       */
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
	if(stack_a == NULL) // if stack_a is empty
		return ;
	temp = (*stack_a)->val;
	temp_b = (*stack_b);
	(*stack_b) = new_node(temp);
	(*stack_b)->next = temp_b;
}
// the swap is working correctly but is return right?
// ----------------------------------------------------------
// ----------- ra & rb & rr ---------------------------------
// Shift up all elements of stack a by 1
// The first element becomes the last one
void ra(l_list **stack_a)
{
	if ((*stack_a)->next == NULL)
		return ; //some error thing
	l_list *temp = NULL;
	l_list *first_node = NULL;
	
	temp = *stack_a;
	first_node = *stack_a;
	
	*stack_a = (*stack_a)->next; 
	while(temp->next != NULL)
		temp = temp->next; // last position of list
	temp->next = first_node;
	first_node->next = NULL;
}
// is working correctly 

// Shift up all elements of stack b by 1
// The first element becomes the last one
void rb(l_list **stack_b)
{
	if ((*stack_b)->next == NULL)
		return ; //some error thing
	l_list *temp = NULL;
	l_list *first_node = NULL;
	
	temp = *stack_b;
	first_node = *stack_b;
	
	*stack_b = (*stack_b)->next; 
	while (temp->next != NULL)
		temp = temp->next; // last position of list
	temp->next = first_node;
	first_node->next = NULL;
}
// is working correctly 

void rr(l_list **stack_a, l_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
// ----------------------------------------------------------
// ----------- rra & rrb & rrr ------------------------------
// shift down all elements of stack a by 1
// the last element becomes the first one
void rra(l_list **stack_a)
{
	l_list *temp_a = NULL;
	l_list *iter = NULL;
	
	iter = *stack_a;
	temp_a = *stack_a;
	// while (iter->next->next != NULL)
	// 	iter = iter->next;
	// iter->next = NULL;
	printf("stack_a->val: %d\n", (*stack_a)->val);
	if((*stack_a)->next == NULL)
	{
		printf("ERROR [(*stack_a)->next == NULL]");
		return ;
	}
	while ((*stack_a)->next->next != NULL)
		*stack_a = (*stack_a)->next;
		printf("check_func\n");
	iter = *stack_a;
	*stack_a = (*stack_a)->next;
	// stack_a points now to last node
	printf("stack_a end: %d\n", (*stack_a)->val);
	(*stack_a)->next = temp_a;
	// printf("temp_a: %d\n", temp_a->val);
	// if(temp_a->next == NULL)
	// 	printf("NULL\n");
	// printf("temp_a: %d\n", temp_a->next->val);
}
// setting in the end something to NULL!!
// iterating again trough the list and set now last node to NULL i guess


// main for ra and rb
int main()
{ 
	l_list *node = NULL;
	int array[5] = {1, 2, 3, 4, 0};
	node = create_list_alone(5, array);
	//printf("BEFORE\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\npos 5: %d\n\n", node->val, node->next->val, node->next->next->val, node->next->next->next->val, node->next->next->next->next->val);
	print_list(&node);
	printf("check\n");
	rra(&node);
	// rb(&node);
	// rb(&node);
	// rb(&node);
	// rb(&node);
	print_list(&node);
	// printf("AFTER\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\npos 5: %d\n\n", node->val, node->next->val, node->next->next->val, node->next->next->next->val, node->next->next->next->next->val);
}
