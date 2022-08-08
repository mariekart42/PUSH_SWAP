/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:06:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/08/08 21:56:08 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>

typedef struct stack_a 
{
	int val_a;
	struct stack_a *next;
} stack_a;

typedef struct stack_b
{
	int val_b;
	struct stack_b *next;
} stack_b;

stack_a *create_list(int len, char *content)
char *argv_changer(int argc, char **argv);

stack_a *sa(stack_a *head);
int list_len(stack_a *head);

#endif