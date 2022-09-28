/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marie_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:06 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/28 12:45:20 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void marie_sort(l_list** stack_a, l_list** stack_b, l_list** a_starts, l_list** b_starts, l_list**temp_b_starts)
{
    l_list *last_a = lst_last(*stack_a);
    l_list *b_down = NULL;
    printf(BLU"\nSTART MARIE ALGO\n"RESET);
    // print_list(stack_a, "STACKA A");
    // print_list(stack_b, "STACKA B");
    // print_list(a_starts, "A STARTS");
    // print_list(b_starts, "B STARTS");
    // print_list(temp_b_starts, "TEMP B STARTS");
    while((stack_sorted(stack_a) == false) || (list_len(*stack_b) != 0))
    {
        // special case
        // there is something above stack a && under stack a
        // push everything from under a to top of b
        if((*stack_a)->val != last_node_content(*a_starts) && lst_last(*stack_a) != last_a)
        {
            printf(GRN"CHECKER SPECIAL CASE\n"RESET);
            // return ;
            special_case(stack_a, stack_b, last_a, temp_b_starts, b_starts);
        }
        else if((*stack_a)->val != last_node_content(*a_starts))
        {
            printf(GRN"\nCHECKER ABOVE A\n\n"RESET);
            // return ;
            some_above_a(stack_a, stack_b, b_starts, temp_b_starts, a_starts);
        }
        else if(*b_starts == NULL && list_len(*stack_b) != 0)
        {
            print_list(stack_b, "stack b");
            printf(GRN"B STARTS EMPTY CASE\n\n"RESET);
            b_starts_empty(stack_a, stack_b, &b_down);
        }
        else if (lst_last(*stack_a) != last_a)
        {
            printf(GRN"CHECKER UNDER A\n"RESET);
            // return ;
            //hardcoding -> can be here cause down list dont need to be updated
            if (range(*stack_a, last_a->next, lst_last(*stack_a)) < 6)
                push_all_to_a("under_a", last_a->next, (lst_last(*stack_a))->next, stack_a, stack_b);
            else
                some_under_a(stack_a, stack_b, b_starts, temp_b_starts, a_starts);
        }
        else if((*stack_b)->val != last_node_content(*b_starts))
        {

            printf(GRN"CHECKER ABOVE B\n"RESET);
            some_above_b(&stack_a, &stack_b, &b_starts, &temp_b_starts, &b_down);
            // printf(YEL"DONE ABOVE B\n"RESET);
            // print_list(b_starts, "B STARTS");
            // print_list(a_starts, "A STARTS");
            // print_list(stack_a, "stack_a");
            // print_list(stack_b, "stack_b");
            // return ;
        }
        else if(*b_starts != lst_last(*stack_b))
        {
            printf(GRN"CHECKER UNDER B\n"RESET);
            // return ;
            printf("b starst: %d\n", (lst_last(*b_starts))->val);
            printf("last stack b: %d\n", (lst_last(*stack_b))->val);
            printf("range: %d\n", range(*stack_b, lst_last(*b_starts), lst_last(*stack_b)));
            some_under_b(stack_a, stack_b, &b_down, b_starts);
        }
        else 
        {
            printf(YEL"DELETED LAST IN B STARTS\n\n"RESET);
            del_last(b_starts);
        }
    }
}

void b_starts_empty(l_list** stack_a, l_list** stack_b, l_list**b_down)
{
    int pivot = 0;
    l_list *temp_b = NULL;
    if(range(*stack_b, *stack_b, lst_last(*stack_b)) < 6)
    {
        push_all_to_a("under_b", *stack_b, NULL, stack_a, stack_b);
        // deleting a list?
        return ;
    }
    if(*b_down == NULL)
    {
        pivot = perfect_pivot(*stack_b, lst_last(*stack_b));
        temp_b = *stack_b;
    }
    else if(*b_down != NULL)
    {
        pivot = perfect_pivot((lst_last(*b_down))->next, lst_last(*stack_b));
        temp_b = (lst_last(*b_down))->next;
    }
    while(temp_b != NULL)
    {
        if(temp_b->val > pivot)
        {
            temp_b = temp_b->next;
            // dunno lol
            rrb(stack_b, true);
        }
        else if(temp_b->val <= pivot)
        {
            temp_b = temp_b->next;
            rrb(stack_b, true);

        }
        
    }
    
}

// write hardcode func then done
void some_above_a(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts, l_list**a_starts)
{
    printf(GRN"------------ SOME ABOVE A -------------\n\n"RESET);
    int pivot = 0;
    if(range(*stack_a, *stack_a, prev(*stack_a, lst_last(*a_starts))) < 6)
    {
        
        hardcode_func(stack_a, stack_b, lst_last(*a_starts)); // add stack_a in a_starts
        // print_list(stack_a, "A BEFORE");
        // print_list(a_starts, "A STARST BEFORE");
        (lst_last(*a_starts))->next = new_node((*stack_a)->val); 
        print_list(stack_a, "A AFTER");
        print_list(a_starts, "A STARST AFTER");
        return ;
    }
    l_list *temp_a = *stack_a;
    
    if(*stack_a != lst_last(*b_starts) || *stack_a != lst_last(*temp_b_starts))
    {
        if(*temp_b_starts == NULL)
            *temp_b_starts = new_node((*stack_b)->val);
        else
            (lst_last(*temp_b_starts))->next = new_node((*stack_b)->val);
    }
    pivot = perfect_pivot(*stack_a, prev(*stack_a, lst_last(*a_starts)));
    while(temp_a != lst_last(*a_starts))
    {
        if(temp_a->val > pivot)
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


// DONE
void some_under_a(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts, l_list **a_starts)
{
    printf(GRN"------------ SOME UNDER A -------------\n\n"RESET);
    int pivot = 0;
    l_list *temp_a = *stack_a;

    if(*stack_b != lst_last(*b_starts) || *stack_b != lst_last(*temp_b_starts))
    {
        if(*temp_b_starts != NULL)
            *temp_b_starts = new_node((*stack_b)->val);
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
            pb(stack_a, stack_b);
        }
    }
    
}


// DONE
void some_above_b(l_list*** stack_a, l_list*** stack_b, l_list*** b_starts, l_list***temp_b_starts, l_list **b_down)
{
    printf(GRN"------------ SOME ABOVE B -------------\n\n"RESET);
    int pivot = 0;
    
    // can get hardcoded in stack a
    // either stuff in above stack b is under 5 digits or content of stack b chunk is under 5
    // CHECK: NO
    if((**temp_b_starts != NULL) && (range(**stack_b, **stack_b, prev(**stack_b, lst_last(**temp_b_starts))) < 5))
    {
        // push everything to top of a
        push_all_to_a("above_b", **stack_b, prev(**stack_b, lst_last(**temp_b_starts)), *stack_a, *stack_b);
        del_last(*temp_b_starts);
        return ;
    }
    else if(range(**stack_b, **stack_b, lst_last(**b_starts)) < 6)
    {
        printf(YEL"\n 2 CHECKER\n\n"RESET);
        // print_list(*stack_b, "stack b");
        // printf("lst last b starts: %d\n", (lst_last(**b_starts))->val);
        push_all_to_a("above_b", **stack_b, lst_last(**b_starts), *stack_a, *stack_b);
        // push_all_to_a("above_b", **stack_b, prev(**stack_b, lst_last(**b_starts)), *stack_a, *stack_b);
        // printf(YEL"\n 2 CHECKER\n\n"RESET);
        // print_list(*stack_a, "STACK A");
        // print_list(*stack_b, "STACK B");
        del_last(*b_starts);
        return ;

    }
        // printf(RED"\n CHECKER\n\n"RESET);
    
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
        pivot = perfect_pivot(**stack_b, second_last(**temp_b_starts));
    }
    else
    {
        // printf(YEL"NULL\n"RESET);
        // printf("stack b val: %d\n", (**stack_b)->val);
        // printf("lst last of b starts: %d\n", (lst_last(**b_starts))->val);
        // printf("prev of last b starts val: %d\n", (prev(**stack_b, lst_last(**b_starts)))->val);
        // printf(YEL"HEEERE NOW\n"RESET);
        pivot = perfect_pivot(**stack_b, lst_last(**b_starts));
        // printf("PIVOT: %d\n", pivot);

    }
    int stop = 0;
    // printf("PIVOT: %d\n", pivot);
    // printf("TEMP B: %d\n", temp_b->val);
    // printf("lst last: %d\n", (lst_last(**b_starts))->val);
    // while next start of b_starts occurs, or if there is something in temp_b_starts next starts there
    while(((temp_b->val != lst_last(**b_starts)->val)) && temp_b != NULL)// || (**temp_b_starts != NULL && temp_b != lst_last(**temp_b_starts)))
    {
    // printf("lst last: %d\n", (lst_last(**b_starts))->val);
    // printf("TEMP B: %d\n", temp_b->val);
        // printf("while\n");
        if(temp_b == NULL)
            printf(BLU"last seen\n"RESET);
        if(temp_b->val > pivot)
        {
            // push to top of a
        // printf(BLU"OKAZ\n"RESET);
            temp_b = temp_b->next;
            pa(*stack_a, *stack_b);
        }
        else if (temp_b->val <= pivot)
        {
            // push to bottom of a
            temp_b = temp_b->next;
            rb(*stack_b, true);
            // pa(*stack_a, *stack_b);
            // ra(*stack_a, true);
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
    
    printf(BLU"OUT\n"RESET);
    // if there was something in temp chunk, remove last content
    del_last(*temp_b_starts);
}


void some_under_b(l_list **stack_a, l_list **stack_b, l_list** b_down, l_list** b_starts)
{
    printf(GRN"------------ SOME UNDER B -------------\n\n"RESET);
    l_list *temp_b = NULL;
    int pivot = 0;
    // hardcode from b down
    l_list *delete = after(*stack_b, *b_starts);
        // printf("b starts next: %d\n", (after(*stack_b, *b_starts))->val);
        // printf("b starts last: %d\n", (lst_last(*stack_b))->val);
    print_list(b_starts, "B starst");
    if(*b_down != NULL && range(*stack_b, lst_last(*b_down), lst_last(*stack_b)) < 6)
    {
            push_all_to_a("under_b", lst_last(*b_down), lst_last(*stack_b), stack_a, stack_b);
            del_last(b_down);
            return ;
    }
    else if(*b_down == NULL && *b_starts!= NULL && range(*stack_b, lst_last(*b_starts), lst_last(*stack_b)) < 5)
    {
                    printf("b starst: %d\n", (lst_last(*b_starts))->val);
            printf("last stack b: %d\n", (lst_last(*stack_b))->val);
        push_all_to_a("under_a", (*b_starts)->next, lst_last(*b_starts), stack_a, stack_b);
        return ;
    }
    if(*b_down == NULL)
    {
        pivot = perfect_pivot((*b_starts)->next, lst_last(*stack_b));
        temp_b = (*b_starts)->next;
    }
    else if(*b_down != NULL)
    {
        pivot = perfect_pivot((lst_last(*b_down))->next, lst_last(*stack_b));
        temp_b = (lst_last(*b_down))->next;
    }
    // think there were different pushing rules but we are doing this for testing now
    while(temp_b != NULL)
    {
        temp_b = temp_b->next;
        rrb(stack_b, true);
        // if(temp_b->val > pivot)
        // {
        //     temp_b = temp_b->next;
        //     rrb(stack_b, true);
        //     pa(stack_a, stack_b);
        // }
        // else if(temp_b->val <= pivot)
        // {

        // }
    }
    del_last(b_down);
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
        // printf(GRN"pivot: %d\n"RESET, pivot);
        	// print_list(stack_a, "stack_a");
	// print_list(stack_b, "stack_b");
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
        
    // printf(GRN"ZEE\n"RESET);
    
    // first and second a stars ->> needs to be there
    *a_starts = new_node((lst_last(*stack_a))->val);
    (*a_starts)->next = new_node((*stack_a)->val);
    // print_list(stack_a, "stack a");
    // print_list(a_starts, "a starts");
    // temp_b_starts = new_node(last_nodes_content(b_starts));
    del_last(b_starts);
    
}
