/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:52:03 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/19 13:53:03 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief function converts string argument to integer type(returns int)
 * stops if it reaches a no digit character, or a not '-' '+' character
 * spaces & tabs are okay only BEFORE argument
 * valid arguments: "423", "-273", "+765", "   -765"
 * @param str char string
 * @return int converted char string if given argument is valid, else returns 0
 */
int	ft_atoi(const char *str)
{
	int		val;
	int		minus;
	int		i;

	val = 0;
	minus = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		val = 10 * val + str[i] - 48;
		i++;
	}
	return (val * minus);
}

/**
 * @brief returns lengh of str
 * 
 * @param str 
 * @return size_t lengh of str
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
