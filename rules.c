/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:43:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/07 17:26:12 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// double pointers cause we want to pass the address in the main
// to actually change the value of the pointers value
// -> arguments needs to be passed with '&' to the function


// swap first 2 elements of stack a
// Do nothing if there is only one or no element in a
void sa(l_list **stack_a, bool output)
{
	if(*stack_a == NULL || (*stack_a)->next == NULL)
	{
		printf("[sa rule] nothing or just one elemtent\n"); // deleter later
		write(STDERR_FILENO, "Error\n", 6); 
		//"In case of error, it must display "Error" followed by a ’\n’ on the standard error"
		// -> like this?
		return ;
	}

	l_list *head = NULL;
	head = *stack_a;
	
	*stack_a = (*stack_a)->next;
	head->next = (*stack_a)->next;
	(*stack_a)->next = head;

	if (output == false)
		write(1, "ss\n", 3);
	else
		write(1, "sa\n", 3);
}

// swap first 2 elements of stack b
// Do nothing if there is only one or no elements
void sb(l_list **stack_b, bool output)
{
	// int check;
	//l_list *temp = NULL;
	
	if(*stack_b == NULL || (*stack_b)->next == NULL)
	{
		printf("[sb rule] nothing or just one elemtent\n"); // delete later
		return ;
	}

	l_list *head = NULL;
	head = *stack_b;
	
	*stack_b = (*stack_b)->next;
	head->next = (*stack_b)->next;
	(*stack_b)->next = head;

	if (output == false)
		write(1, "ss\n", 3);
	else
		write(1, "sa\n", 3);
}

// rule sa and sb at the same time
void ss(l_list **stack_a, l_list **stack_b)
{
	sa(stack_a, false);
	sb(stack_b, false);
}


// first element of stack a to stack b
// first element of stack b gets removed!
// Do nothing if a is empty
void	pa(l_list **stack_a, l_list **stack_b)
{
	l_list *head = NULL;
	l_list *prev_content = *stack_b;
	if (*stack_b == NULL) // if stack_a is empty
	{
		printf("stack_b is empty\n"); // delete later
		return ;
	}
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	*stack_a = head;
	(*stack_a)->next = prev_content;
	write(1, "pa\n", 3);
}

// first element of stack a to stack b
// first element of stack b gets removed!
// Do nothing if a is empty
void	pb(l_list **stack_a, l_list **stack_b)
{
	l_list *head = NULL;
	l_list *prev_content = *stack_b;
	
	if (*stack_a == NULL) // if stack_a is empty
	{
		printf("stack_a is empty\n"); // delete later
		return ;
	}
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	*stack_b = head;
	(*stack_b)->next = prev_content;
	write(1, "pb\n", 3);
}



// Shift up all elements of stack a by 1
// The first element becomes the last one
void ra(l_list **stack_a, bool output)
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
	if (output == false)
		write(1, "rr\n", 3);
	else
		write(1, "ra\n", 3);
}

// Shift up all elements of stack b by 1
// The first element becomes the last one
void rb(l_list **stack_b, bool output)
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
	if (output == false)
		write(1, "rr\n", 3);
	else
		write(1, "rb\n", 3);
}
// is working correctly 

void rr(l_list **stack_a, l_list **stack_b)
{
	ra(stack_a, false);
	rb(stack_b, false);
}



// shift down all elements of stack a by 1
// the last element becomes the first one
void rra(l_list **stack_a, bool output)
{
	l_list *head = NULL;
	l_list *second_last = NULL;
	
	second_last = *stack_a;
	head = *stack_a;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		printf("none or just one element in stack_a\n");
		return ; //do nothing cause only one node in list
	}
	while ((*stack_a)->next->next != NULL)
		*stack_a = (*stack_a)->next; 

	second_last = *stack_a; // second last node -> is working
	*stack_a = (* stack_a)->next; // last node

	second_last->next = NULL;
	(* stack_a)->next = head;
	if (output == false)
		write(1, "rrr\n", 4);
	else
		write(1, "rra\n", 4);
}

// shift down all elements of stack b by 1
// the last element becomes the first one
void rrb(l_list **stack_b, bool output)
{
	l_list *head = NULL;
	l_list *second_last = NULL;
	
	second_last = *stack_b;
	head = *stack_b;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		printf("none or just one element in stack_b\n");
		return ; //do nothing cause only one node in list
	}
	while ((*stack_b)->next->next != NULL)
		*stack_b = (*stack_b)->next; 

	second_last = *stack_b; // second last node -> is working
	*stack_b = (* stack_b)->next; // last node

	second_last->next = NULL;
	(*stack_b)->next = head;
	if (output == false)
		write(1, "rrr\n", 4);
	else
		write(1, "rrb\n", 4);
}

// rra and rrb at the same time
void rrr(l_list **stack_a, l_list **stack_b)
{
	rra(stack_a, false);
	rrb(stack_b, false);
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
