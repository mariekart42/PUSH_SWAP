#include "push_swap.h"

// create list without passing argc argv
l_list *create_list_alone(int len, int *content)
{
	l_list *temp = NULL;
	l_list *p = NULL;
	l_list *head = NULL;
	int i = 0;
	while (i < len)
	{
		temp = (l_list *)malloc(sizeof(l_list));
		if (!temp)
			return (NULL);
		temp->next = NULL;
		temp->val = content[i];
		if (head == NULL)
			head = temp;
		else
		{
			if(p == NULL)
				p = head;//p at the beginning just head
			else
				p = p->next;//p is the previouse position
			p->next = temp; // temp contains value  we want
		}		
		i++;
	}
	return(head);
}