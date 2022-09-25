/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/25 14:54:09 by mmensing         ###   ########.fr       */
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


//returns last node in list
l_list *lst_last(l_list *head)
{
	if(head == NULL)
		return(NULL);
	while(head->next != NULL)
		head = head->next;
	return(head);	
}

// returns NULL if head is NULL or the next is also NULL
l_list *second_last(l_list *head)
{
	l_list *temp;
	if(head == NULL || head->next == NULL)
		return(NULL);
	if(head->next->next == NULL)
	{
		return(head);
		
	}
	while(head->next->next != NULL)
	{
		temp = head;
		head = head->next;
	}
	return(temp);
}


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


// checks if th stack is sorted
bool stack_sorted(l_list **stack)
{
	l_list *temp;
	// temp should know have the same val as int start
	temp = *stack;
	while(temp->next != NULL)
	{
		if (temp->val > temp->next->val)
			return(false);
		temp = temp->next;
	}
	return(true);	
}

bool lst_is_sorted(l_list **head, int32_t end, int32_t start)
{
	l_list *temp;
	while ((*head)->val != start)
		*head = (*head)->next;
		
	// temp should know have the same val as int start
	temp = *head;
	while(temp->val != end)
	{
		if(temp->val > temp->next->val)
			return(false);
		temp = temp->next;
	}
	return(true);	
}

//prev returns the previouse content of node in stack
//if node is NULL, function returns the content before NULL 
//  in the current stack
//function doesnt handle cases where there is no prev of node
//  or node or stack are NULL!
l_list *prev(l_list *stack, l_list*node)
{
	printf("node: %d\n\n", node->val);
	print_list(&stack, "STACK");
	if(stack == node || stack == NULL)
	{
		printf(RED"\n!! i prev function case appeared\n\n"RESET);
		return(NULL);
	}
	while(stack->next->val != node->val && stack->next != NULL)
	{
		stack = stack->next;
	}
	return(stack);
}

// function calculates the amount of nodes(including end)
int32_t range(l_list* begin, l_list *end)
{
	int count = 1;
	while(begin->val != end->val)
	{
		begin = begin->next;
		count++;
	}
	return(count);

}





// // function compares the actual ending digit with the given input
// bool check_ending(l_list *stack, l_list *content)
// {
// 	l_list *temp = NULL;
// 	while (temp->next != NULL)
// 		temp = temp->next;
// 	if (temp->val == content->val)
// 		return(true);
// 	else 
// 		return(false);
// }


void del_last(l_list **node)
{
	l_list *temp = *node;
	if(*node == NULL)
		return ;
		
	if((*node)->next == NULL)
	{
		*node = NULL;
		free((*node)->next);
		return ;
	}
	while(temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}


/**
compares 2 char arrays if one of them is greater, less or equal
stop point is a fixed variable n
for extendet ascii using unsigned char
e.g. 
"abc" > "aba"   ->    returns 1
  ""  =  ""     ->    returns 0
 "a"  < "abc"   ->    returns -1
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)(s1[i]) - ((unsigned char)s2[i]));
		}
	i++;
	}
	return (0);
}