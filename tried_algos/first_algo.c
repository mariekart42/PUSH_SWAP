/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:24:30 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/07 17:38:22 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void algo_uno(l_list **stack_a, l_list **stack_b)
{
    l_list *current_node = NULL;
    l_list *last_node = NULL;
    // stack_b = NULL;
    current_node = *stack_a;
    
    last_node = lst_last(*stack_a);
   printf("before\n"); 
    // print_list(stack_b, "stack_b");
    print_list(stack_a, "stack_a");
    // printf("current_node: %d\nlast_node: %d\n", current_node->val, last_node->val);
    
    // as long as there is only one more element in stack_a
    while (list_len(*stack_a) > 1)
    {    
        // everything that is bigger then last number gets shifted
        // to stack_b
        while (last_node != *stack_a)
        {
        printf("LIST len: %d\n", list_len(*stack_a));
        printf("stack_a: %d\n", (*stack_a)->val);
            if(last_node->val > current_node->val)
            {
                current_node = current_node->next;
                pb(stack_a, stack_b);
            }
            else if(last_node->val < current_node->val)
            {
                current_node = current_node->next;
                ra(stack_a, 1);   
            }
            print_list(stack_a, "stack_a");
            print_list(stack_b, "stack_b");
        }
        last_node = lst_last(*stack_a);
    }
    // printf("after\n");
    // printf("stack_a: %d\n", (*stack_a)->val);
    // print_list(stack_a, "stack_a");
    // print_list(stack_b, "stack_b");
    
}