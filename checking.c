/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:37:08 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/25 01:13:55 by mmensing         ###   ########.fr       */
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
	check += duplicates(argv, argc);
	//check += only_nums(argv, argc);
	return (check);
}


int8_t duplicates(char **argv, int32_t argc)
{
	int32_t k = 0;
	int64_t all[argc-1];
	argv++;
	printf("ARGV: %ld\n", ft_atol(argv[0]));
	printf("ARGV: %ld\n", ft_atol(argv[1]));
	printf("ARGV: %ld\n", ft_atol(argv[2]));
	while (k < argc-1)
	{
		all[k] = ft_atol((const char*)argv[k]);
		printf("all[k]: %lld\n", all[k]);
		if (all[k] < INT_MIN || all[k] > INT_MAX)
		{
			printf("NOPE input to high/low\n");
			return(1);
		}
		// printf("all[%d]: %d\n", k, all[k]);
		k++;
	}
	

	// all[k] = '\0';
	// int32_t i = 0;
	// int32_t n = 1;
	// while (all[i] != '\0')
	// {
	// 	while (all[n + i] != '\0')
	// 	{
	// 		if (all[i] == all[n + i])
	// 		{
	// 			printf("NOPE duplicate found\n");
	// 			return (1);
	// 		}
	// 		n++;
	// 	}
	// 	n = 1;
	// 	i++;
	// }
	return (0);
}

// the original one

// int32_t duplicates(char **argv, int32_t argc)
// {
// 	int32_t k = 0;
// 	int32_t all[argc-1];
// 	argv++;
	
// 	while (k + 1 < argc)
// 	{
// 		all[k] = atoi(*argv);
// 		argv++;
// 		k++;
// 	}
// 	all[k] = '\0';
// 	int32_t i = 0;
// 	int32_t n = 1;
// 	while (all[i] != '\0')
// 	{
// 		while (all[n + i] != '\0')
// 		{
// 			if (all[i] == all[n + i])
// 			{
// 				printf("NOPE duplicate found\n");
// 				return (1);
// 			}
// 			n++;
// 		}
// 		n = 1;
// 		i++;
// 	}
// 	return (0);
// }

// // only numbers
// // bullshit cause function only checks for first digit (only 0 - 9)
// int32_t only_nums(char **argv, int32_t argc)
// {
// 	int32_t i;
	
// 	i = 1;
// 	while (argc - 1 > 0)
// 	{
// 		if (!(argv[i][0] >= 48 && argv[i][0] <= 57))
// 		{
// 			printf("NOPE not only nums\n");
// 			return (1);
// 		}
// 		i++;
// 		argc--;
// 	}
// 	return (0);
// }