/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:06:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/25 01:14:24 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // write()
#include <stdint.h> // int32_t
#include <limits.h> // int max/min macros

typedef struct l_list 
{
	int val;
	struct l_list *next;
} l_list;

//colour shit
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"
 

// delete later
l_list *create_list_alone(int32_t len, int32_t *content); //deleter later
void print_list(l_list **list, char *name);

l_list *create_list(int32_t len, char **content);
int32_t list_len(l_list *head);
l_list *new_node(int32_t content);
// stack_a *create_list(int len, char *content);
//char *argv_changer(int argc, char **argv);
long int ft_atol(const char *str);

int32_t last_nodes_content(l_list *head);
int create_and_check_list(l_list **stack_a, char **argv, int argc);


/* - - - CHECK - - - */
int8_t duplicates(char **argv, int32_t argc);
int8_t checking(char **argv, int32_t argc);
int32_t only_nums(char **argv, int32_t argc);


/* - - - RULES - - - */
void sa(l_list **stack_a, bool output);
void sb(l_list **stack_b, bool output);
void ss(l_list **stack_a, l_list **stack_b);

void pa(l_list **stack_a, l_list **stack_b);
void pb(l_list **stack_a, l_list **stack_b);

void ra(l_list **stack_a, bool output);
void rb(l_list **stack_b, bool output);
void rr(l_list **stack_a, l_list **stack_b);

void rra(l_list **stack_a, bool output);
void rrb(l_list **stack_b, bool output);
void rrr(l_list **stack_a, l_list **stack_b);

#endif