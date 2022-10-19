/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/19 11:41:54 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_list(t_list **list, char *name)
// {
// 	printf("----------\n[%s]:\n", name);
// 	if(*list == NULL)
// 	{
// 		printf("list_pos_1: (NULL)\n");
// 		return ;
// 	}
// 	int32_t i = 1;
// 	t_list *node = NULL;
// 	node = (*list);
// 	while (node->next != NULL)
// 	{
// 		printf("list_pos_%d: %d\n", i, node->val);
// 		i++;
// 		node = node->next;
// 	}
// 	printf("list_pos_%d: %d\n", i, node->val);
// 	i++;
// 	if(node->next == NULL)
// 		printf("list_pos_%d: (NULL)\n", i);
// 	else	
// 		printf("something wrong! (print_list function)\n");
// 	printf("-- done --\n\n");
// }

int32_t	main(int32_t argc, char **argv)
{
	t_holder	l_hold;
	t_list		list;

	if (argc == 1)
		return (0);
	if (checking(argv, argc) == false)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	l_hold.a = create_list(argc, argv);
	if (stack_sorted(&l_hold.a) == true && list_len(l_hold.b) == 0)
	{
		free_list(&l_hold.a);
		return (0);
	}
	quick_to_b(&l_hold);
	// print_list(&l_hold.a, "a main");
	// print_list(&l_hold.b, "b main");
	
	
	marie_sort(&l_hold, &list);
	ft_lstclear(&l_hold.a, del_);
	ft_lstclear(&l_hold.b, del_);
	ft_lstclear(&l_hold.b_start, del_);
	ft_lstclear(&l_hold.a_start, del_);
	ft_lstclear(&l_hold.tmp_b_start, del_);
	ft_lstclear(&l_hold.b_down, del_);

}
