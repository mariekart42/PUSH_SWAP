#include "push_swap.h"

// create list without passing argc argv -> here just for testing
l_list *create_list_alone(int32_t len, int32_t *content)
{
	l_list *temp = NULL;
	l_list *p = NULL;
	l_list *head = NULL;
	int32_t i = 0;
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

void print_list(l_list **list, char *name)
{
	printf("----------\n[%s]:\n", name);
	if(*list == NULL)
	{
		printf("list_pos_1: (NULL)\n");
		return ;
	}
	int32_t i = 1;
	l_list *node = NULL;
	node = (*list);
	while (node->next != NULL)
	{
		printf("list_pos_%d: %d\n", i, node->val);
		i++;
		node = node->next;
	}
	printf("list_pos_%d: %d\n", i, node->val);
	i++;
	if(node->next == NULL)
		printf("list_pos_%d: (NULL)\n", i);
	else	
		printf("something wrong! (print_list function)\n");
	printf("-- done --\n\n");
}