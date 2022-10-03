/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/03 15:11:26 by mmensing         ###   ########.fr       */
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

int32_t last_node_content(l_list *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head->val);
}


//returns last node in list
l_list *lst_last(l_list *head)
{
	printf(RED"CHUFT\n"RESET);
	
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
	while((*node)->val > ((*node)->next->next)->val)
		ra(node, false);
	if(((*node)->next->next)->val < ((*node)->next)->val)
		rra(node, false);
	if((*node)->val > ((*node)->next)->val)
		sa(node, false);
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
	if(stack == node)// || node == NULL)
	{
		printf(RED"\n!! i prev function case appeared\n\n"RESET);
		return(NULL);
	}
	while(stack->next != NULL && stack->next->val != node->val)
		stack = stack->next;
	return(stack);
}

// function calculates the amount of nodes(including end)
int32_t range(l_list* stack, l_list* begin, l_list *end)
{
	int count = 1;
	while(stack->val != begin->val)
		stack = stack->next;
	while(stack->val != end->val)
	{
		stack = stack->next;
		count++;
	}
	return(count);

}


void del_last(l_list **node)
{
	l_list *temp = *node;
	if(*node == NULL)
		return ;
		
	if((*node)->next == NULL)
	{
		*node = NULL;
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



l_list *after(l_list *stack, l_list* node)
{
	if(stack == node)
	{
		printf(RED"\n!! in after function case appeared\n\n"RESET);
		return(NULL);
	}
	while(stack != NULL && stack->val != node->val)
		stack = stack->next;
	if(stack != NULL)
		stack = stack->next;
	return(stack);
}



// void hardcode_func(l_list **stack_a)
void hardcode_func(l_list**stack_a, l_list **stack_b, l_list *end)
{
	int len = 0;
	l_list *temp = *stack_a;
	while(temp->val != end->val)
	{
		temp = temp->next;
		len++;
	}
	if(len == 1)
		printf("ONLY ONE IN HARDCODE FUNC (should not happen)");
	else if(len == 2)
	{
		if((*stack_a)->val > (*stack_a)->next->val)
			sa(stack_a, false);
	}
	else if(len == 3)
		hc_three(stack_a);
	else if(len == 4)
		hc_four(stack_a, stack_b);
}


void hc_three(l_list **stack_a)
{
	if((*stack_a)->next->next->val < (*stack_a)->val || (*stack_a)->next->next->val < (*stack_a)->next->val)
	{
		if((*stack_a)->val > (*stack_a)->next->val)
			sa(stack_a, true);
		ra(stack_a, true);
		if((*stack_a)->val > (*stack_a)->next->val)
			sa(stack_a, true);
		rra(stack_a, true);
		if((*stack_a)->val > (*stack_a)->next->val)
			sa(stack_a, true);
	}
	else if((*stack_a)->val > (*stack_a)->next->val)
		sa(stack_a, true);
}


// function returns the fist found number that is smollest or second smollest
int smol(l_list *stack_a)
{
	l_list *temp = stack_a;
	
	// first smaller then sec & third OR sec & four OR third & four
	if((temp->val < stack_a->next->next->next->val && temp->val < stack_a->next->next->val)
		|| (temp->val < stack_a->next->next->next->val && temp->val < stack_a->next->val)
		|| (temp->val < stack_a->next->next->val && temp->val < stack_a->next->val))
		return (temp->val);
	else if((temp->next->val < stack_a->next->next->val && temp->next->val < stack_a->val)
		|| (temp->next->val < stack_a->next->next->next->val && temp->next->val < stack_a->val))
		return(temp->next->val);
	else
		return(temp->next->next->val);

}

void hc_four(l_list **stack_a, l_list **stack_b)
{
	int smolst_int;
	
	smolst_int = smol(*stack_a);
	if((*stack_a)->next->next->val == smolst_int)
	{
		ra(stack_a, true);
		sa(stack_a, false);
		rra(stack_a, true);
		sa(stack_a, true);
		ra(stack_a, true);
	}
	else if((*stack_a)->next->val == smolst_int)
	{
		sa(stack_a, true);
		ra(stack_a, true);
	}
	else if((*stack_a)->val == smolst_int)
		ra(stack_a, true);
	hc_three(stack_a);
	rra(stack_a, stack_b);
	if((*stack_a)->val > (*stack_a)->next->val)
		sa(stack_a, true);
}


void special_case(l_list **stack_a, l_list** stack_b, l_list *last_a, l_list**temp_b_starts, l_list**b_starts)
{
	l_list* temp = last_a->next;
	if(*stack_b != lst_last(*temp_b_starts) || *stack_b != lst_last(*b_starts))
	{
		if(temp_b_starts == NULL)
			*temp_b_starts = new_node((*stack_b)->val);
		else if(*temp_b_starts != NULL)
			(lst_last(*temp_b_starts))->next = new_node((*stack_b)->val);
	}
	while(temp != NULL)
	{
		temp = temp->next;
		rra(stack_a, true);
		pb(stack_a, stack_b);
	}
}

// function returns pointer to place in given stack of content node
l_list *place(l_list*stack, l_list*node)
{
	if(stack == NULL)
	{
		printf("error in function PLACE\n\n");
		return(NULL);
	}
	if(node == NULL)
		return(NULL);
	while(stack->val != node->val)
		stack = stack->next; 
	return(stack);
}

// for the ABOVE nums: 
//   -> "start" [gets pushed]  
//      "end" [gets NOT pushed]
//
// for the UNDER nums:
//   -> "start" [gets NOT pushed]  
//      "end" [gets NOT pushed]
//
// make b empty:
//   -> everything gets pushed
void push_all_to_a(char *from, l_list*start, l_list* end, l_list **stack_a, l_list** stack_b)
{
    l_list *temp = start;
	
	if(ft_strncmp(from, "above_b", 7) == 0)// or above a
	{
		while(temp != end)
		{
			if(ft_strncmp(from, "above_b", 7) == 0)
			{
				temp = temp->next;
				pa(stack_a, stack_b);
			}
		}
	}
	else if(ft_strncmp(from, "under_b", 7) == 0 || ft_strncmp(from, "under_a", 7) == 0)
	{
		while(temp->next != NULL)
		{
			if(ft_strncmp(from, "under_b", 7) == 0)
			{
				rrb(stack_b, true);
				pa(stack_a, stack_b);
			}
			else if(ft_strncmp(from, "under_a", 7) == 0)
				rra(stack_a, true);			
		}
	}
	else if(ft_strncmp(from, "make_b_empty", 12) == 0)
	{
		while(list_len(*stack_b) > 0)
			pa(stack_a, stack_b);
	}
	return ;
}