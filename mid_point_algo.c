/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:42 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/11 18:39:59 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void create_list_c_start_and_c_end(l_list **stack_b, l_list **l_c_start, l_list **l_c_end)
{
	l_c_end = NULL;
	
	l_list *temp;
	temp = *l_c_start;
	while(temp != NULL)
		temp = temp->next;
	temp = new_node((*stack_b)->val);
	temp->next = NULL;

	// printf("l_c_start: %d\n", (*l_c_start)->val);
	print_list(l_c_start, "L C START");
}

// // c_   -> current start/end
// // l_c_ -> the LIST of all starts/ends
// void sort_stack_b(l_list **stack_a, l_list **stack_b)
// {
// 	// l_list *c_start = NULL;
// 	// l_list *c_end = NULL;

	
// 	printf("\n\nSORT STACK B\n");
//     print_list(stack_a, "stack_a");
//     print_list(stack_b, "stack_b");
	
// 	c_start = *stack_b;
// 	printf("c_start: %d\n", c_start->val);
	
// 	c_end = chunk_end(stack_b, c_start);
	
// }




// l_ -> always list
// c_ -> always chunk
void mid_point_algo(l_list **stack_a, l_list **stack_b)
{
	l_list *l_c_start = NULL;
	l_list *l_c_end = NULL;

	l_list *l_start = NULL;
	l_list *l_end = NULL;
    int count = 0;
    printf("before\n");
    print_list(stack_a, "stack_a");
    print_list(stack_b, "stack_b");
	
	while(list_len(*stack_a) > 2)
	{
		l_start = *stack_a;
		l_end = lst_last(*stack_a);
		int pivot = perfect_pivot(*stack_a, NULL);
		printf("pivot: %d\n", pivot);
		while (l_start->next != NULL && l_end->next != l_start)
		{
			if (pivot > l_start->val)
			{
				l_start = l_start->next;
				pb (stack_a, stack_b);
			}
			else if(pivot <= l_start->val)
			{
				// guard for stop loop if hitting piviot again
				if (l_start->val == pivot)
					count++;
				if (count > 1 && l_start->val == pivot)
					break ;
					
				l_start = l_start->next;
				ra (stack_a, true);
				l_end = l_end->next;
			}
			else
				l_start = l_start->next;
		}
		create_list_c_start_and_c_end(stack_b, &l_c_start, &l_c_end);
		count=0;
		
	}
	if(list_len(*stack_a) == 2)
	{
		if((*stack_a)->val > (*stack_a)->next->val)
			ra(stack_a, true);
	}
    // printf("\n\nafter\n");
    // print_list(stack_a, "stack_a");
    // print_list(stack_b, "stack_b");
	
	//sort_stack_b(stack_a, stack_b);
	
	
}


