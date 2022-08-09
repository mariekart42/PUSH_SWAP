/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:06:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/09 21:18:12 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>

typedef struct l_list 
{
	int val;
	struct l_list *next;
} l_list;

l_list *create_list_alone(int len, int *content); //deleter later

l_list *create_list(int len, char **content);
int list_len(l_list *head);
l_list *new_node(int content);
// stack_a *create_list(int len, char *content);
//char *argv_changer(int argc, char **argv);



/* - - - RULES - - - */
void sa(l_list *stack_a);
void sb(l_list *stack_b);
void ss(l_list *stack_a, l_list *stack_b);
void pa(l_list *stack_a, l_list *stack_b);


#endif