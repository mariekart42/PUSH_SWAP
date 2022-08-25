/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:37:08 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/25 16:49:50 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function returns 1 or more if something wrong
// 0 if everything is allright
// normal pointer so we get the copy of stack_a and dont change anything
int8_t checking(char **argv, int32_t argc)
{
	int8_t check = 0;
	printf("check in checking\n");
	check += dupli_and_min_max(argv, argc);
	check += only_nums(argv, argc);
	return (check);
}

int8_t dupli_and_min_max(char **argv, int32_t argc)
{
	int32_t k = 0;
	int64_t all[argc]; // long int so we can check for INT_MAX/MIN
	argv++;
	while (k < argc-1)
	{
		all[k] = ft_atol(argv[k]);
		if (all[k] < INT_MIN || all[k] > INT_MAX)
		{
			printf("NOPE input to high/low\n");
			return(1);
		}
		// printf("all[%d]: %lld\n", k, all[k]);
		k++;
	}
	all[k] = '\0';
	//IS WORKING!
	
	int32_t i = 0;
	int32_t n = 1;
	while (all[i] != '\0')
	{
		while (all[n + i] != '\0')
		{
			if (all[i] == all[n + i])
			{
				printf("NOPE duplicate found\n");
				return (1);
			}
			n++;
		}
		n = 1;
		i++;
	}
	return (0);
}


// only numbers
// bullshit cause function only checks for first digit (only 0 - 9)
int32_t only_nums(char **argv, int32_t argc)
{
	int32_t i;
	int32_t base;
	int32_t len;

	len = 0;
	base = 1;
	i = 0;
	while (argc - 1 > 0)
	{
		len = strlen(argv[base]);
		while(len > 0)
		{
			if(!(argv[base][i] >= 48 && argv[base][i] <= 57))
			{
				printf("NOPE not only digits\n");
				return(1);
			}
			i++;
			len--;
		}
		i=0;
		base++;
		argc--;
	}
	return (0);
}