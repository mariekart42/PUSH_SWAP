/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:42 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/11 16:19:47 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void mid_point_algo(l_list **stack_a, l_list **stack_b)
{
    int pivot = perfect_pivot(*stack_a, NULL);
	printf("pivot: %d\n", pivot);
    int count = 0;
    l_list *start = *stack_a;
    l_list *end = lst_last(*stack_a);
    printf("before\n");
    print_list(stack_a, "stack_a");
    print_list(stack_b, "stack_b");
    while (start->next != NULL && end->next != start)
    {
        if(pivot > start->val)
        {
            start = start->next;
            pb (stack_a, stack_b);
        }
        else if(pivot <= start->val)
        {
			// guard for stop loop if hitting piviot again
			if (start->val == pivot)
				count++;
			if (count > 1 && start->val == pivot)
				break ;
				
			start = start->next;
			ra (stack_a, true);
			end = end->next;
		}
		else
			start = start->next;
    }
    printf("\n\nafter\n");
    print_list(stack_a, "stack_a");
    print_list(stack_b, "stack_b");
}