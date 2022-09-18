/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:42:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/18 23:43:42 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quicksort(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts)
{
	// bool end_b = false;
	// bool end_a = false;
    print_list(stack_a, "stack_a");
	print_list(stack_b, "stack_b");
    

    quick_to_b(stack_a, stack_b, a_starts, b_starts);
    print_list(stack_a, "stack_a");
	print_list(stack_b, "stack_b");
    print_list(a_starts, "a starts");
    print_list(b_starts, "b starts");
    
	while (list_len(stack_b) != 0 || stack_sorted(&stack_a) == false)
	{
        
		// end_b = quick_to_b(&stack_a, &stack_b, &a_starts, &b_starts);
		// end_a = quick_to_a(&stack_a, &stack_b, &a_starts, &b_starts);
	}
    return ;
}

void move_chunk_to_a()
{
    l_list *last_node = lst_last(stack_b);
    l_list *stop = second_last(b_starts);
    l_list *temp = stack_b;
    
    if(a_starts == NULL)
    {
        a_starts = new_node(stack_a->val);
    }
        // l_list *last_node = lst_last()
    if(range(stack_b, stop) < 5)
    {
        hardcode();
        return ;
    }
    while(stop->val != stack_b->val)
    {
        pivot = perfect_pivot(stack_b, prev(stack_b, second_last(b_starts)));
        while(temp->next != second_last(b_starts))
        {
            if(pivot <= temp->val)
            {
                temp = temp->next;
                pa(stack_a, stack_b);
            }
            else if(pivot > temp->val)
            {
                temp = temp->next;
                rb(stack_b, false);
            }
        }
    }
    // command rb pushed something to the end of stack b
    // solution that sucks and is mies inefficient but i'm too stupid for something better rn
    // pushes everything that is at the bottom again to the top of stack b ->> rrb
    if (last_node->next != NULL)
    {
        while (last_node->next != NULL)
        {
            last_node = last_node->next;
            rrb(&stack_b, false);
        }
        // replacing the last node of previouse b start with new b start
        lst_last(b_starts) = *stack_b;
        return (false);
    }
    (lst_last(a_starts))->next = new_node(stack_a->val);

}

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
}