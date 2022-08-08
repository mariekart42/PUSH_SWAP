/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:35:09 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/08 21:58:38 by mmensing         ###   ########.fr       */
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
stack_a *create_list(int len, char *content)
{
	stack_a *temp = NULL;
	stack_a *p = NULL;
	stack_a *head = NULL;
	int i = 0;
	while(i < len)
	{
		temp = (stack_a *)malloc(sizeof(stack_a));
		if(!temp)
			return(NULL);
		temp->next = NULL;
		temp->val = content[i];
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


// int main(int argc, char *argv[])
// {
// 	int i = 1;
// 	int dup_result = duplications(argv, argc);
// 	if(dup_result == -1)
// 	{
// 		printf("ERROR: num duplicate\n");
// 		return(0);//error message?
// 	}

// 	//creating linked list:
// 	Node *head = NULL;
// 	head = create_list(argc, argv);
// 	//-> works
	
// 	while (argv[i] != NULL)
// 	{
// 		// printf("argv[%d] = %s\n", i, argv[i]);
// 		i++;
// 	}	
// }

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
	array = (char *)malloc(len);
	if(!array)
		return(NULL);
	//char array[len-1];
	//printf("len: %d\n", len);
	while(len > k)
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

int main(int argc, char *argv[])
{
	//stack_a *head = NULL;
	char *array;
	array = argv_changer(argc, argv);
	// head = create_list(argc , array);
	
	
	// stack_a *stack_b = NULL;
	
	// printf("len of list: %d\n", list_len(stack_a));
	//printf("pos 1: %d\npos 2: %d\npos 3: %d\n\n", head->val_a, head->next->val_a,  head->next->next->val_a );
	// printf("check in main function\n");
	// stack_a *test = NULL;
	// test = sa(stack_a);
	// // head = sa(head);
	//printf("pos 1: %d\npos 2: %d\npos 3: %d\n\n", head->val_a, head->next->val_a,  head->next->next->val_a );
	// return(0);
}