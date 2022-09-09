#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h> // int32_t
typedef struct l_list 
{
    int val;
    struct l_list *next;
} l_list;
void lst_swap(l_list *head_a, l_list *head_b)
{
    int temp;
    
    temp = head_a->val;
    head_a->val = head_b->val;
    head_b->val = temp;
}

char *create_array(l_list *start, l_list *end)
{
    
}

l_list *lst_list(l_list *content, l_list *end)
{
    l_list *temp = NULL;
    l_list *head = NULL;
    l_list *p = NULL;
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
int32_t perfect_pivot(l_list *start, l_list *end)
{
    l_list *temp;
    temp = lst_list(start, end);
    int i = 0;
    while (i < 5)
    {
        while (temp->next != end)
        {
            if (temp->val > temp->next->val)
                lst_swap(temp, temp->next);
            temp = temp->next;
        }
        temp = start;
    }
    return(1);
}
int32_t main(void)
{
    l_list *stack_b = NULL;
    l_list *temp1 = NULL;
    l_list *temp2 = NULL;
    l_list *temp3 = NULL;
    temp1 = (l_list *)malloc(sizeof(l_list));
    temp2 = (l_list *)malloc(sizeof(l_list));
    temp3 = (l_list *)malloc(sizeof(l_list));
    temp1->val = 7;
    temp2->val = 1;
    temp3->val = 3;
    temp3->next=NULL;
    temp1->next = temp2;
    temp2->next = temp3;

    int pivot;
    pivot = perfect_pivot(temp1, NULL);
}