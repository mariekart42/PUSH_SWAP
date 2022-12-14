/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_funcs_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:18:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/25 16:41:03 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/push_swap.h"

int64_t	ft_atol(const char *str)
{
	int64_t		val;
	int8_t		minus;
	int32_t		i;

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
		i++;
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		val = 10 * val + str[i] - 48;
		i++;
	}
	return (val * minus);
}

/**
compares 2 char arrays if one of them is greater, less or equal
stop point is a fixed variable n
for extendet ascii using unsigned char
e.g. 
"abc" > "aba"   ->    returns 1
  ""  =  ""     ->    returns 0
 "a"  < "abc"   ->    returns -1
*/
int32_t	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - ((unsigned char)s2[i]));
	i++;
	}
	return (0);
}

// for the ABOVE nums: 
//   -> "start" [gets pushed]  
//      "end" [gets NOT pushed]
//
// for the UNDER nums:
//   -> "start" [gets NOT pushed]  
//      "end" [gets NOT pushed]
//
// make b empty:
//   -> everything gets pushed
void	push_to_a(char *from, t_list *start, t_list *end, t_holder *l_hold)
{
	t_list	*temp;

	temp = start;
	while (ft_strncmp(from, "above_b", 7) == 0 && temp != end)
	{
		temp = temp->next;
		pa(&l_hold->a, &l_hold->b);
	}
	while (ft_strncmp(from, "make_b_empty", 12) == 0 && list_len(l_hold->b) > 0)
		pa(&l_hold->a, &l_hold->b);
	if (ft_strncmp(from, "under_b", 7) == 0 \
	|| ft_strncmp(from, "under_a", 7) == 0)
	{
		while (temp->next != NULL)
		{
			if (ft_strncmp(from, "under_b", 7) == 0)
			{
				rrb(&l_hold->b, true);
				pa(&l_hold->a, &l_hold->b);
			}
			else if (ft_strncmp(from, "under_a", 7) == 0)
				rra(&l_hold->a, true);
		}
	}
	return ;
}

/**
 * @brief Outputs the string ???s??? to the given file descriptor
 * 
 * @param s string to output
 * @param fd given file descriptor
 */
void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
