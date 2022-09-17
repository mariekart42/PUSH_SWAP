/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:42 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/17 17:48:57 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

//----------------------------------------------------------------------------------
//	          chunk 3     chunk 2        chunk 1
//	stack:  10 11 9  |  7 8 5 6  | 2 3 0 1 -5 4 -3
//             ^    ^     ^     ^    ^             ^
//   c_b_start -> |2|  -> |7| -> |10| -> NULL
//   c_b_end   -> |-3| -> |6| -> |9|  -> NULL
//
// function keeps track of each start and end value of each chunk that gets pushed from stack a to stack b
void create_list_start_end(l_list *stack, l_list **start, l_list **end)
{
	// if there is nothing in start and end
	if (*start == NULL)
	{
		*start = new_node(stack->val);
		*end = new_node(last_nodes_content(stack));
		return ;
	}
	
	// end
	l_list *temp = stack;
	while(temp->next->val != last_nodes_content(*start))
		temp = temp->next; 
	(lst_last(*end))->next = new_node(temp->val);
	
	// start
	(lst_last(*start))->next = new_node(stack->val);
}


void edit_list_start_end(l_list *stack, l_list **start, l_list **end)
{
	l_list *temp = stack;
	while(temp->val != stack->val)
		temp = temp->next;
	start++;
	end++;
		
	// delete last contents of both chunk lists and replace it with new val
	// if there is no new val or its under 5, just delete last content of both
	// chunk lists and use ggf hardcode cases
	
	
	// // c_b_start
	// (lst_last(*c_b_start)) = new_node(temp->next->val);

	// // c_b_end
	// (lst_last(*c_b_end)) = new_node(last_nodes_content(*stack_b));
}

void sort_stack_b(l_list **stack_a, l_list **stack_b, l_list **c_b_start, l_list **c_b_end)
{
	int pivot = 0;
	int count = 0;
	l_list *temp = *stack_b;
	l_list *c_a_start = new_node((*stack_a)->val);
	l_list *c_a_end = new_node(last_nodes_content(*stack_a));

	// printf("len list stack b: %d\n\n", list_len(*stack_b));
	while(list_len(*stack_b) > 4)
	{
		// printf(GRN"CHECK\n"RESET);
		// print_list(c_b_start, "c_b_start");
		printf("\nlast c end: %d\n", last_nodes_content(*c_b_end));
		printf("first c end: %d\n\n", last_nodes_content(*c_b_start));
		if(lst_is_sorted(stack_b, last_nodes_content(*c_b_end),last_nodes_content(*c_b_start)) == false)
		{
			// pivot should be right hopefully but check again later
			pivot = perfect_pivot(lst_last(*c_b_start), lst_last(*c_b_end));
			print_list(stack_b, "STACK_B");
			printf("PIVOT: %d\n", pivot);
			while(temp->next != second_last(*c_b_start) && temp->next != NULL)
			{
				if(pivot > temp->val)
				{
					temp = temp->next;
					
					// from top b to top a
					pa(stack_a, stack_b);
				}
				else if (pivot <= temp->val)
				{
					// guard for stop loop if hitting piviot again
					if(temp->val == pivot)
						count++;
					if(count > 1 && temp->val == pivot)
						break ;
					
					temp = temp->next;
					// shift first digit to bottom of b
					ra(stack_a, true);
				}
			}
			edit_list_start_end(*stack_b, c_b_start, c_b_end);
			print_list(c_b_end, "c_b_end");
			print_list(c_b_start, "c_b_start");
			count = 0;
		}
		
		

	}
	printf(RED"NOPE\n"RESET);
	stack_a++;
	c_b_end++;
	
	
	// hardcode cases for 2, 3 and 4
}


//----------------------------------------------------------------------------------
// l_ -> always list
// c_ -> always chunk
void mid_point_algo(l_list **stack_a, l_list **stack_b)
{
	l_list *c_b_start = NULL;
	l_list *c_b_end = NULL; // but both to main func so mid point algo can get called again

	l_list *l_start = NULL;
	l_list *l_end = NULL;
    int count = 0;
	
	while (list_len(*stack_a) > 4 && (!(is_sorted(stack_a, last_node(stack_a) == true && list_len(stack_b) == 0)))
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
			// should do nothing ??:
			else
				l_start = l_start->next;
		}
		create_list_start_end(*stack_b, &c_b_start, &c_b_end);
		count=0;
	}
	printf("\n======\nOUT WHILE LOOP\n=========\n");
	if (list_len(*stack_a) == 3)
		hardcode_case_3(stack_a);
	else if (list_len(*stack_a) == 4)
		hardcode_case_4(stack_a);
	else if (list_len(*stack_a) == 2 && ((*stack_a)->val > (*stack_a)->next->val))
		ra(stack_a, true);
	

	printf(RED"\n=========\nSORT STACK B\n=========\n\n"RESET);
	
	print_list(&c_b_start, "chunk start");
	print_list(&c_b_end, "chunk end");
	sort_stack_b(stack_a, stack_b, &c_b_start, &c_b_end);
	

	
    // printf("\n\nafter\n");
	// print_list(stack_a, "stack A");
	// print_list(stack, "stack B");

}


