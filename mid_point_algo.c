/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:42 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/16 03:30:37 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//----------------------------------------------------------------------------------
//	          chunk 3     chunk 2        chunk 1
//	stack_b:  10 11 9  |  7 8 5 6  | 2 3 0 1 -5 4 -3
//             ^    ^     ^     ^    ^             ^
//   c_start -> |2|  -> |7| -> |10| -> NULL
//   c_end   -> |-3| -> |6| -> |9|  -> NULL
//
// function keeps track of each start and end value of each chunk that gets pushed from stack a to stack b
void create_list_c_start_and_c_end(l_list *stack_b, l_list **c_start, l_list **c_end)
{
	// if there is nothing in c_start and c_end
	if (*c_start == NULL)
	{
		*c_start = new_node(stack_b->val);
		*c_end = new_node(last_nodes_content(stack_b));
		return ;
	}
	
	// C_END
	l_list *temp = stack_b;
	while(temp->next->val != last_nodes_content(*c_start))
		temp = temp->next; 
	(lst_last(*c_end))->next = new_node(temp->val);
	
	// C_START
	(lst_last(*c_start))->next = new_node(stack_b->val);
}


//----------------------------------------------------------------------------------
// l_ -> always list
// c_ -> always chunk
void mid_point_algo(l_list **stack_a, l_list **stack_b)
{
	l_list *c_start = NULL;
	l_list *c_end = NULL;

	l_list *l_start = NULL;
	l_list *l_end = NULL;
    int count = 0;
	
	while (list_len(*stack_a) > 4)
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
		create_list_c_start_and_c_end(*stack_b, &c_start, &c_end);
		count=0;
	}
	printf("\n======\nOUT WHILE LOOP\n=========\n");
	if (list_len(*stack_a) == 3)
		hardcode_case_3(stack_a);
	else if (list_len(*stack_a) == 4)
		hardcode_case_4(stack_a);
	else if (list_len(*stack_a) == 2 && ((*stack_a)->val > (*stack_a)->next->val))
		ra(stack_a, true);
	else
		sort_stack_b();
	
    printf("\n\nafter\n");
	print_list(stack_a, "stack A");
	print_list(stack_b, "stack B");
	print_list(&c_start, "chunk start");
	print_list(&c_end, "chunk end");

	
}


