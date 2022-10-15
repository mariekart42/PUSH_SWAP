/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:43:26 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/15 15:04:15 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// rule sa and sb at the same time
void	ss(t_list **a, t_list **b)
{
	sa(a, false);
	sb(b, false);
}

void	rr(t_list **a, t_list **b)
{
	ra(a, false);
	rb(b, false);
}

// rra and rrb at the same time
void	rrr(t_list **a, t_list **b)
{
	rra(a, false);
	rrb(b, false);
}
