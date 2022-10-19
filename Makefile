# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 12:21:27 by mmensing          #+#    #+#              #
#    Updated: 2022/10/18 19:50:29 by mmensing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap.a

CC = gcc
CFLAGS= -Wall -Werror -Wextra -g
HEADER= push_swap.h
RM= rm -rf
NAME = push_swap
#DEBUG = -fsanitize=address

FILES=	marie_sort.c \
		checking.c \
		perfect_pivot.c \
		extra_funcs.c \
		a_and_b_rules.c \
		a_rules.c \
		b_rules.c \
		main.c \
		some_above_a.c \
		some_under_a.c \
		some_above_b.c \
		some_under_b.c \
		quick_to_b.c \
		hc_quick_to_b.c \
		b_starts_empty.c \
		hardcode.c \
		edit_list.c \
		list_positions.c \
		list_infos.c \
		leak_shit.c 

O_FILES= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	$(CC) $(CFLAGS) $(DEBUG) $(O_FILES) -o $(NAME)

clean:
	$(RM) $(O_FILES)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

g:
	@gcc -g -fsanitize=address $(FILES) $(CFLAGS)
# -fsanitize=address
.PHONY: all clean fclean re