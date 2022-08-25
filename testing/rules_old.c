/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:35:35 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/09 15:42:31 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


// function creates linked list and adds content to it
stack_a *create_list(int len, char *array)
{
	stack_a *temp = NULL;
	stack_a *p = NULL;
	stack_a *head = NULL;
	int i = 0;
	while(i < len)
	{
		temp = (stack_a *)malloc(sizeof(stack_a));
		if(!temp)
			return(NULL);
		temp->next = NULL;
		temp->val_a = array[i];
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



/**
 * @brief	Swap the first 2 elements at the top of stack a
 *			Do nothing if there is only one or no elements.
 * @param head root of stack_a
 * @return stack_a* swaped elements
 */
void sa(stack_a *head)
{
	int temp = 0;
	if(list_len(head) < 2)
		return ;
	//printf("before:\npos 1: %d\npos 2: %d\npos 3: %d\n\n", head->value, head->next->value, head->next->next->value);
	temp = head->next->val_a;
	head->next->val_a = head->val_a;
	head->val_a = temp;
	//printf("after:\npos 1: %d\npos 2: %d\npos 3: %d\n\n", head->value, head->next->value, head->next->next->value);	
	//return(head);
}

/**
 * @brief	Swap the first 2 elements at the top of stack b
 *			Do nothing if there is only one or no elements.
 * @param head root of stack_b
 * @return stack_b* swaped elements
 */
void sb(stack_b *head)
{
	int temp = 0;
	if(list_len(head) < 2)
		return(NULL);
	temp = head->next->val_b;
	head->next->val_b = head->val_b;
	head->val_b = temp;
	return(head);
}


int main()
{
	int array[4] = {1, 3, 5, 7};
	stack_a *head = NULL;
	head = (stack_a*)malloc(sizeof(stack_a));
	head = create_list(4, array);
	
	printf("pos 1: %d\npos 2: %d\npos 3: %d\npos 4: %d\n\n", head->val_a, head->next->val_a, head->next->next->val_a, head->next->next->next->val_a);

}

