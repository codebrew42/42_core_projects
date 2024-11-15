# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 10:19:39 by jiepark           #+#    #+#              #
#    Updated: 2024/11/15 10:19:41 by jiepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

# Directories
LIBFT_DIR	= libft
MINILIBX_DIR	= minilibx-linux

# Header
HEADER		= -Iincludes -I$(LIBFT_DIR)/includes 

# Source files
SRC		= src/init1_game.c \
		src/init2_map.c \
		src/init3_path_check.c \
		src/error.c \
		src/graphic.c \
		src/control.c \
		src/main.c \
		src/free.c

# Object files
OBJ		= $(SRC:.c=.o)

# Compiler options
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror $(HEADER) -fPIE

# Libraries
LIB		= -L$(LIBFT_DIR) -l$(LIBFT_DIR)
MINILIBX	= -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lz

# Default target
all: $(NAME)

$(NAME): libft/liblibft.a $(OBJ)
	make -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MINILIBX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/liblibft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
