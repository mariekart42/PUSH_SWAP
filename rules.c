/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:43:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/14 15:59:31 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


// double pointers cause we want to pass the address in the main
// to actually change the value of the pointers value
// -> arguments needs to be passed with '&' to the function
static int count = 0;

int counti()
{
	return count;
}
// swap first 2 elements of stack a
// Do nothing if there is only one or no element in a
void sa(t_list **a, bool output)
{
	count++;
	if (*a == NULL || (*a)->next == NULL)
	{
		// printf("[sa rule] nothing or just one elemtent\n"); // deleter later
		//"In case of error, it must display "Error" followed by a ’\n’ on the standard error"
		// -> like this?
		return ;
	}

	t_list *head = NULL;
	head = *a;
	
	*a = (*a)->next;
	head->next = (*a)->next;
	(*a)->next = head;

	if (output == true)
		write(1, "sa\n", 3);
	else
		write(1, "ss\n", 3);
		

}

// swap first 2 elements of stack b
// Do nothing if there is only one or no elements
void sb(t_list **b, bool output)
{
	count++;
	if (*b == NULL || (*b)->next == NULL)
	{
		// printf("[sb rule] nothing or just one elemtent\n"); // delete later
		return ;
	}
	t_list *head = NULL;
	head = *b;
	
	*b = (*b)->next;
	head->next = (*b)->next;
	(*b)->next = head;

	if (output == true)
		write(1, "sa\n", 3);
	else
		write(1, "ss\n", 3);
		
		
}

// rule sa and sb at the same time
void ss(t_list **a, t_list **b)
{
	sa(a, false);
	sb(b, false);
}


// first element of stack b to top of stack a
// first element of stack a gets removed!
// Do nothing if b is empty
void	pa(t_list **a, t_list **b)
{
	count++;
	t_list *head = NULL;
	t_list *prev_content = *a;
	if (*b == NULL) // if b is empty
	{
		// printf("b is empty\n"); // delete later
		return ;
	}
	head = *b;
	*b = (*b)->next;
	*a = head;
	(*a)->next = prev_content;
	write(1, "pa\n", 3);
	

}

// first element of stack a to stack b
// first element of stack b gets removed!
// Do nothing if a is empty
void	pb(t_list **a, t_list **b)
{
	count++;
	t_list *head = NULL;
	t_list *prev_content = *b;
	
	if (*a == NULL)
	{
		// printf("a is empty\n"); // delete later
		return ;
	}
	head = *a;
	*a = (*a)->next;
	*b = head;
	(*b)->next = prev_content;
	write(1, "pb\n", 3);
}



// Shift up all elements of stack a by 1
// The first element becomes the last one
void ra(t_list **a, bool output)
{
	count++;
	if ((*a)->next == NULL)
		return ;

	t_list *temp = NULL;
	t_list *first_node = NULL;
	
	temp = *a;
	first_node = *a;
	
	*a = (*a)->next; 
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first_node;
	first_node->next = NULL;
	if (output == true)
		write(1, "ra\n", 3);
	else
		write(1, "rr\n", 3);
		

}

// Shift up all elements of stack b by 1
// The first element becomes the last one
void rb(t_list **b, bool output)
{
	count++;
	if ((*b)->next == NULL)
		return ;
		
	t_list *temp = NULL;
	t_list *first_node = NULL;
	
	temp = *b;
	first_node = *b;
	
	*b = (*b)->next; 
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first_node;
	first_node->next = NULL;
	if (output == true)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
		

}

void rr(t_list **a, t_list **b)
{
	ra(a, false);
	rb(b, false);
}



// shift down all elements of stack a by 1
// the last element becomes the first one
void rra(t_list **a, bool output)
{
	count++;
	t_list *head = NULL;
	t_list *second_last = NULL;
	
	second_last = *a;
	head = *a;

	if (*a == NULL || (*a)->next == NULL)
	{
		// printf("none or just one element in a\n");
		return ;
	}
	while ((*a)->next->next != NULL)
		*a = (*a)->next; 

	second_last = *a;
	*a = (* a)->next;

	second_last->next = NULL;
	(* a)->next = head;
	if (output == true)
		write(1, "rra\n", 4);
	else
		write(1, "rrr\n", 4);
		

}

// shift down all elements of stack b by 1
// the last element becomes the first one
void rrb(t_list **b, bool output)
{
	count++;
	t_list *head = NULL;
	t_list *second_last = NULL;
	
	second_last = *b;
	head = *b;

	if (*b == NULL || (*b)->next == NULL)
	{
		// printf("none or just one element in b\n");
		return ;
	}
	while ((*b)->next->next != NULL)
		*b = (*b)->next; 

	second_last = *b;
	*b = (* b)->next;

	second_last->next = NULL;
	(*b)->next = head;
	if (output == true)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
		

}

// rra and rrb at the same time
void rrr(t_list **a, t_list **b)
{
	rra(a, false);
	rrb(b, false);
}

