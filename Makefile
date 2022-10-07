# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 12:21:27 by mmensing          #+#    #+#              #
#    Updated: 2022/10/07 14:14:12 by mmensing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap.a

CC = gcc
CFLAGS= -Wall -Werror -Wextra
HEADER= push_swap.h
RM= rm -rf
NAME = push_swap

FILES= marie_sort.c checking.c perfect_pivot.c extra_funcs.c rules.c main.c delete_later_funcs.c

O_FILES= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	ar rcs $(NAME) $(O_FILES)
	
clean:
	$(RM) $(O_FILES)
	$(RM) a.out
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

g:
	@gcc -g $(FILES) $(CFLAGS)
# -fsanitize=address
.PHONY: all clean fclean re