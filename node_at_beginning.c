#include "push_swap.h"

// stack_a *add_node_at_beginning(stack_a *node, int value)
// {
// 	stack_a *temp;
// 	temp = (stack_a*)malloc(sizeof(stack_a)); 
// 	temp = head->next;
// 	head->next = node;
// 	node->next = temp;
// }

stack_a *create_list(int argc, char **value)
{
	stack_a *head = NULL;
	stack_a *temp = NULL;
	stack_a *p = NULL;

	int i = 1;
	while(argc > i)
	{
		temp = (stack_a*)malloc(sizeof(stack_a));
		if(!temp)
			return(NULL);
		temp->val_a = atoi(value[i]);
		temp->next = NULL;
		if(head == NULL)
			head = temp;
		else
		{
			if(p == NULL)
				p = head;
			else
				p = p->next;
			p->next = temp;
		}
		i++;
	}
	return(head);
}

int main(int argc, char *argv[])
{
	stack_a *head = NULL;
	head = create_list(argc, argv);
	printf("before:\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\n\n", head->next->val_a, head->next->next->val_a, head->next->next->next->val_a, head->next->next->next->next->val_a);
	printf("after:\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\n\n", head->next->val_a, head->next->next->val_a, head->next->next->next->val_a, head->next->next->next->next->val_a);
}