/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:42:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/14 14:59:48 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t main(int32_t argc, char **argv) 
{
	t_holder	l_hold;

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
		free_list(l_hold.a);
		return (0);
	}
	quick_to_b(&l_hold);
	marie_sort(&l_hold);
	free_list(l_hold.b_start);
	free_list(l_hold.b);
	free_list(l_hold.a);
	free_list(l_hold.a_start);
	free_list(l_hold.tmp_b_start);
}
