/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:19:20 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/15 16:39:03 by mmensing         ###   ########.fr       */
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
 # include<string.h>
 
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
}	t_holder;

//colour shit
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

// ---- some_above_a.c ------
void	some_above_a(t_holder *l_hold);
void	update_tmp_b_start(t_holder *l_hold);
bool	decider_hc_above_a(t_holder *l_hold);


// --- some_under_a.c --------
void	some_under_a(t_holder *l_hold, t_list *l);


// --- some_above_b.c -------
void	some_above_b(t_holder *l_hold, t_list *l);
bool	decider_push_to_a(t_holder *l_hold);
int		decider_pivot_above_b(t_holder *l_hold);
void	update_b_down(t_holder *l_hold);
void	end_of_b_start(t_holder *l_hold, int temp_b_val, int pivot);


// --- some_under_b.c ----
void	some_under_b(t_holder *l_hold, t_list *l);
int		decider_pivot_under_b(t_holder *l_hold);
t_list	*decider_temp_b_under_b(t_holder *l_hold);

// -----  marie_sort.c  -----
void	marie_sort(t_holder *l_hold, t_list *list);


// ---- quick_to_b.c -----
void	quick_to_b(t_holder *l_hold);
void	quick_to_b_algo(t_holder *l_hold, int64_t guard, int32_t pivot);
void	hc_quick(t_holder *l_hold);
void	hc_quick_3(t_list **node);
void	hc_quick_4(t_list **node, t_holder *l_hold);


// ---- b_starts_empty.c -----
void	b_start_empty(t_holder *l_hold);
bool	decider_push_to_a_b_starts_empty(t_holder *l_hold);
int32_t	decider_pivot(t_holder *l_hold);
int32_t	decider_len(t_holder *l_hold);


// -----  delete_later_funcs.c  -----
t_list	*create_list_alone(int32_t len, int32_t *content);
void	print_list(t_list **list, char *name);


// -----  checking.c  -----
bool	checking(char **argv, int32_t argc);
bool	init_all_array(t_list *list, int argc, char **argv);
bool	dupli_and_min_max(char **argv, int32_t argc, t_list l);
bool	only_nums(char **argv, int32_t argc, t_list l);


// -----  perfect_pivot.c  -----
int32_t	perfect_pivot(t_list *start, t_list *end);
int32_t	init_array(t_list *start, int32_t *array, int32_t len_list);
int32_t	lst_len_end(t_list **start, t_list **end);
int32_t	half_list_val(int *array, int len_list);
bool	is_sorted(int *array, int len_list);


// --- edit_list.c ------
t_list	*create_list(int32_t len, char **content);
t_list	*new_node(int32_t content);
void	free_list(t_list *head);
void	del_last(t_list **node);


// ----- list_positions.c -----
t_list	*l_last(t_list *head);
t_list	*place(t_list*stack, t_list*node);
t_list	*prev(t_list *stack, t_list*node);
t_list*	after(t_list *stack, t_list* node);


// ----- list_infos.c ------
int32_t	list_len(t_list *head);
int32_t	last_node_content(t_list *head);
int32_t	range(t_list *stack, t_list *begin, t_list *end);
bool	stack_sorted(t_list **stack);


// -----  extra_funcs.c  -----
int64_t ft_atol(const char *str);
int32_t	ft_isdigit(int32_t val);
int32_t	ft_strncmp(const char *s1, const char *s2, size_t n);
void push_to_a(char *from, t_list*start, t_list* end, t_list **a, t_list** b);
void	ft_putstr_fd(char *s, int fd);




// ---- hardcoding.c -----
void	hc_three(t_list **a);
int		smol(t_list *a);
void	hc_four(t_list **a, t_list **b);
void	hardcode_func(t_list**a, t_list **b, t_list *end);


// --- a_rules.c ----
void	sa(t_list **a, bool output);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a, bool output);
void	rra(t_list **a, bool output);

// --- b_rules.c ----
void	sb(t_list **b, bool output);
void	pb(t_list **a, t_list **b);
void	rb(t_list **b, bool output);
void	rrb(t_list **b, bool output);

// --- a_and_b_rules.c ----
void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

#endif