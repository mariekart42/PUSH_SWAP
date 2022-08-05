/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:35:09 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/05 12:11:37 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//fuction for each rule

// int sa()




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

// Node *add_at_end(Node *head, int val)
// {
// 	Node *temp;
// 	temp = (Node*)malloc(sizeof(Node));
// 	if(!temp)
// 		return(NULL);
// 	temp->next = NULL;
// 	temp->value = val;
// 	Node *lst;
// 	lst = head;
// 	while (lst->next != NULL)
// 	{
// 		lst = lst->next;
// 	}
// 	lst->next = temp;
	
// }

Node *new_node()
{
	Node *new;
	new = (Node*)malloc(sizeof(Node));
	if(!new)
		return(NULL);
	new->next = NULL;
	return(new);
}

Node *val_into_lst(Node *root, char **argv)
{
	Node *lst;
	lst = (Node*)malloc(sizeof(Node));
	if(!lst)
		return(NULL);
	lst = root;
	lst->next = NULL;
	printf("argv: %d\n", atoi(argv[1]));
	int i = 1;
	while(argv[i] != NULL)
	{
		lst->value = atoi(argv[i]);
		//printf("-->  lst->val: %d\n", lst->value);
		if(argv[i+1] != NULL)
		{
			lst->next = new_node();
			lst = lst->next;
		}
		i++;
	}
	lst->next = NULL;
	return(0);//just testting-> actually void?
}

int main(int argc, char *argv[])
{
	int i = 1;
	int dup_result = duplications(argv, argc);
	if(dup_result == -1)
	{
		printf("ERROR: num duplicate\n");
		return(0);//error message?
	}
//-------------------------------------------
	//creating linked list:
	Node *head = NULL;
	head = val_into_lst(head, argv);
	printf("argc: %d\n", argc);
	int test = 1;
	while(test < argc)
	{
	printf("Yeee\n");
		printf("head->value: %d\n", head->value);
		// head = head->next;
		test++;
	}
	
	// head = (Node*) malloc(sizeof(Node));
	// int k = 1;
	// while (argv[k] != NULL)
	// {
	// 	//printf("argv= %d\n", atoi(argv[k]));
	// 	head->value = atoi(argv[k]);
	// 	//printf("head->value: %d\n", head->value);
	// 	head = new_node(head->next);
	// 	k++;
	// }
	

//-------------------------------------------




	printf("result: %d\n", duplications(argv, argc));
	printf("argc= %d\n", argc);
	while (argv[i] != NULL)
	{
		// printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}	
}