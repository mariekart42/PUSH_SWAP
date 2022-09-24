/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marie_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:12:30 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/21 14:13:25 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void marie_sort(l_list **stack_a, l_list ** stack_b, l_list** a_starts, l_list** b_starts)
{
    quick_to_b(stack_a, stack_b, a_starts, b_starts);
    
    // l_list *b_down = NULL;
    // no need for a down cause there is never more then one content
    
    l_list *last_a = lst_last(*stack_a);
    // l_list *last_b = lst_last(*stack_b);
    
    printf("last a :%d\n", last_a->val);
    
    print_list(stack_a, "stack a");
    print_list(stack_b, "stack b");
    print_list(a_starts, "a_starts");
    print_list(b_starts, "b_starts");
    
printf(BLU"\nAFTER\n\n"RESET);
    if((*stack_a)->val == (*a_starts)->val)
        printf("\nYES\n\n\n");

    

    // something above stack a && something under stack a
    // ->> push everything from bottom of a to top of b
    
    // else if something above a 
    // ->> higer half to bottom of a 
    // ->> smoler half to top b
    
    // else if something under a
    // ->> higer to top of a 
    // ->> smoler to top of b

    // else if something above b
    // ->> higer to top of a 
    // ->> smoler to bottom of b
    
    // else if something under b
    // ->> higer to top of a
    // ->> smoler to top of b
    
    // ELSE
    // delete last content of b_starts
}





// very first step
void quick_to_b(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts)
{
    int pivot = 0;
    l_list *temp = *stack_a;
	
	// for guarding that the same number will not hit twice
    int64_t guard = 999999999999; //12 times 9, so no int val will ever be this

    // i the first iteration it will stop when everything besides max numbers is in stack b
    // in second an continue iteration will stop when current a_chunk is sorted
    while (list_len(*stack_a) > 4)// || is_sorted(*stack_a, ))  >> add something for second iter
    {
        // finding pivot from start of stack a to the second last content of a_starts
        // second_last returns NULL if there is nothing
        // pivot = perfect_pivot(*stack_a, second_last(*a_starts)); // or last node? ->> see in second iter
        pivot = perfect_pivot(*stack_a, NULL);
        printf(GRN"pivot: %d\n"RESET, pivot);
        
        //first iter last of a starts will be NULL
        // otherwise the last of a starts -> or has it to be second last -> look after second iter
        // while (temp->next != lst_last(*a_starts))
        while (temp->next != NULL)
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
            *b_starts = new_node((lst_last(*stack_b))->val);
        else
            (lst_last(*b_starts))->next = new_node((lst_last(*stack_b))->val);
    }
	// hardcode cases
	if (list_len(*stack_a) == 3)
		hardcode_case_3(stack_a);
	else if (list_len(*stack_a) == 4)
		hardcode_case_4(stack_a);
	else if (list_len(*stack_a) == 2 && ((*stack_a)->val > (*stack_a)->next->val))
		ra(stack_a, true);
    *a_starts = new_node((*stack_a)->val);
}