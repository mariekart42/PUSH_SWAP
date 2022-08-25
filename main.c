/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/26 00:30:47 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking for valid arguments
// -> YEE no duplicates YEE
// -> YEE nothing else than numbers -> checking with argv YEE
// -> YEE integer max/min YEE
// ((-> how to quit when no input at all? -> if(argc < 2) do something))
//	-> not important cause its working anyways, maybe for algo later relevant

// int32_t main(int32_t argc, char **argv) 
// {
// 	l_list *stack_a = NULL;
// 	l_list *stack_b = NULL;

// 	if (checking(argv, argc)) // function returns 1 if something wrong, 0 if all right
// 	{
// 		printf("ERROR check faild\n");
// 		exit(0);
// 	}
// 	// printf("check\n");
// 	stack_a = calloc(1, sizeof(l_list));
// 	stack_b = NULL;
// 	stack_a = create_list(argc, argv);

// 	print_list(&stack_a, "stack_a");
// 	print_list(&stack_b, "stack_b");
// 	first_sort_try(stack_a, stack_b);
// 	// rrr(&stack_a, &stack_b);
// 	print_list(&stack_a, "stack_a");
// 	print_list(&stack_b, "stack_b");
// }

// main without argv argc
int32_t main(void)
{
	l_list *stack_a = NULL;
	l_list *stack_b = NULL;

	stack_a = calloc(1, sizeof(l_list));
	stack_b = NULL;
	
	int32_t num = 6;
	int32_t array[num];
	array[0] = 1;
	array[1] = 4;
	array[2] = 6;
	array[3] = 2;
	array[4] = 7;
	array[5] = 3;

	stack_a = create_list_alone(num, array);

	print_list(&stack_a, "stack_a");
	print_list(&stack_b, "stack_b");
	first_sort_try(&stack_a, &stack_b);
	// rrr(&stack_a, &stack_b);
	print_list(&stack_a, "stack_a");
	print_list(&stack_b, "stack_b");
}