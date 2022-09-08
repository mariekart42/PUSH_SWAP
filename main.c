/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/08 18:46:13 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking for valid arguments
// -> YEE no duplicates YEE
// -> YEE nothing else than numbers -> checking with argv YEE
// -> YEE integer max/min YEE

int32_t main(int32_t argc, char **argv) 
{
	l_list *stack_a = NULL;
	l_list *stack_b = NULL;

	if (checking(argv, argc) == false) // function returns 1 if something wrong, 0 if all right
	{
		write(2, "ERROR\n", 6); // printing error to standard error output
		exit(0);
	}
	// printf("check\n");
	stack_a = calloc(1, sizeof(l_list));
	stack_b = NULL;
	stack_a = create_list(argc, argv);

	printf("bool is sorted: %d\n", is_sorted(stack_a, NULL));

	// int dunno = sort(stack_a, NULL);
	// printf("perfect pivot: %d\n", dunno);
	


}

// // main without argv argc
// int32_t main(void)
// {
// 	l_list *stack_a = NULL;
// 	l_list *stack_b = NULL;

// 	stack_a = calloc(1, sizeof(l_list));
// 	stack_b = NULL;
	
// 	int32_t num = 6;
// 	int32_t array[num];
// 	array[0] = 1;
// 	array[1] = 4;
// 	array[2] = 6;
// 	array[3] = 2;
// 	array[4] = 7;
// 	array[5] = 3;

// 	stack_a = create_list_alone(num, array);

// 	int dunno = sort(stack_a, NULL);
// 	dunno++;


// 	print_list(&stack_a, "stack_a");
// 	print_list(&stack_b, "stack_b");
// 	first_sort_try(&stack_a, &stack_b);
// 	// rrr(&stack_a, &stack_b);
// 	print_list(&stack_a, "stack_a");
// 	print_list(&stack_b, "stack_b");
// }