/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:20 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/16 16:39:29 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <string.h>

typedef struct s_list
{
	int64_t			*all;
	int32_t			n;
	int32_t			i;
	int32_t			base;
	int32_t			len_num;
	int8_t			minus;
	int32_t			k;
	int32_t			pivot;
	int64_t			guard;
	int32_t			val;
	struct s_list	*last_a;
	struct s_list	*next;
}				t_list;

typedef struct s_holder
{	
	t_list			*a;
	t_list			*b;
	t_list			*b_start;
	t_list			*a_start;
	t_list			*tmp_b_start;
	t_list			*b_down;
}				t_holder;	

t_list	*att_new_node(t_list **node, int32_t content);
//  · _ · 	SOME_ABOVE_A.C		· _ ·  · _ ·  · _ ·  · _ ·  
void		some_above_a(t_holder *l_hold);
void		update_tmp_b_start(t_holder *l_hold);
bool		decider_hc_above_a(t_holder *l_hold);

//  · _ · 	SOME_UNDER_A.C		· _ ·  · _ ·  · _ ·  · _ ·  
void		some_under_a(t_holder *l_hold, t_list *l);

//  · _ · 	SOME_ABOVE_B.C		· _ ·  · _ ·  · _ ·  · _ ·
void		some_above_b(t_holder *l_hold, t_list *l);
bool		decider_push_to_a(t_holder *l_hold);
int			decider_pivot_above_b(t_holder *l_hold);
void		update_b_down(t_holder *l_hold);
void		end_of_b_start(t_holder *l_hold, int temp_b_val, int pivot);

//  · _ · 	SOME_UNDER_B.C		· _ ·  · _ ·  · _ ·  · _ ·  
void		some_under_b(t_holder *l_hold, t_list *l);
int			decider_pivot_under_b(t_holder *l_hold);
t_list		*decider_temp_b_under_b(t_holder *l_hold);

//  · _ · 	MARIE_SORT.C		· _ ·  · _ ·  · _ ·  · _ ·  
void		marie_sort(t_holder *l_hold, t_list *list);

//  · _ · 	QUICK_TO_B.C		· _ ·  · _ ·  · _ ·  · _ ·  
void		quick_to_b(t_holder *l_hold);
void		quick_to_b_algo(t_holder *l_hold, int64_t guard, int32_t pivot);

//  · _ · 	HC_QUICK_TO_B.C		· _ ·  · _ ·  · _ ·  · _ ·  
void		hc_quick(t_holder *l_hold);
void		hc_quick_3(t_list **node);
void		hc_quick_4(t_list **node, t_holder *l_hold);
void		hc_quick_5(t_list **a, t_list **b);

//  · _ · 	B_STARTS_EMPTY.C	· _ ·  · _ ·  · _ ·  · _ ·  
void		b_start_empty(t_holder *l_hold);
bool		decider_push_to_a_b_starts_empty(t_holder *l_hold);
int32_t		decider_pivot(t_holder *l_hold);
int32_t		decider_len(t_holder *l_hold);

//  · _ · 	CHECKING.C			· _ ·  · _ ·  · _ ·  · _ ·  
bool		checking(char **argv, int32_t argc);
bool		init_all_array(t_list *list, int argc, char **argv);
bool		dupli_and_min_max(char **argv, int32_t argc, t_list l);
bool		only_nums(char **argv, int32_t argc, t_list l);

//  · _ · 	PERFECT_PIVOT.C		· _ ·  · _ ·  · _ ·  · _ ·  
int32_t		perfect_pivot(t_list *start, t_list *end);
int32_t		init_array(t_list *start, int32_t *array, int32_t len_list);
int32_t		lst_len_end(t_list **start, t_list **end);
int32_t		half_list_val(int *array, int len_list);
bool		is_sorted(int *array, int len_list);

//  · _ · 	EDIT_LIST.C			· _ ·  · _ ·  · _ ·  · _ ·  
t_list		*create_list(int32_t len, char **content);
t_list		*new_node(int32_t content);
void		free_list(t_list **head);
void		del_last(t_list **node);

//  · _ · 	LIST_POSITIONS.C	· _ ·  · _ ·   · _ ·   · _ ·  
t_list		*l_last(t_list *head);
t_list		*place(t_list*stack, t_list*node);
t_list		*prev(t_list *stack, t_list*node);
t_list		*after(t_list *stack, t_list *node);

//  · _ · 	LIST_INFOS.C		· _ ·  · _ ·  · _ ·  · _ ·  
int32_t		list_len(t_list *head);
int32_t		last_node_content(t_list *head);
int32_t		range(t_list *stack, t_list *begin, t_list *end);
bool		stack_sorted(t_list **stack);

//  · _ · 	EXTRA_FUNCS.C		· _ ·  · _ ·  · _ ·  · _ ·  
int64_t		ft_atol(const char *str);
int32_t		ft_isdigit(int32_t val);
int32_t		ft_strncmp(const char *s1, const char *s2, size_t n);
void		push_to_a(char *from, t_list *start, t_list *end, t_holder *l_hold);
void		ft_putstr_fd(char *s, int fd);

//  · _ · 	HARDCODE.C			· _ ·  · _ ·  · _ ·  · _ ·  
void		hc_three(t_list **a);
int			smol(t_list *a);
void		hc_four(t_list **a, t_list **b);
void		hardcode_func(t_list**a, t_list **b, t_list *end);

//  · _ · 	A_RULES.C			· _ ·  · _ ·  · _ ·  · _ ·  
void		sa(t_list **a, bool output);
void		pa(t_list **a, t_list **b);
void		ra(t_list **a, bool output);
void		rra(t_list **a, bool output);

//  · _ · 	B_RULES.C			· _ ·  · _ ·  · _ ·  · _ ·  
void		sb(t_list **b, bool output);
void		pb(t_list **a, t_list **b);
void		rb(t_list **b, bool output);
void		rrb(t_list **b, bool output);

//  · _ · 	A_AND_B_RULES.C		· _ ·  · _ ·  · _ ·  · _ ·  
void		ss(t_list **a, t_list **b);
void		rr(t_list **a, t_list **b);
void		rrr(t_list **a, t_list **b);

#endif