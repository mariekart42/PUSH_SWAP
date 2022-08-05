/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:35:09 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/05 20:13:22 by mmensing         ###   ########.fr       */
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
Node* create_list(int len, char *argv[])
{
	Node *head = NULL;
	Node *temp = NULL;
	Node *p = NULL;
	int i = 0;
	while(i < len)
	{
		temp = (Node*)malloc(sizeof(Node));
		if(!temp)
			return(NULL);
		temp->next = NULL;
		temp->value = atoi(argv[i]);
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

int main(int argc, char *argv[])
{
	Node *stack_a = NULL;
	stack_a = create_list(argc - 1, argv);
	Node *stack_b = NULL;
	
	printf("len of list: %d\n", list_len(stack_a));
	// printf("pos 1: %d\npos 2: %d\npos 3: %d\n\n", head->value, head->next->value,  head->next->next->value );
	printf("check in main function\n");
	Node *test = NULL;
	test = sa(stack_a);
	// head = sa(head);
	// printf("pos 1: %d\npos 2: %d\npos 3: %d\n\n", head->value, head->next->value,  head->next->next->value );
	return(0);
}