/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:35:43 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/09 21:39:00 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count len from start to end
// works!!
int32_t lst_len_end(l_list *start, l_list *end)
{
    int count = 0;
    // should not happen i guess
    if(start == NULL)
    {
        printf("wrong in lst_len_end\n\n");//delete later
        return(0);
    }
    
    if (start == end)
        return(1);
        
    while(start != end && start != NULL)
    {
        count++;
        start = start->next;
    }
    // printf("count: %d\n", count);
    return(count);
}

bool is_sorted(int **array, int len_list)
{
    int i = 0;
    if (len_list == 1)
        return(true);
    while(len_list > 0)
    {
        // printf("array: %d\n", array[i]);
        if (array[0][i] > array[0][i+1])
            return(false);
        len_list--;
    }
    return(true);
}

// create array with content of list
// sort array
// find half
int32_t perfect_pivot(l_list *start, l_list *end)
{
    int i = 0;
    int len_list;
    len_list = lst_len_end(start, end);
    printf("len_ list %d\n", len_list);
    int *array; 
    array = (int *)malloc(sizeof(int) * len_list + 1);
    while(len_list-- > 0)
    {
        array[i] = start->val;
        printf("array: %d\n", array[i]);

        i++;
        start = start->next;
    }
    array[i] = '\0';
    len_list = i;
    printf("check\n");
    if(is_sorted(&array, len_list) == true)
        printf("ZESS\n");
    else if(is_sorted(&array, len_list) == false)
        printf("NOO\n");
    
    // while(is_sorted(array, len_list) == false)
    // {

    // }
    return(0);
}