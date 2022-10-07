/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marie_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:06 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/07 01:55:07 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void marie_sort(l_list** stack_a, l_list** stack_b, l_list** a_starts, l_list** b_starts, l_list**temp_b_starts)
{
    l_list *last_a = lst_last(*stack_a);
    l_list *b_down = NULL;
    // return;
    while((stack_sorted(stack_a) == false) || (list_len(*stack_b) != 0))
    {
        // there is something above stack a && under stack a
        // push everything from under a to top of b
        if((*stack_a)->val != last_node_content(*a_starts) && lst_last(*stack_a) != last_a)
        {
            special_case(stack_a, stack_b, last_a, temp_b_starts, b_starts);
        }
        else if((*stack_a)->val != last_node_content(*a_starts))
        {
            some_above_a(stack_a, stack_b, b_starts, temp_b_starts, a_starts);
        }
        else if (lst_last(*stack_a) != last_a)
        {
            //hardcoding -> can be here cause down list dont need to be updated
            // max 4 cause these are actually the nums we want to push
            if (range(*stack_a, last_a->next, lst_last(*stack_a)) <= 4)
                push_all_to_a("under_a", place(*stack_a, *a_starts), NULL, stack_a, stack_b);
            else
                some_under_a(stack_a, stack_b, b_starts, temp_b_starts, a_starts);
        }
        else if(*b_starts == NULL && list_len(*stack_b) != 0)
        {
            b_starts_empty(stack_a, stack_b, &b_down, b_starts);
        }
        else if((*stack_b)->val != last_node_content(*b_starts) && !(*b_starts != NULL && (*stack_b)->val < last_node_content(*stack_b)))
        {
            some_above_b(&stack_a, &stack_b, &b_starts, &temp_b_starts, &b_down);
        }
        else if((*b_starts)->val != (lst_last(*stack_b))->val)
        {
            some_under_b(stack_a, stack_b, &b_down, b_starts);
        }
        else 
        {
            del_last(b_starts);
            // return;
        }
    }
    // free_list(b_down);
}

void b_starts_empty(l_list** stack_a, l_list** stack_b, l_list**b_down, l_list**b_starts)
{
    int pivot = 0;
    l_list *temp_b = NULL;
    // very last digit maybe not 5
    if((*b_down == NULL && range(*stack_b, *stack_b, lst_last(*stack_b)) <= 4))
    {
        if(*b_down == NULL)
            push_all_to_a("make_b_empty", *stack_b, NULL, stack_a, stack_b);
        else if(*b_down != NULL)
            push_all_to_a("under_b", place(*stack_b, lst_last(*b_down)), NULL, stack_a, stack_b);
        del_last(b_down);
        return ;
    }
    else if(*b_down != NULL && range(*stack_b, (place(*stack_b, lst_last(*b_down)))->next, lst_last(*stack_b)) <= 4)
    {
        if(*b_down == NULL)
            push_all_to_a("make_b_empty", *stack_b, NULL, stack_a, stack_b);
        else if(*b_down != NULL)
            push_all_to_a("under_b", place(*stack_b, lst_last(*b_down)), NULL, stack_a, stack_b);
        del_last(b_down);
        return ;
        
    }
    int len = 0;
    if(*b_down == NULL)
    {
        pivot = perfect_pivot(*stack_b, NULL);
        temp_b = *stack_b;
        len = range(*stack_b, *stack_b, lst_last(*stack_b));
    }
    else if(*b_down != NULL)
    {
        pivot = perfect_pivot(place(*stack_b, (lst_last(*b_down)))->next, NULL);
        temp_b = (lst_last(*b_down))->next;
        len = range(*stack_b, lst_last(*b_down), lst_last(*stack_b)) - 1;
    }
    
    while(len > 0)
    {
        rrb(stack_b, true);
        if((*stack_b)->val > pivot)// do = sign and try
            pa(stack_a, stack_b);
        else if(*b_starts == NULL)
            *b_starts = new_node((*stack_b)->val);
        len--;
    }
    del_last(b_down);
}

// write hardcode func then done
void some_above_a(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts, l_list**a_starts)
{    
    int pivot = 0;
    // 6 cause we want max 4 but not the last digit including
    if(range(*stack_a, *stack_a, lst_last(*a_starts)) < 6)
    {
        hardcode_func(stack_a, stack_b, lst_last(*a_starts));
        // there is always something in a_starts
        (lst_last(*a_starts))->next = new_node((*stack_a)->val); 
        return ;
    }
    l_list *temp_a = *stack_a;
    
    // there is something above b
    // current number is not already in b_starts or temp_b_start
    if(*b_starts != NULL && *stack_b != place(*stack_b, lst_last(*b_starts)) && *stack_b != place(*stack_b, lst_last(*temp_b_starts)))
    {
        if(*temp_b_starts == NULL)
            *temp_b_starts = new_node((*stack_b)->val);
        else
            (lst_last(*temp_b_starts))->next = new_node((*stack_b)->val);
    }
    pivot = perfect_pivot(*stack_a, lst_last(*a_starts));
    while(temp_a->val != (lst_last(*a_starts))->val)
    {
        if(temp_a->val >= pivot)
        {
            temp_a = temp_a->next;
            ra(stack_a, true);
        }
        else if(temp_a->val < pivot)
        {
            temp_a = temp_a->next;
            pb(stack_a, stack_b);
            if (*b_starts == NULL)
                *b_starts = new_node((*stack_b)->val);
        }
    }
}


void some_under_a(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts, l_list **a_starts)
{
    int pivot = 0;
    l_list *temp_a = place(*stack_a, *a_starts);

    if(*stack_b != lst_last(*b_starts) || *stack_b != lst_last(*temp_b_starts))
    {
        if(*temp_b_starts == NULL)
            *temp_b_starts = new_node((*stack_b)->val);
        else
            (lst_last(*temp_b_starts))->next = new_node((*stack_b)->val);
    }
    pivot = perfect_pivot((place(*stack_a, *a_starts))->next, NULL);
    while(temp_a->next != NULL)
    {
        rra(stack_a, stack_b);
        if((*stack_a)->val <= pivot) // TRY rm the = sign
            pb(stack_a, stack_b);
    }
}


void some_above_b(l_list*** stack_a, l_list*** stack_b, l_list*** b_starts, l_list***temp_b_starts, l_list **b_down)
{
    printf(GRN"------------ SOME ABOVE B -------------\n\n"RESET);
    int pivot = 0;

    // the stuff between top of b to [excluding] last node of temp b_starts is max 4
    // 5 cause last node gets not pushed in if statement
    //if((**temp_b_starts != NULL) && (range(**stack_b, **stack_b, prev(**stack_b, lst_last(**temp_b_starts))) <= 5))
    if((**temp_b_starts != NULL) && (range(**stack_b, **stack_b, prev(**stack_b, lst_last(**temp_b_starts))) <= 4))
    {
        // push everything from top of b till [excluding] last node of temp_b_starts to a
        push_all_to_a("above_b", **stack_b, place(**stack_b, lst_last(**temp_b_starts)), *stack_a, *stack_b);
        del_last(*temp_b_starts);
        return ;
    }
    
    // maybe problem here cause if b starts has one last digit
    // first: we dont push very first b_starts so number can be 5 but we actually just push 4
    // second: if there is the very last b_starts we want to push it as well
    //         -> number has to be 4
    
    // else if(range(**stack_b, **stack_b, lst_last(**b_starts)) < 5)
    else if((list_len(**b_starts) > 1 && range(**stack_b, **stack_b, lst_last(**b_starts)) <= 5) || (list_len(**b_starts) == 1 && range(**stack_b, **stack_b, lst_last(**b_starts)) <= 4))
    {
        // push all to a -> from stack_b till [excluding] last node of b_starts
        push_all_to_a("above_b", **stack_b, place(**stack_b, lst_last(**b_starts)), *stack_a, *stack_b);
        
        // if we reach very last digit of above b
        //  -> special case and we push it as well
        if((**stack_b)->val == (**b_starts)->val)
        {
            pa(*stack_a, *stack_b);
            del_last(*b_starts); // THIS IS NEW
        }
        return ;
    }

    // if there is already something under b -> updating b_down list
    if((**b_starts)->val != (lst_last(**stack_b))->val)
    {
        if(*b_down == NULL)
            *b_down = new_node(last_node_content(**stack_b));
        else
            (lst_last(*b_down))->next = new_node(last_node_content(**stack_b));
    }
    l_list *temp_b = **stack_b;
    
    // either pivot for chunk in temp starts, or pivot in actual b_starts chunk 
    if(**temp_b_starts != NULL)
    {
        printf(YEL"NOT NULL"RESET);
        // CHANGED HERE
        pivot = perfect_pivot(**stack_b, lst_last(**temp_b_starts));
    }
    else if (list_len(**b_starts) == 1)
        pivot = perfect_pivot(**stack_b, (place(**stack_b, lst_last(**b_starts)))->next);
    else
        pivot = perfect_pivot(**stack_b, lst_last(**b_starts));
    

    // while next start of b_starts occurs, or if there is something in temp_b_starts next starts there
    while(temp_b != NULL && temp_b->val != lst_last(**b_starts)->val)
    {
        if(**temp_b_starts != NULL && temp_b->val == lst_last(**temp_b_starts)->val)
        {
            break ;
        }
        if(temp_b->val >= pivot)
        {
            temp_b = temp_b->next;
            pa(*stack_a, *stack_b);
        }
        else if (temp_b->val < pivot)
        {
            // push to bottom of b
            temp_b = temp_b->next;
            rb(*stack_b, true);
        }
    }
    // hitting the beginning of b_starts
    if(temp_b->val == (**b_starts)->val)
    {
        del_last(*b_starts);
        if(temp_b->val > pivot)
            pa(*stack_a, *stack_b);
        else
            rb(*stack_b, true);
    }
    // if there was something in temp chunk, remove last content
    del_last(*temp_b_starts);
}


void some_under_b(l_list **stack_a, l_list **stack_b, l_list** b_down, l_list** b_starts)
{
    printf(GRN"------------ SOME UNDER B -------------\n\n"RESET);
    l_list *temp_b = NULL;
    int pivot = 0;

    // 5 cause we dont want to push the very first digit (lst_last(b_down))
    if(*b_down != NULL && range(*stack_b, lst_last(*b_down), lst_last(*stack_b)) <= 5)
    {
        push_all_to_a("under_b", place(*stack_b, lst_last(*b_down)), NULL, stack_a, stack_b);
        del_last(b_down);
        return ;
    }
    else if(*b_down == NULL && *b_starts!= NULL && range(*stack_b, place(*stack_b, *b_starts)->next, lst_last(*stack_b)) < 5)
    {
        push_all_to_a("under_b", place(*stack_b, *b_starts), NULL, stack_a, stack_b);
        return ;
    }
    if(*b_down == NULL)
    {
        pivot = perfect_pivot((place(*stack_b, *b_starts))->next, NULL);
        temp_b = (place(*stack_b, *b_starts))->next;
    }
    else if(*b_down != NULL)
    {
        pivot = perfect_pivot((place(*stack_b, lst_last(*b_down)))->next, NULL);
        temp_b = (place(*stack_b, lst_last(*b_down)))->next;
    }
    while(temp_b->next != NULL)
    {
        // temp_b = temp_b->next;
        rrb(stack_b, true);
    }
    rrb(stack_b, true);
    
    del_last(b_down);
}




// very first step
void quick_to_b(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts)
{
    int pivot = 0;
    l_list *temp_a = *stack_a;
    
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

        //first iter last of a starts will be NULL
        // otherwise the last of a starts -> or has it to be second last -> look after second iter
        // while (temp->next != lst_last(*a_starts))
        while (temp_a->next != NULL)
        {
            if (pivot > temp_a->val)
            {
                temp_a = temp_a->next;
                pb(stack_a, stack_b);
            }
            else if (pivot <= temp_a->val)
            {
				if(guard == temp_a->val)
					break ;
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
            
    // first and second a stars ->> needs to be there
    *a_starts = new_node((lst_last(*stack_a))->val);
    (*a_starts)->next = new_node((*stack_a)->val);
    del_last(b_starts);
}
