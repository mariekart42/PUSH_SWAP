#include "push_swap.h"

stack_a *add_node_at_beginning(stack_a *head, int value)
{
    stack_a *temp = NULL;
    temp = head;
    stack_a *node = NULL;
    node = (stack_a *)malloc(sizeof(stack_a)); 
    head = node;
    node->val_a = value;
    node->next = temp;
    return(head); 
}

stack_a *create_list(int argc, char *content)
{
	stack_a *head = NULL;
	stack_a *temp = NULL;
	stack_a *p = NULL;

	int i = 0;
	while(argc > i)
	{
		printf("iter: %d\n", i);
		temp = (stack_a *)malloc(sizeof(stack_a));
		if(!temp)
			return(NULL);
		temp->val_a = content[i];
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

int main(void)
{
	stack_a *head = NULL;
	char array[4] = {2, 4, 6, 8};
	head = create_list(4, array);
	printf("before:\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\n\n", head->val_a, head->next->val_a, head->next->next->val_a, head->next->next->next->val_a);
	printf("after:\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\n\n", head->val_a, head->next->val_a, head->next->next->val_a, head->next->next->next->val_a);

	head = add_node_at_beginning(head, 9);
	printf("\nSECOND:\nbefore:\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\npos 5: %d\n\n", head->val_a, head->next->val_a, head->next->next->val_a, head->next->next->next->val_a, head->next->next->next->next->val_a);
	printf("after:\npos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\npos 5: %d\n\n", head->val_a, head->next->val_a, head->next->next->val_a, head->next->next->next->val_a, head->next->next->next->next->val_a);
}

