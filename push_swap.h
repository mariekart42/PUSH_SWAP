/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:20 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/29 18:48:24 by mmensing         ###   ########.fr       */
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


//colour shit
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"


// -----  marie_sort.c  -----
void quick_to_b(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts);
void marie_sort(l_list** stack_a, l_list** stack_b, l_list** a_starts, l_list** b_starts, l_list**temp_b_starts);
void some_above_a(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts, l_list**a_starts);
void some_under_a(l_list** stack_a, l_list** stack_b, l_list** b_starts, l_list**temp_b_starts, l_list **a_starts);
void some_above_b(l_list*** stack_a, l_list*** stack_b, l_list*** b_starts, l_list***temp_b_starts, l_list **b_down);
void some_under_b(l_list **stack_a, l_list **stack_b, l_list** b_down, l_list** b_starts);
void b_starts_empty(l_list** stack_a, l_list** stack_b, l_list**b_down);

// -----  delete_later_funcs.c  -----
l_list *create_list_alone(int32_t len, int32_t *content); //deleter later
void print_list(l_list **list, char *name);


// -----  perfect_pivot.c  -----
int32_t perfect_pivot(l_list *start, l_list *end);
int32_t lst_len_end(l_list **start, l_list **end);
int32_t half_list_val(int *array, int len_list);
bool is_sorted(int *array, int len_list);


// -----  checking.c  -----
bool checking(char **argv, int32_t argc);
bool dupli_and_min_max(char **argv, int32_t argc);
bool only_nums(char **argv, int32_t argc);


// -----  extra_funcs.c  -----
l_list *create_list(int32_t len, char **content);
int32_t list_len(l_list *head);
l_list *new_node(int32_t content);
int32_t last_node_content(l_list *head);
l_list *lst_last(l_list *head);
long int ft_atol(const char *str);
int	ft_isdigit(int val);
void free_list(l_list *head);
l_list *second_last(l_list *head);
// bool l_duplication(l_list *head, int content);
void hardcode_case_3(l_list **node);
void hardcode_case_4(l_list **node);
bool lst_is_sorted(l_list **head, int32_t end, int32_t start);
l_list *prev(l_list *stack, l_list*node);
bool stack_sorted(l_list **stack);
void del_last(l_list **node);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void push_all_to_a(char *from, l_list*start, l_list* end, l_list **stack_a, l_list** stack_b);
int32_t range(l_list* stack, l_list* begin, l_list *end);

l_list *place(l_list*stack, l_list*node);

l_list* after(l_list *stack, l_list* node);

void hc_three(l_list **stack_a);
int smol(l_list *stack_a);
void hc_four(l_list **stack_a, l_list **stack_b);

void hardcode_func(l_list**stack_a, l_list **stack_b, l_list *end);
void special_case(l_list **stack_a, l_list** stack_b, l_list *last_a, l_list**temp_b_starts, l_list**b_starts);

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