/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/24 01:01:32 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking for valid arguments
// -> no duplicates
// -> nothing else than numbers
// -> integer max/min

int main(int argc, char *argv[]) 
{
	l_list *stack_a = NULL;
	l_list *stack_b = NULL;

	stack_a = calloc(1, sizeof(l_list));
	stack_b = NULL;
	//checking content
	if(create_and_check_list(&stack_a, argv, argc)) // create function that returns 1 if something is not right
		exit(0);
}