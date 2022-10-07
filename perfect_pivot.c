/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:35:43 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/07 13:00:01 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// create array with content of list
// sort array
// find half
// pivot every time the bigger one!
int32_t perfect_pivot(l_list *start, l_list *end)
{
    int i = 0;
    int len_list;
    len_list = lst_len_end(&start, &end);
    int temp;
    int array[len_list +1];
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
    temp = half_list_val(array, len_list);
    return (temp);
}


// count len from start to end
int32_t lst_len_end(l_list **start, l_list **end)
{
    l_list *temp = *start;
    int count = 0;
    if(temp == NULL)
        return(0);
    if (temp == *end)
        return(1);
    if(*end == NULL)
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return (count);
    }
    while(temp->val != (*end)->val)
    {
        count++;
        temp = temp->next;
    }
    return(count);
}


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


