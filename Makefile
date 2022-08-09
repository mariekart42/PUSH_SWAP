# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 12:21:27 by mmensing          #+#    #+#              #
#    Updated: 2022/08/09 20:33:33 by mmensing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap.a

CC = gcc
CFLAGS= -Wall -Werror -Wextra
HEADER= push_swap.h
RM= rm -rf

FILES= extra_funcs.c main.c rules.c delete_later_funcs.c

O_FILES= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	ar rcs $(NAME) $(O_FILES)
	
clean:
	$(RM) $(O_FILES)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

g:
	@gcc $(FILES) $(CFLAGS)

.PHONY: all clean fclean re