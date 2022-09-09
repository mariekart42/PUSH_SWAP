/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:42 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/10 00:58:11 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void mid_point_algo(l_list **stack_a, l_list **stack_b)
{
    int pivot;


    pivot = perfect_pivot(*stack_a, NULL);
    stack_b++;
    
    printf("perfect pivot: %d\n", pivot);
    
    // l_list *temp_a = *stack_a;
    // last_node = lst_last(*stack_a);
    // while(is_sorted(*stack_a, lst_last(*stack_a)) == false || list_len(*stack_b) > 1) //quit while loop if list is sorted
    // {        
    //     if(pivot > temp_a->val)
    //     {
    //         temp_a = temp_a->next;
    //         pb(stack_a, stack_b);
    //     }
    //     else if(pivot < temp_a->val)
    //     {
    //         temp_a = temp_a->next;
    //         ra(stack_a, true);
    //     }
    //     else
    //         temp_a = temp_a->next; 
    // print_list(stack_a, "stack_a");
    // print_list(stack_b, "stack_b");
    // }
}