/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/25 13:55:07 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

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
		ft_lstclear(&l_hold.a, free_);
		return (0);
	}
	quick_to_b(&l_hold);
	marie_sort(&l_hold, &list);
	ft_lstclear(&l_hold.a, free_);
	ft_lstclear(&l_hold.b, free_);
	ft_lstclear(&l_hold.b_start, free_);
	ft_lstclear(&l_hold.a_start, free_);
	ft_lstclear(&l_hold.tmp_b_start, free_);
	ft_lstclear(&l_hold.b_down, free_);
}
