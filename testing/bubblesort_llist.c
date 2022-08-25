/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort_llist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:27:11 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/24 18:27:12 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// no duplicates
int duplicates(l_list *stack_a)
{
	l_list *temp = NULL;
	l_list *iter = NULL;
	l_list *safe_pos = NULL;
	
	temp = stack_a;
	iter = stack_a->next;
	safe_pos = iter;
	while (temp->next != NULL)
	{
		while (iter->next != NULL)
		{
			if (iter->val == temp->val)
			{
				printf("NOPE found duplicate\n"); // delete later
				return(1);
			}
			iter = iter->next;
		}
		if (iter->val == temp->val)
		{
			printf("NOPE found duplicate\n"); // delete later
			return(1);
		}
		iter = safe_pos->next;
		temp = temp->next;
	}
	printf("YEE all righty\n");
	return(0);
}