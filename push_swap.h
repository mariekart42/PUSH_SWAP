/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:06:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/09/21 20:50:18 by mmensing         ###   ########.fr       */
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
void marie_sort(l_list **stack_a, l_list ** stack_b, l_list** a_starts, l_list** b_starts);



// // -----  move_chunk.c  -----
// void quicksort(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts);
// void quick_to_b(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts);



// // -----  quicksort.c  -----
// bool quick_to_b(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts);
// bool quicksort(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts);
// bool quick_to_a(l_list **stack_a, l_list **stack_b, l_list **a_starts, l_list **b_starts);


// // -----  mid_point_algo.c  -----
// void mid_point_algo(l_list **stack_a, l_list **stack_b);
// void sort_stack_b(l_list **stack_a, l_list **stack_b, l_list **c_b_start, l_list **c_b_end);
// void create_list_start_end(l_list *stack_b, l_list **start, l_list **end);
// void edit_list_start_end(l_list *stack, l_list **start, l_list **end);


// -----  delete_later_funcs.c  -----
l_list *create_list_alone(int32_t len, int32_t *content); //deleter later
void print_list(l_list **list, char *name);


// -----  perfect_pivot.c  -----
int32_t perfect_pivot(l_list *start, l_list *end);
int32_t lst_len_end(l_list *start, l_list *end);
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
int32_t last_nodes_content(l_list *head);
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
void create_b_starts(l_list *stack_b, l_list **b_starts, l_list *tmp);
void hardcode(l_list** stack);


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