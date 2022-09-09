/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:35:43 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/10 00:54:19 by mmensing         ###   ########.fr       */
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

bool is_sorted(int *array, int len_list)
{
    int i = 0;
    if (len_list == 1)
        return(true);
    while(len_list - 1 > 0)
    {
        if (array[i] > array[i+1])
            return(false);
        len_list--;
        i++;
    }
    return(true);
}
// WORKS


int32_t half_list_val(int *array, int len_list)
{
    int32_t half_len = 0;
    
    if(len_list == 1)
        return(array[0]);
        
    if ((len_list % 2) == 0)
        half_len = len_list / 2;
    else if ((len_list % 2) != 0)
        half_len = (len_list - 1) / 2;
    return(array[half_len]);
}

// create array with content of list
// sort array
// find half
int32_t perfect_pivot(l_list *start, l_list *end)
{
    int i = 0;
    int len_list;
    len_list = lst_len_end(start, end);
    int temp;
    int *array; 
    array = (int *)malloc(sizeof(int) * len_list + 1);
    while(len_list > 0)
    {
        array[i] = start->val;
        len_list--;
        i++;
        start = start->next;
    }
    array[i] = '\0';
    len_list = i;
    i = 0;
    while(is_sorted(array, len_list) == false)
    {
        while(len_list - 1 > i)
        {
            if (array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
            i++;
        }
        i=0;
    }
    return(half_list_val(array, len_list));
}