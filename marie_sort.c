/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marie_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:12:30 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/21 20:57:14 by mmensing         ###   ########.fr       */
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
    
    //something under stack b && 
}



// very first step
void quick_to_b(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts)
{
    int pivot = 0;
    l_list *temp_a = *stack_a;
    l_list *tmp= new_node(-1);
    // l_list *temp_start = NULL;
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
        // while (temp_a->next != lst_last(*a_starts))
        while (temp_a->next != NULL)
        {
            // printf(RED"\nITER\n\n"RESET);
            if (pivot > temp_a->val)
            {
                temp_a = temp_a->next;
                pb(stack_a, stack_b);
            }
            else if (pivot <= temp_a->val)
            {
				if(guard == temp_a->val)
					break ; // or return?
                if (guard == 999999999999)
					guard = temp_a->val;
                temp_a = temp_a->next;
                ra(stack_a, true);     
            }
        }
print_list(stack_a, "stack a");
print_list(stack_b, "stack b");
print_list(a_starts, "a_starts");
print_list(b_starts, "b_starts");
		guard = 999999999999;
		
        create_b_starts(*stack_b, b_starts, tmp);
        lst_last(tmp)->next = new_node((*stack_b)->val); 
        // printf(BLU"CHECK\n"RESET);
    }
    // free all nodes of tmp start
    
	// hardcode cases
    hardcode(stack_a);
    *a_starts = new_node((lst_last(*stack_a))->val);
}