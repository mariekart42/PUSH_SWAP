/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/16 04:02:45 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function creates linked list and adds content to it
l_list *create_list(int32_t len, char **content)
{
	l_list *temp = NULL;
	l_list *p = NULL;
	l_list *head = NULL;
	int32_t i = 1;
	while (i < len)
	{
		temp = (l_list *)malloc(sizeof(l_list));
		if (!temp)
			return (NULL);
		temp->next = NULL;
		temp->val = atoi(content[i]);
		if (head == NULL)
			head = temp;
		else
		{
			if(p == NULL)
				p = head;//p at the beginning just head
			else
				p = p->next;//p is the previouse position
			p->next = temp; // temp contains value  we want
		}		
		i++;
	}
	return(head);
}

int32_t list_len(l_list *head)
{
	int32_t len = 0;
	if (head == NULL)
		return(0);
	while (head->next != NULL)
	{
		len++;
		head = head->next;
	}
	return (len+1);
}

l_list *new_node(int32_t content)
{
	l_list *new = NULL;
	new = (l_list *)malloc(sizeof(l_list));
	if (!new)
		return(NULL);
	new->next = NULL;
	new->val = content;
	return (new);
}

int32_t last_nodes_content(l_list *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head->val);
}

l_list *lst_last(l_list *head)
{
	if(head == NULL)
		return(NULL);
	while(head->next != NULL)
		head = head->next;
	return(head);	
}

int32_t second_last(l_list *head)
{
	int temp;
	if(head->next->next == NULL)
	{
		return(head->val);
		
	}
	while(head->next->next != NULL)
	{
		temp = head->val;
		head = head->next;
	}
	return(temp);
}

// // function compares whole list to given digit
// // returns true if found duplication
// // false if not
// bool l_duplication(l_list *head, int content)
// {
// 	if (head == NULL)
// 		return (false);
// 	while (head != NULL)
// 	{
// 		if (head->val == content)
// 			return (true);
// 		head = head->next;
// 	}
// 	return (false);
// }

long int ft_atol(const char *str)
{
	int64_t		val; 	//int64_t == long int
	int8_t		minus; 	//int8_t == short int
	int32_t		i; 		// int32_t == int

	val = 0;
	minus = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		val = 10 * val + str[i] - 48;
		i++;
	}
	return (val * minus);
}

int	ft_isdigit(int val)
{
	if (val >= 48 && val <= 57)
		return (1);
	return (0);
}

void free_list(l_list *head)
{
	if(!head)
		return ;
	l_list *temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

// algo for only 3 digits -> max 2 rules! works
void hardcode_case_3(l_list **node)
{
	// print_list(node, "HERE NODE before");
	while((*node)->val > ((*node)->next->next)->val)
		ra(node, false);
	if(((*node)->next->next)->val < ((*node)->next)->val)
		rra(node, false);
	if((*node)->val > ((*node)->next)->val)
		sa(node, false);
	// print_list(node, "HERE NODE after");
}

void hardcode_case_4(l_list **node)
{
	l_list *temp = *node;
	int smallest_val = temp->val;
	temp = temp->next;
	while (temp != NULL)
	{
		if(temp->val < smallest_val)
			smallest_val = temp->val;
		temp = temp->next;
	}
	free(temp); // dunno lol
	if(((*node)->next)->val == smallest_val)
		sa(node, false);
	else if(((*node)->next->next)->val == smallest_val)
	{
		rra(node, false);
		rra(node, false);
	}
	else if(((*node)->next->next->next)->val == smallest_val)
		rra(node, false);
	hardcode_case_3(&((*node)->next));
}

void sort_stack_b(l_list **stack_a, l_list **stack_a, l_list **c_start, l_list **c_end)
{
	while(list_len(*stack_b) > 4)
	{
		
	}
	
	
	// hardcode cases for 2, 3 and 4
}



bool is_sorted_from_to(l_list **head, int32_t end, int32_t start, int32_t len)
{
	l_list *temp;
	int count = 0;
	while ((*head)->val != start)
		*head = (*head)->next;
		
	// temp should know have the same val as int start
	temp = *head;
	int array
	while(temp->val != end)
	{
		temp = temp->next;
		count++;
	}
	count++;
	
	
	// here again cause while loop doesnt compare last case

	
}