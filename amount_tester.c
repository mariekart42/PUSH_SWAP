/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amount_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:56:50 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/05 15:06:06 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void one()
{
    l_list *stack_a = NULL;
	l_list *stack_b = NULL;
    l_list *a_starts = NULL;
	l_list *b_starts = NULL;
	l_list *temp_b_starts = NULL;
    stack_a = calloc(1, sizeof(l_list));
	int32_t array[1];
	array[0] = 1;
	array[1] = 4;
    stack_a = create_list_alone(2, array);
    marie_sort(&stack_a, &stack_b, &a_starts, &b_starts, &temp_b_starts);
    printf(GRN"1 yes\n"RESET);
    
    
    
}

	array[2] = 6;
	array[3] = 2;
	array[4] = 7;
	array[5] = 3;
int main()
{
    one();
    
}