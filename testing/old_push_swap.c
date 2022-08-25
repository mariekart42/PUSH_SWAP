/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:35:09 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/09 18:50:55 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//difference swap a and swap b??




// function checks for duplications
// returns -1 if duplicated
int duplications(char *nums[], int argc)
{
	int k = 0;
	int all[argc-1];
	nums++;
	while (k+1 < argc)
	{
		all[k] = atoi(*nums);
		//printf("all[k] = %d\n", all[k]);
		nums++;
		k++;
	}
	all[k] = '\0';
	int i = 0;
	int n = 1;
	while (all[i] != '\0')
	{
		while(all[n+i] != '\0')
		{
			if(all[i] == all[n+i])
				return(-1);
			n++;
		}
		n = 1;
		i++;
	}
	return(k);
}


// function creates linked list and adds content to it
char *create_list(int len, char *content)
{
	stack_a *temp = NULL;
	stack_a *p = NULL;
	stack_a *head = NULL;
	int i = 0;
	while (i < len)
	{
		temp = (stack_a *)malloc(sizeof(stack_a));
		if(!temp)
			return(NULL);
		temp->next = NULL;
		temp->val_a = content[i];
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
	return((char*)head);
}


/**
 * @brief function turns double pointer argv into single pointer
 * 
 * @param argc len of array
 * @param argv content
 * @return char* normal pointer to list of content from argv
 */
char *argv_changer(int argc, char **argv)
{
	int i = 0;
	int k = 1;
	char *array;
	array = (char *)malloc(argc);
	if(!array)
		return(NULL);
	//char array[len-1];
	//printf("len: %d\n", len);
	while(argc > k)
	{
		array[i] = atoi(argv[k]);
		// printf("argv[%d]  = %d\n", i, atoi(argv[k]));
		// printf("array[%d] = %d\n", i, array[i]);
		i++;
		k++;
	}
	array[i] = '\0';
	return(array);
}
