/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:43:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/24 01:11:09 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// double pointers cause we want to pass the address in the main
// to actually change the value of the pointers value
// -> arguments needs to be passed with '&' to the function


// swap first 2 elements of stack a
// Do nothing if there is only one or no elements
void sa(l_list **stack_a)
{
	int check;
	l_list *temp = NULL;
	
	check = 0;
	temp = *stack_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
		check++;
	}
	if((check + 1) < 2)
		return ; // quit and do nothing

	temp = (*stack_a)->next->val;
	(*stack_a)->next->val = (*stack_a)->val;
	(*stack_a)->val = temp;
}

// swap first 2 elements of stack b
// Do nothing if there is only one or no elements
void sb(l_list **stack_b)
{
	int check;
	l_list *temp = NULL;
	
	check = 0;
	temp = *stack_b;
	while (temp->next != NULL)
	{
		temp = temp->next;
		check++;
	}
	if((check + 1) < 2)
		return ; // do nothing
	temp = (*stack_b)->next->val;
	(*stack_b)->next->val = (*stack_b)->val;
	(*stack_b)->val = temp;
}

// rule sa and sb at the same time
void ss(l_list **stack_a, l_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}



// first element of stack b to stack a
// Do nothing if b is empty
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



// shift down all elements of stack a by 1
// the last element becomes the first one
void rra(l_list **stack_a)
{
	l_list *head = NULL;
	l_list *second_last = NULL;
	
	second_last = *stack_a;
	head = *stack_a;

	if ((*stack_a)->next == NULL)
	{
		printf("ERROR [(*stack_a)->next == NULL]");
		return ; //do nothing cause only one node in list
	}
	while ((*stack_a)->next->next != NULL)
		*stack_a = (*stack_a)->next; 

	second_last = *stack_a; // second last node -> is working
	*stack_a = (* stack_a)->next; // last node

	second_last->next = NULL;
	(* stack_a)->next = head;
}

// shift down all elements of stack b by 1
// the last element becomes the first one
void rrb(l_list **stack_b)
{
	l_list *head = NULL;
	l_list *second_last = NULL;
	
	second_last = *stack_b;
	head = *stack_b;

	if ((*stack_b)->next == NULL)
	{
		printf("ERROR [(*stack_b)->next == NULL]");
		return ; //do nothing cause only one node in list
	}
	while ((*stack_b)->next->next != NULL)
		*stack_b = (*stack_b)->next; 

	second_last = *stack_b; // second last node -> is working
	*stack_b = (* stack_b)->next; // last node

	second_last->next = NULL;
	(*stack_b)->next = head;
}

// rra and rrb at the same time
void rrr(l_list **stack_a, l_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}




// int main()
// { 
// 	l_list *node = NULL;
// 	int array[5] = {1, 2, 3, 4, 5};
// 	node = create_list_alone(5, array);
// 	// printf("BEFORE\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\npos 5: %d\n\n", node->val, node->next->val, node->next->next->val, node->next->next->next->val, node->next->next->next->next->val);
// 	print_list(&node);
// 	//printf("check\n");
// 	rra(&node);
// 	// rb(&node);
// 	// rb(&node);
// 	// rb(&node);
// 	// rb(&node);
// 	print_list(&node);
// 	// printf("AFTER\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\npos 5: %d\n\n", node->val, node->next->val, node->next->next->val, node->next->next->next->val, node->next->next->next->next->val);
// }
