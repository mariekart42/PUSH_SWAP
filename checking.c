/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:37:08 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/08 18:45:49 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function returns 1 or more if something wrong
// 0 if everything is alright
// normal pointer so we get the copy of stack_a and dont change anything
bool checking(char **argv, int32_t argc)
{
	// int8_t check = 0;
	// // checks if there is at least one argument
	// if (argc < 2)
	// 	check += 1;
	// check += dupli_and_min_max(argv, argc);
	// check += only_nums(argv, argc);
	if(argc < 2 || dupli_and_min_max(argv, argc) == false || only_nums(argv, argc) == false)
		return(false);
	return (true);
}

bool dupli_and_min_max(char **argv, int32_t argc)
{
	int32_t k = 0;
	int64_t all[argc]; // long int so we can check for INT_MAX/MIN
	argv++;
	// checks if number is out of integwer range
	while (k < argc-1)
	{
		all[k] = ft_atol(argv[k]);
		if (all[k] < INT_MIN || all[k] > INT_MAX)
			return (false);
		k++;
	}
	all[k] = '\0';
	//IS WORKING!
	
	int32_t i = 0;
	int32_t n = 1;
	// checks for duplicates
	while (all[i] != '\0')
	{
		while (all[n + i] != '\0')
		{
			if (all[i] == all[n + i])
				return (false);
			n++;
		}
		n = 1;
		i++;
	}
	return (true);
}

// checks if there are only numbers (works now also with neg nums)
bool only_nums(char **argv, int32_t argc)
{
	int32_t i = 0;
	int8_t minus = 0;
	int32_t base = 1;
	int8_t len_num;
	while (argc - 1 > 0)
	{
		len_num = strlen(argv[base]);
		if (argv[base][0] == '-' || argv[base][0] == '+')
		{
			i++;
			minus = 1;
		}
		while (len_num - minus > 0)
		{
			if (!(argv[base][i] >= 48 && argv[base][i] <= 57))
				return(false);
			len_num--;
			i++;
		}
		i = 0;
		len_num = 0;
		argc--;
		base++;
	}
	return(true);
}