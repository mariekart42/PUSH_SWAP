/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:28:29 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/18 15:56:49 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool quicksort(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts)
{
	bool end_b = false;
	bool end_a = false;
	while (end_b == false || end_a == false)
	{
		end_b = quick_to_b(&stack_a, &stack_b, &a_starts, &b_starts);
		end_a = quick_to_a(&stack_a, &stack_b, &a_starts, &b_starts);
	}
}

bool quick_to_a(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts)
{
    l_list *temp = NULL;
    int pivot = 0;
    l_list *last_node = lst_last(stack_b);
    
	if(*a_starts == NULL)
		a_starts = new_node((*stack_a)->val);
	// else
    //     (lst_last(a_starts))->next = new_node((*stack_a)->val);
    
    while(list_len(*stack_b) > 5) // guess more argument
    {
        temp = *stack_b;
        
        // if b_starts has less then 2 nodes, function returns NULL
        while(temp->next != second_last(&b_starts))
        {
            if(range(temp, second_last(&b_starts)) < 5)
            {
                hardcode()
                
            }
            // pivot of first chunk
            pivot = perfect_pivot(lst_last(*stack_b), prev(stack_b, second_last(&b_starts)));
            if(temp->val > pivot)
            {
                temp = temp->next;
                pa(stack_a, stack_b);
            }
            else if(temp->val <= pivot)
            {
                temp = temp->next;
                rb(stack_b, true);
            }
        }
        
        // edit a starts
        lst_last(a_starts)->next = new_node((*stack_a)->val);

        // command rb pushed something to the end of stack b
        // solution that sucks and is mies inefficient but i'm too stupid for something better rn
        // pushes everything that is at the bottom again to the top of stack b ->> rrb
        if(last_node->next == NULL)
        {
            while(last_node->next != NULL)
            {
                last_node = last_node->next;
                rrb(&stack_b, false);
            }
            // replacing the last node of previouse b start with new b start
            lst_last(b_starts) = *stack_b;
            return(false);
        }
        
        // something if current a chunk is unsorted send back to b
        
    }
    
		
}


bool quick_to_b(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts)
{
    print_list(stack_a, "stack_a");
    print_list(stack_b, "stack_b");
    print_list(a_starts, "a_starts");
    print_list(b_starts, "b_starts");
    printf("\nSTART QUICK TO B\n\n");
    int pivot = 0;
    l_list *temp = *stack_a;
	
	// for guarding that the same number will not hit twice
    // int count = 0;
    int64_t guard = 999999999999; //12 times 9, so no int val will ever be this

    // i the first iteration it will stop when everything besides max numbers is in stack b
    // in second an continue iteration will stop when current a_chunk is sorted
    while (list_len(*stack_a) > 4 )// || is_sorted(*stack_a, ))  >> add something for second iter
    {
        // finding pivot from start of stack a to the second last content of a_starts
        // second_last returns NULL if there is nothing
        pivot = perfect_pivot(*stack_a, second_last(*a_starts)); // or last node? ->> see in second iter
        printf(GRN"pivot: %d\n"RESET, pivot);
        
        //first iter last of a starts will be NULL
        // otherwise the last of a starts -> or has it to be second last -> look after second iter
        while (temp->next != lst_last(*a_starts))
        {
            printf(RED"\nITER\n\n"RESET);
            if (pivot > temp->val)
            {
                temp = temp->next;
                pb(stack_a, stack_b);
            }
            else if (pivot <= temp->val)
            {
				if(guard == temp->val)
					break ; // or return?
                if (guard == 999999999999)
					guard = temp->val;
                temp = temp->next;
                ra(stack_a, true);     
            }
        }
		guard = 999999999999;
		
        // if there is nothing in start
        if (*b_starts == NULL)
            *b_starts = new_node((*stack_b)->val);
        else
            (lst_last(*b_starts))->next = new_node((*stack_b)->val);
    }
	// hardcode cases
	if (list_len(*stack_a) == 3)
		hardcode_case_3(stack_a);
	else if (list_len(*stack_a) == 4)
		hardcode_case_4(stack_a);
	else if (list_len(*stack_a) == 2 && ((*stack_a)->val > (*stack_a)->next->val))
		ra(stack_a, true);
		

    print_list(stack_a, "stack_a");
    print_list(stack_b, "stack_b");
    print_list(a_starts, "a_starts");
    print_list(b_starts, "b_starts");
    printf("\nEND QUICK TO B\n\n");
		
	// final decider if stack a is complete ordered and stack b is empty
	if (is_sorted(stack_a, NULL) == true && list_len(stack_b) == 0)
		return(true);
	else
		return(false);
		
		
}