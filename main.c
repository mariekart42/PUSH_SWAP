/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/25 00:53:14 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking for valid arguments
// -> YEE no duplicates YEE
// -> nothing else than numbers -> checking with argv
// -> integer max/min
// -> how to quit when no input at all? -> if(argc < 2) do something

int32_t main(int32_t argc, unsigned char **argv) 
{
	l_list *stack_a = NULL;
	l_list *stack_b = NULL;

	// int check = 0;
	// check = only_nums(argv, argc);
	printf("## high number: %c\n", argv[0][0]);
	printf("## high number: %c\n", argv[1][0]);
	printf("## high number: %c\n", argv[2][0]);
	printf("## high number: %c\n", argv[2][1]);
	printf("## high number: %c\n", argv[2][2]);
	if (checking(argv, argc)) // function returns 1 if something wrong, 0 if all right
	{
		printf("ERROR check faild\n");
		exit(0);
	}
	printf("check\n");
	stack_a = calloc(1, sizeof(l_list));
	stack_b = NULL;
	stack_a = create_list(argc, argv);

	print_list(&stack_a, "stack_a");
	print_list(&stack_b, "stack_b");
	rrr(&stack_a, &stack_b);
	print_list(&stack_a, "stack_a");
	print_list(&stack_b, "stack_b");
}