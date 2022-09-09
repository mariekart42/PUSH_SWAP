/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:06:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/09 21:29:14 by mmensing         ###   ########.fr       */
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
#include <string.h> // strlen -> delete later & implement libft strlen

typedef struct l_list 
{
	int val;
	struct l_list *next;
} l_list;


// -----  mid_point_algo.c  -----
void mid_point_algo(l_list **stack_a, l_list **stack_b);



// -----  delete_later_funcs.c  -----
l_list *create_list_alone(int32_t len, int32_t *content); //deleter later
void print_list(l_list **list, char *name);


////////////// -----  OLD_perfect_pivot.c  -----
// void lst_swap(l_list *head_a, l_list *head_b);
// bool is_sorted(l_list *start, l_list *end);
// int32_t perfect_pivot(l_list *start, l_list *end);
// int32_t val_half_list(l_list *head, l_list *end);
// char *create_array(l_list *head);


// -----  perfect_pivot.c  -----
int32_t perfect_pivot(l_list *start, l_list *end);
int32_t lst_len_end(l_list *start, l_list *end);
bool is_sorted(int **array, int len_list);

// -----  checking.c  -----
bool checking(char **argv, int32_t argc);
bool dupli_and_min_max(char **argv, int32_t argc);
bool only_nums(char **argv, int32_t argc);


// -----  extra_funcs.c  -----
l_list *create_list(int32_t len, char **content);
int32_t list_len(l_list *head);
l_list *new_node(int32_t content);
int32_t last_nodes_content(l_list *head);
l_list *lst_last(l_list *head);
long int ft_atol(const char *str);
int	ft_isdigit(int val);




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