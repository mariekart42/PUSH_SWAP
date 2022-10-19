/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/19 12:37:48 by ljahn            ###   ########.fr       */
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

void	block(t_holder l_hold)
{
	ft_lstclear(&l_hold.a, free_);
	ft_lstclear(&l_hold.b, free_);
	ft_lstclear(&l_hold.b_start, free_);
	ft_lstclear(&l_hold.a_start, free_);
	ft_lstclear(&l_hold.tmp_b_start, free_);
	ft_lstclear(&l_hold.b_down, free_);
};

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
	quick_to_b(&l_hold);// Is leaking one leak
	// print_list(&l_hold.a, "a main");
	// print_list(&l_hold.b, "b main");
	
	marie_sort(&l_hold, &list);
	block(l_hold);
}
