/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/09 20:32:42 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// /**
//  * @brief function turns double pointer argv into single pointer
//  * 
//  * @param argc len of array
//  * @param argv content
//  * @return char* normal pointer to list of content from argv
//  */
// l_list *argv_changer(int argc, char **argv)
// {
// 	int i = 0;
// 	int k = 1;
// 	char *array;
// 	array = (char *)malloc(argc);
// 	if (!array)
// 		return(NULL);
// 	while (argc > k)
// 	{
// 		array[i] = atoi(argv[k]);
// 		i++;
// 		k++;
// 	}
// 	array[i] = '\0';
// 	return(array);
// }

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

