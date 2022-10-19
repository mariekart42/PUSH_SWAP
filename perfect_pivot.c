/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:35:43 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/19 13:23:29 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// create array with content of list
// sort array
// find half
// pivot every time the bigger one!
int32_t	perfect_pivot(t_list *start, t_list *end)
{
	int32_t	*array;
	int32_t	len_list;
	t_list	l;

	len_list = lst_len_end(&start, &end);
	array = (int32_t *)malloc(sizeof(int32_t) * len_list);
	if (!array)
		exit (0);
	len_list = init_array(start, array, len_list);
	l.i = 0;
	while (is_sorted(array, len_list) == false)
	{
		while ((len_list - 1) > l.i)
		{
			if (array[l.i] > array[l.i + 1])
			{
				l.val = array[l.i];
				array[l.i] = array[l.i + 1];
				array[l.i + 1] = l.val;
			}
			l.i++;
		}
		l.i = 0;
	}
	return (half_list_val(array, len_list));
}

int32_t	init_array(t_list *start, int *array, int32_t len_list)
{
	int32_t	i;

	i = 0;
	while (len_list > 0)
	{
		array[i] = start->val;
		len_list--;
		i++;
		start = start->next;
	}
	array[i] = '\0';
	return (i);
}

// count len from start to end
int32_t	lst_len_end(t_list **start, t_list **end)
{
	t_list	*temp;
	int		count;

	temp = *start;
	count = 0;
	if (temp == NULL)
		return (0);
	if (temp == *end)
		return (1);
	if (*end == NULL)
	{
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return (count);
	}
	while (temp->val != (*end)->val)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int32_t	half_list_val(int *array, int len_list)
{
	int32_t	half_len;
	int32_t	return_val;

	half_len = 0;
	if (len_list == 1)
		return (array[0]);
	if ((len_list % 2) == 0)
		half_len = len_list / 2;
	else if ((len_list % 2) != 0)
		half_len = (len_list - 1) / 2;
	return_val = array[half_len];
	free_((void **)&array);
	return (return_val);
}

bool	is_sorted(int *array, int len_list)
{
	int	i;

	i = 0;
	if (len_list == 1)
		return (true);
	while (len_list - 1 > 0)
	{
		if (array[i] > array[i + 1])
			return (false);
		len_list--;
		i++;
	}
	return (true);
}
