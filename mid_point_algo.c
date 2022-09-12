/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:42 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/12 22:31:01 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// return false if something not right -> found duplicate
// add content of each start and end to the two lists "c_start" / "c_end" (c = chunk)
bool create_list_c_start_and_c_end(l_list *stack_b, l_list **c_start, l_list **c_end)
{	
	// chunk first
	// l_list *temp_temp = c_start_temp;
	

	
	l_list *temp;
	temp = lst_last(*c_start);
	
	static int iter = 1;
	printf("\n-----------------\nITER: %d\n\n", iter);
	iter++;
	if(stack_b->next == NULL || l_duplication(*c_start, stack_b->next->val) == true)
	{
		
		printf("SHOULD RETURN FALSE\n");
		return(true);
	}
	// if(l_duplication(*c_start, stack_b->val) == true)

	// int last_val = last_nodes_content(*c_start);
	// if(temp != NULL)
	// 	printf("HEEEERE: %d\n", temp->val);
	
	// if(*c_start == NULL)
	// {
	// 	(*c_start) = new_node(stack_b->val);
	// }
	int prev_start_val;
	if(*c_start == NULL)
	{
		*c_start = new_node(stack_b->val);
		prev_start_val = stack_b->val;
	}
	else
	{
		temp->next = new_node(stack_b->val);
		prev_start_val = temp->next->val;
	}
	// printf("new start %d\n", prev_start_val);
	

	// chunk last
	l_list *c_end_temp = stack_b;
	
	if (*c_end == NULL)
	{
		while(stack_b->next != NULL)
			stack_b = stack_b->next;
		*c_end = new_node(stack_b->val);
		return (true);
	}
	
	// printf("check BEFORE\n");
	// while(stack_b->next )
	// printf("prev start: %d\n", prev_start_val);
	int second_last_val = second_last(*c_start);
	// printf("!!!!!second last: %d\n", second_last_val);
	while(c_end_temp->next->val != second_last_val)
	{
	// printf("check IN\n");
		printf("c end : %d\n", c_end_temp->val);
		c_end_temp = c_end_temp->next;
	}
	
	// printf("check AFTER\n");
	temp = lst_last(*c_end);
	// printf("check\n");
	temp->next = new_node(c_end_temp->val);
	


	return(true);

	// print_list(c_start, "C START");
	// printf("last node c start: %d\n", last_nodes_content(*c_start));
	// figuring out last digit before hitting another start val

	

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
	l_list *c_start = NULL;
	l_list *c_end = NULL;

	l_list *l_start = NULL;
	l_list *l_end = NULL;
    int count = 0;
	
    // printf("before\n");
    // print_list(stack_a, "stack_a");
    // print_list(stack_b, "stack_b");
	
	while(list_len(*stack_a) > 2)
	{
		print_list(stack_a, "STACKKKKK_A");
		print_list(stack_b, "STACKKKKK_B");
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
		//checking if only one digit in list
		if (create_list_c_start_and_c_end(*stack_b, &c_start, &c_end) == false)
		{
			//means there is either only 
			printf("\nSHOULD END HERE\n\n");
			
		}
		print_list(&c_start, "C START");
		print_list(&c_end, "C END");
		count=0;
		
	}
	if(list_len(*stack_a) == 2)
	{
		if((*stack_a)->val > (*stack_a)->next->val)
			ra(stack_a, true);
	}
	
    printf("\n\nafter\n");
	print_list(&c_start, "chunk start");
	print_list(&c_end, "chunk end");



    // print_list(stack_a, "stack_a");
    // print_list(stack_b, "stack_b");
	
	//sort_stack_b(stack_a, stack_b);
	
	
}


