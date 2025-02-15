# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 13:04:55 by jiepark           #+#    #+#              #
#    Updated: 2025/02/07 13:04:58 by jiepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo

SRC			:=	src/init.c \
				src/main.c \
				src/print.c \
				src/terminate.c \
				src/monitor.c \
				src/routine.c \
				src/utils.c

OBJ_DIR		:= obj

OBJ			:= $(SRC:src/%.c=$(OBJ_DIR)/%.o)

CC			:= gcc
CFLAG		:= -Wall -Wextra -Werror -I includes -g
RM			:= rm -rf

$(NAME)		: $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OBJ_DIR)/$(NAME) -lpthread

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean			:
	$(RM) $(OBJ_DIR)

fclean			: clean
	$(RM) $(OBJ_DIR)/$(NAME)

re				: fclean all

all				: $(NAME)

.PHONY			: all clean fclean re
