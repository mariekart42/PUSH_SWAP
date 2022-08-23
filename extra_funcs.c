/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/24 01:03:54 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int create_and_check_list(l_list **stack_a, char **argv, int argc)
{
	printf("len: %d\n", argc-1);
	*stack_a = create_list(argc - 1, argv);
	print_list(stack_a);
	// duplicates
	
	// int max/min
	return(0);
}

// function creates linked list and adds content to it
l_list *create_list(int len, char **content)
{
	l_list *temp = NULL;
	l_list *p = NULL;
	l_list *head = NULL;
	int i = 1;
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

int list_len(l_list *head)
{
	int len = 0;
	while (head->next != NULL)
	{
		len++;
		head = head->next;
	}
	return(len+1);
}

l_list *new_node(int content)
{
	l_list *new = NULL;
	new = (l_list *)malloc(sizeof(l_list));
	if (!new)
		return(NULL);
	new->next = NULL;
	new->val = content;
	return (new);
}

int last_nodes_content(l_list *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head->val);
}

// int main()
// {
// 	int content;
// 	l_list *node = NULL;
// 	int array[3] = {1, 2, 3};
// 	node = create_list_alone(3, array);
// 	content = last_nodes_content(node);
// 	printf("content: %d\n", content);
// }
