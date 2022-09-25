/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marie_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:06 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/25 15:03:13 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void marie_sort(l_list** stack_a, l_list** stack_b, l_list** a_starts, l_list** b_starts, l_list**temp_b_starts)
{
    l_list *last_a = lst_last(*stack_a);
    l_list *b_down = NULL;
    while((stack_sorted(stack_a) == false) || (list_len(*stack_b) != 0))
    {
        // special case
        // there is something above stack a && under stack a
        if((*stack_a)->val != last_node_content(*a_starts) && lst_last(stack_a) != last_a)
        {
            special_case();
        }
        else if((*stack_a)->val != last_node_content(*a_starts))
        {
            some_above_a(stack_a, stack_b, b_starts, temp_b_starts, a_starts);
        }
        else if (lst_last(*stack_a) != last_a)
        {
                //hardcoding
            if(range(last_a->next, lst_last(*stack_a)) < 5)
            {
                push_all_to_a("under_a", stack_a, stack_b);
                
            }
            some_under_a(stack_a, stack_b, b_starts, temp_b_starts);
        }
        else if((*stack_b)->val != last_node_content(*b_starts))
        {
            some_above_b(stack_a, stack_b, b_starts, temp_b_starts, b_down);
        }
        else if(*b_starts != lst_last(*stack_b))
        {
            some_under_b();
        }
        else 
            del_last(b_starts);
    }
}

void some_above_a(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts, l_list**a_starts)
{
    int pivot = 0;
    if(range(*stack_a, prev(*stack_a, lst_last(a_starts))) < 5)
    {
        hardcode_func(); // add stack_a in a_starts
        return ;
    }
    l_list *temp_a = *stack_a;
    
    if(*stack_a != lst_last(*b_starts) || *stack_a != lst_last(temp_b_starts))
    {
        if(temp_b_starts == NULL)
            temp_b_starts = new_node((*stack_b)->val);
        else
            (lst_last(temp_b_starts))->next = new_node((*stack_b)->val);
    }
    
    pivot = perfect_pivot(*stack_a, prev(*stack_a, lst_last(*a_starts)));
    while(temp_a != lst_last(*a_starts))
    {
        if(temp->val > pivot)
        {
            temp_a = temp_a->next;
            ra(stack_a, true);
        }
        else if(temp_a->val <= pivot)
        {
            temp_a = temp_a->next;
            pb(stack_a, stack_b);
        }
    }
}

void push_all_to_a(char *from, l_list**start, l_list** end, l_list **stack_a, l_list** stack_b)
{
    l_list *temp = *start;
    if(ft_strncmp(from, "under_a") == 0)
    {
        while(temp != end)
        {
            temp = temp->next;
            rra(stack_a, true);
        }
    }
    if(ft_strncmp(from, "under_b") == 0)
    if(ft_strncmp(from, "above_b") == 0)
}

void some_under_a(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts)
{
    l_list *temp_a = *stack_a;

    if(*stack_b != lst_last(*b_starts) || *stack_b != lst(last(temp_b_starts))
    {
        if(temp_b_starts != NULL)
            temp_b_starts = new_node((*stack_b)->val);
        else
            (lst_last(*temp_b_starts))->next = new_node((*stack_a)->val);
    }
    pivot = perfect_pivot(*stack_a, prev(*stack_a, lst_last(*a_starts)));
    while(temp_a != lst_last(*a_starts))
    {
        if(temp_a->val > pivot)
        {
            temp_a = temp_a->next;
            rra(stack_a, stack_b);
        }
        else if(temp_a->val <= pivot)
        {
            temp_a = temp_a->next;
            rra(stack_a, true);
            pb(*stack_a, stack_b);
        }
    }
    
}
void some_above_b(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts, l_list **b_down)
{
    // can get hardcoded in stack a
    // either stuff in above stack b is under 5 digits or content of stack b chunk is under 5
    if((temp_b_starts != NULL && range(*stack_b, prev(*stack_b, lst_last(temp_b_starts))) < 5) 
        || range(*stack_b, prev(*stack_b, lst_last(b_starts))) < 5)
    {
        // push everything to top of a
        hardcode_func(); // add a_starts
        if(temp_b_starts == NULL)
            del_last(b_starts);
        else
            del_last(temp_b_starts);
        return ;
    }
    // if there is already something under b -> updating b_down list
    if(*b_starts != lst_last(*stack_b))
    {
        if(*b_down == NULL)
            down_b = new_node(last_nodes_content(*stack_b));
        else
            (lst_last(*down_b))->next = new_node(last_node_content(*stack_b))
    }
    l_list = temp_b = *stack_b;
    
    // either pivot for chunk in temp starts, or pivot in actual b_starts chunk
    if(temp_b_starts != NULL)
        pivot = perfect_pivot(*stack_b, prev(*stack_b, second_last(temp_b_starts));
    else
        pivot = perfect_pivot(*stack_b, prev(*stack_b, lst_last(b_starts)));
    // while next start of b_starts occurs, or if there is something in temp_b_starts next starts there
    while((temp_b != lst_last(b_starts)) || (temp_b_starts != NULL && temp_b != lst_last(temp_b_starts)))
    {
        if(temp_b->val > pivot)
        {
            // push to top of a
            temp_b = temp_b->next;
            pa(stack_a, stack_b);
        }
        else if (temp_b->val <= pivot)
        {
            // push to bottom of a
            temp_b = temp_b->next;
            pa(stack_a, stack_b);
            ra(stack_a, false);
        }
    }
    // if there was something in temp chunk, remove last content
    del_last(temp_b_starts);
}




// very first step
void quick_to_b(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts)
{
    int pivot = 0;
    l_list *temp_a = *stack_a;
	// l_list *first_a = *stack_a;
    
	// for guarding that the same number will not hit twice
    int64_t guard = 999999999999; //12 times 9, so no int val will ever be this

    // i the first iteration it will stop when everything besides max numbers is in stack b
    // in second an continue iteration will stop when current a_chunk is sorted
    // while(temp_a->next != NULL)
    while (list_len(*stack_a) > 4)// || is_sorted(*stack_a, ))  >> add something for second iter
    {
        // finding pivot from start of stack a to the second last content of a_starts
        // second_last returns NULL if there is nothing
        // pivot = perfect_pivot(*stack_a, second_last(*a_starts)); // or last node? ->> see in second iter
        pivot = perfect_pivot(*stack_a, NULL);
        printf(GRN"pivot: %d\n"RESET, pivot);
        	print_list(stack_a, "stack_a");
	print_list(stack_b, "stack_b");
        //first iter last of a starts will be NULL
        // otherwise the last of a starts -> or has it to be second last -> look after second iter
        // while (temp->next != lst_last(*a_starts))
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
		guard = 999999999999;
		
        // if there is nothing in start
        if (*b_starts == NULL)
            *b_starts = new_node((lst_last(*stack_b))->val);
        (lst_last(*b_starts))->next = new_node((*stack_b)->val);
    }
	// hardcode cases
	if (list_len(*stack_a) == 3)
		hardcode_case_3(stack_a);
	else if (list_len(*stack_a) == 4)
		hardcode_case_4(stack_a);
	else if (list_len(*stack_a) == 2 && ((*stack_a)->val > (*stack_a)->next->val))
		ra(stack_a, true);
        
    *a_starts = new_node((lst_last(*stack_a))->val);
    printf(GRN"ZEE\n"RESET);
    (*a_starts)->next = new_node((*stack_a)->val);
    // temp_b_starts = new_node(last_nodes_content(b_starts));
    del_last(b_starts);
}
