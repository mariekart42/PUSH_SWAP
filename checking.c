/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:37:08 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/19 13:46:38 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	checking(char **argv, int32_t argc)
{
	t_list	num;

	num.i = 0;
	if (argc < 2)
		return (false);
	if (only_nums(argv, argc, num) == false)
		return (false);
	if (dupli_and_min_max(argv, argc, num) == false)
		return (false);
	return (true);
}

bool	init_all_array(t_list *list, int argc, char **argv)
{
	list->k = 0;
	while (list->k < argc - 1)
	{
		list->all[list->k] = ft_atol(argv[list->k]);
		if (list->all[list->k] < INT_MIN || list->all[list->k] > INT_MAX)
			return (false);
		list->k++;
	}
	list->all[list->k] = '\0';
	return (true);
}

bool	dupli_and_min_max(char **argv, int32_t argc, t_list l)
{
	l.i = 0;
	l.n = 1;
	l.all = (int64_t *)malloc ((argc + 1) * sizeof(int64_t));
	if (!l.all)
		exit (0);
	argv++;
	if (init_all_array(&l, argc, argv) == false)
		return (false);
	while (argc - 2 > l.i)
	{
		while (argc - 2 - l.i >= l.n)
		{
			if (l.all[l.i] == l.all[l.n + l.i])
				return (false);
			l.n++;
		}
		l.n = 1;
		l.i++;
	}
	free_((void **)&l.all);
	return (true);
}

bool	only_nums(char **argv, int32_t argc, t_list l)
{
	l.base = 1;
	l.i = 0;
	l.minus = 0;
	while (argc - 1 > 0)
	{
		l.len_num = ft_strlen(argv[l.base]);
		if (argv[l.base][0] == '-' || argv[l.base][0] == '+')
		{
			l.i++;
			l.minus = 1;
		}
		while (l.len_num - l.minus > 0)
		{
			if (!(argv[l.base][l.i] >= 48 && argv[l.base][l.i] <= 57))
				return (false);
			l.len_num--;
			l.i++;
		}
		l.i = 0;
		l.len_num = 0;
		argc--;
		l.base++;
	}
	return (true);
}
