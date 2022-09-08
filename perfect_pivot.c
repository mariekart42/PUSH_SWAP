/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:52:49 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/08 17:14:27 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"push_swap.h"

void lst_swap(l_list *head_a, l_list *head_b)
{
    int temp;
    
    temp = head_a->val;
    head_a->val = head_b->val;
    head_b->val = temp;
}

// function checks if contend is sorted
bool is_sorted(l_list *start, l_list *end)
{
    while(start->next != end)
    {
        if(start->val > start->next->val)
            return(false);
        start = start->next;    
    }
    return(true);
}

// fuction sorts given chunk of array and calculates
// perfect piviot
int32_t perfect_pivot(l_list *start, l_list *end)
{
    l_list *temp = NULL;
    temp = start;
    while (is_sorted(start, end) == false)
    {
        while (temp->next != end)
        {
            if (temp->val > temp->next->val)
                lst_swap(temp, temp->next);
            temp = temp->next;
        }
        temp = start;
    }
    // print_list(&start, "start");
    return(val_half_list(start, end));
}

// function calculates the number in middle of list
// eg. list:   2 5 12 3 4
//                 ˆˆ
// -> function returns 12
// 'end' is the last number of chunk we wanna check
int32_t val_half_list(l_list *head, l_list *end)
{
    int len = 0; // len of list
    l_list *temp = head;
    int half_len = 0;
    int count = 1;

    while (temp != end)
    {
        temp = temp->next;
        len++;
    }
    if ((len % 2) == 0)
        half_len = len / 2;
    else if ((len % 2) != 0)
        half_len = (len + 1) / 2;
    while (half_len > count)
    {
        if (head == end)
            break;
        head = head->next;
        count++;
    }
    return (head->val);
}
// WORKS