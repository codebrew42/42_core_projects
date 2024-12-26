# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 10:18:32 by jiepark           #+#    #+#              #
#    Updated: 2024/12/12 10:18:33 by jiepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo

SRC			:=	src/main.c		\
				src/display.c	\
				src/philos.c	\
				src/parsing.c	\
				src/table.c		\
				src/utils.c		\
				src/rm_debug.c

OBJ_DIR		:= obj
OBJ			:=	$(SRC:src/%.c=$(OBJ_DIR)/%.o)


CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -Iincludes
LDFLAGS		:= -pthread

#default target
all:		$(NAME)

#linking
$(NAME):	$(OBJ)
			@echo "\t\tLinking..."
			$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

#compiling
$(OBJ_DIR)/%.o:		src/%.c
			@echo "\t\tCompiling $<..."
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@echo "\t\tCleaning object files..."
			rm -f $(OBJ)

fclean:		clean
			@echo "\t\tCleaning object files and executable..."
			rm -f $(NAME)

re:			fclean	all

.PHONY:		all		clean		fclean		re
