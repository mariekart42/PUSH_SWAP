/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/14 15:48:15 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function creates linked list and adds content to it
t_list *create_list(int32_t len, char **content)
{
	t_list *temp = NULL;
	t_list *p = NULL;
	t_list *head = NULL;
	int32_t i = 1;
	while (i < len)
	{
		temp = (t_list *)malloc(sizeof(t_list));
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


int32_t list_len(t_list *head)
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


t_list *new_node(int32_t content)
{
	t_list *new = NULL;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return(NULL);
	new->val = content;
	new->next = NULL;
	return (new);
}


int32_t last_node_content(t_list *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head->val);
}

//returns last node in list
t_list *lst_last(t_list *head)
{
	if(head == NULL)
		return(NULL);
	while(head->next != NULL)
		head = head->next;
	return(head);	
}

// // returns NULL if head is NULL or the next is also NULL
// t_list *second_last(t_list *head)
// {
// 	t_list *temp;
// 	if(head == NULL || head->next == NULL)
// 		return(NULL);
// 	if(head->next->next == NULL)
// 	{
// 		return(head);
		
// 	}
// 	while(head->next->next != NULL)
// 	{
// 		temp = head;
// 		head = head->next;
// 	}
// 	return(temp);
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

void free_list(t_list *head)
{
	if(!head)
		return ;
	t_list *temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

// checks if th stack is sorted
bool stack_sorted(t_list **stack)
{
	t_list *temp;
	temp = *stack;
	while(temp->next != NULL)
	{
		if (temp->val > temp->next->val)
			return(false);
		temp = temp->next;
	}
	return(true);	
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
			return ((unsigned char)(s1[i]) - ((unsigned char)s2[i]));
	i++;
	}
	return (0);
}

// function calculates the amount of nodes(including end)
int32_t range(t_list* stack, t_list* begin, t_list *end)
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

// function returns pointer to place in given stack of content node
t_list *place(t_list*stack, t_list*node)
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
void push_all_to_a(char *from, t_list*start, t_list* end, t_list **a, t_list** b)
{
    t_list *temp = start;
	
	if(ft_strncmp(from, "above_b", 7) == 0)
	{
		while(temp != end)
		{
			if(ft_strncmp(from, "above_b", 7) == 0)
			{
				temp = temp->next;
				pa(a, b);
			}
		}
	}
	else if(ft_strncmp(from, "under_b", 7) == 0 || ft_strncmp(from, "under_a", 7) == 0)
	{
		while(temp->next != NULL)
		{
			if(ft_strncmp(from, "under_b", 7) == 0)
			{
				rrb(b, true);
				pa(a, b);
			}
			else if(ft_strncmp(from, "under_a", 7) == 0)
				rra(a, true);			
		}
	}
	else if(ft_strncmp(from, "make_b_empty", 12) == 0)
	{
		while(list_len(*b) > 0)
			pa(a, b);
	}
	return ;
}

void push_all_to_b(t_list** stack, t_list*start, t_list*end)
{
	
	while((*stack)->val != start->val)
		*stack = (*stack)->next;
	while(*stack != end)
		rrb(stack, true);
}


void del_last(t_list **node)
{
	t_list *temp = *node;
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
	(temp)->next = NULL;
}

/**
 * @brief Outputs the string ’s’ to the given file descriptor
 * 
 * @param s string to output
 * @param fd given file descriptor
 */
void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}











// // algo for only 3 digits -> max 2 rules! works
// void hardcode_case_3(t_list **node)
// {
// 	while((*node)->val > ((*node)->next->next)->val)
// 		ra(node, true);
// 	if(((*node)->next->next)->val < ((*node)->next)->val)
// 		rra(node, true);
// 	if((*node)->val > ((*node)->next)->val)
// 		sa(node, true);
// }


// void hardcode_case_4(t_list **node)
// {
// 	t_list *temp = *node;
// 	int smallest_val = temp->val;
// 	temp = temp->next;
// 	while (temp != NULL)
// 	{
// 		if(temp->val < smallest_val)
// 			smallest_val = temp->val;
// 		temp = temp->next;
// 	}
// 	free(temp); // dunno lol
// 	if(((*node)->next)->val == smallest_val)
// 		sa(node, true);
// 	else if(((*node)->next->next)->val == smallest_val)
// 	{
// 		rra(node, true);
// 		rra(node, true);
// 	}
// 	else if(((*node)->next->next->next)->val == smallest_val)
// 		rra(node, true);
// 	hardcode_case_3(&((*node)->next));
// }




bool lst_is_sorted(t_list **head, int32_t end, int32_t start)
{
	t_list *temp;
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
t_list *prev(t_list *stack, t_list*node)
{
	if(stack == node)
		return(NULL);
	while(stack->next != NULL && stack->next->val != node->val)
		stack = stack->next;
	return(stack);
}



t_list *after(t_list *stack, t_list* node)
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



// void hardcode_func(t_list **a)
void hardcode_func(t_list**a, t_list **b, t_list *end)
{
	int len = 0;
	t_list *temp = *a;
	while(temp->val != end->val)
	{
		temp = temp->next;
		len++;
	}
	if(len == 2)
	{
		if((*a)->val > (*a)->next->val)
			sa(a, true);
	}
	else if(len == 3)
		hc_three(a);
	else if(len == 4)
		hc_four(a, b);
}


void hc_three(t_list **a)
{
	if((*a)->next->next->val < (*a)->val || (*a)->next->next->val < (*a)->next->val)
	{
		if((*a)->val > (*a)->next->val)
			sa(a, true);
		ra(a, true);
		if((*a)->val > (*a)->next->val)
			sa(a, true);
		rra(a, true);
		if((*a)->val > (*a)->next->val)
			sa(a, true);
	}
	else if((*a)->val > (*a)->next->val)
		sa(a, true);
}


// function returns the fist found number that is smollest or second smollest
int smol(t_list *a)
{
	t_list *temp = a;
	
	// first smaller then sec & third OR sec & four OR third & four
	if((temp->val < a->next->next->next->val && temp->val < a->next->next->val)
		|| (temp->val < a->next->next->next->val && temp->val < a->next->val)
		|| (temp->val < a->next->next->val && temp->val < a->next->val))
		return (temp->val);
	else if((temp->next->val < a->next->next->val && temp->next->val < a->val)
		|| (temp->next->val < a->next->next->next->val && temp->next->val < a->val))
		return(temp->next->val);
	else
		return(temp->next->next->val);

}

void hc_four(t_list **a, t_list **b)
{
	int smolst_int;
	
	smolst_int = smol(*a);
	if((*a)->next->next->val == smolst_int)
	{
		ra(a, true);
		sa(a, true);
		rra(a, true);
		sa(a, true);
		ra(a, true);
	}
	else if((*a)->next->val == smolst_int)
	{
		sa(a, true);
		ra(a, true);
	}
	else if((*a)->val == smolst_int)
		ra(a, true);
	hc_three(a);
	rra(a, b);
	if((*a)->val > (*a)->next->val)
		sa(a, true);
}


void special_case(t_list **a, t_list** b, t_list *last_a, t_list**tmp_b_start, t_list**b_start)
{
	t_list* temp = last_a->next;
	if(*b != lst_last(*tmp_b_start) || *b != lst_last(*b_start))
	{
		if(tmp_b_start == NULL)
			*tmp_b_start = new_node((*b)->val);
		else if(*tmp_b_start != NULL)
			(lst_last(*tmp_b_start))->next = new_node((*b)->val);
	}
	while(temp != NULL)
	{
		temp = temp->next;
		rra(a, true);
		pb(a, b);
	}
}












void hc_quick(t_holder* l_hold)
{
    if (list_len(l_hold->a) == 3)
		hardcode_case_3(&l_hold->a);
	else if (list_len(l_hold->a) == 4)
		hardcode_case_4(&l_hold->a, l_hold);
	else if (list_len(l_hold->a) == 2 && ((l_hold->a)->val > (l_hold->a)->next->val))
		ra(&l_hold->a, true);
}

// algo for only 3 digits -> max 2 rules! works
void hardcode_case_3(t_list **node)
{
	while ((*node)->val > ((*node)->next->next)->val)
		ra(node, true);
	if (((*node)->next->next)->val < ((*node)->next)->val)
		rra(node, true);
	if ((*node)->val > ((*node)->next)->val)
		sa(node, true);
}

void hardcode_case_4(t_list **node, t_holder*l_hold) // add list holder here, 
{
	t_list *temp = *node;
	int smallest_val = temp->val;
	temp = temp->next;
	while (temp != NULL)
	{
		if (temp->val < smallest_val)
			smallest_val = temp->val;
		temp = temp->next;
	}
	free(temp); // dunno lol
	if ((*node)->next->val == smallest_val)
		sa(node, true);
	else if ((*node)->next->next->val == smallest_val)
	{
		rra(node, true);
		rra(node, true);
	}
	else if ((*node)->next->next->next->val == smallest_val)
		rra(node, true);
	pb(node, &l_hold->b);
	hardcode_case_3(node);
	pa(node, &l_hold->b);
}