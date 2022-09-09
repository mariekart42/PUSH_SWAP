/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:52:49 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/09 20:34:39 by mmensing         ###   ########.fr       */
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
    while (start->next != end)
    {
        if (start->val > start->next->val)
            return(false);
        start = start->next; 
    }
    return (true);
}

// head will never be NULL
char *create_array(l_list *head)
{
    int len = list_len(head);
    printf("len: %d\n", len);
    char *test = NULL;
    return(test);
}


l_list *lst_list(l_list *content, l_list *end)
{
    l_list *temp = NULL;
    l_list *head = NULL;
	l_list *p = NULL;
    if(end == NULL)
        printf("is NULL\n");
    // printf("end->val: %d\n",end->val);
    
    while(content != NULL && content != end)
    {
		temp = (l_list *)malloc(sizeof(l_list));
		if (!temp)
			return (NULL);
		temp->next = NULL;
		temp->val = content->val;
		if (head == NULL)
			head = temp;
		else
		{
			if (p == NULL)
				p = head;//p at the beginning just head
			else
				p = p->next;//p is the previouse position
			p->next = temp; // temp contains value  we want
		}		
		temp = temp->next;
        content = content->next;
    }
    return(head);
}

// fuction sorts given chunk of array and calculates
// perfect piviot
int32_t perfect_pivot(l_list *start, l_list *end)
{
    l_list *temp;
    printf("1 check\n");
    temp = lst_list(start, end);
    print_list(&temp, "TEMP");
    printf("2 check\n");
    while (is_sorted(temp, end) == false)
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