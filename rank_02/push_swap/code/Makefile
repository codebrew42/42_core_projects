# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 14:50:36 by jiepark           #+#    #+#              #
#    Updated: 2024/10/30 14:50:37 by jiepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

# dir
LIBFT_DIR = libft
OPERATION_DIR = operation
SRC_DIR = src
INC_DIR = includes
OPERATION_BONUS_DIR = operation_bonus

# libft
LIBFT := $(LIBFT_DIR)/libft.a

# header
INC := -I$(INC_DIR)

# src file
SRC := $(SRC_DIR)/input0_handle.c $(SRC_DIR)/move0_init_a.c \
 	$(SRC_DIR)/move0_init_b.c $(SRC_DIR)/move1_cost.c \
	$(SRC_DIR)/move2_move.c $(SRC_DIR)/stack0_utils.c \
	$(SRC_DIR)/stack1_init.c $(SRC_DIR)/stack2_sort.c  \
	$(SRC_DIR)/main.c $(SRC_DIR)/main_utils.c

OP_SRC := $(OPERATION_DIR)/op1_push.c $(OPERATION_DIR)/op2_rotate.c \
	$(OPERATION_DIR)/op3_rev_rotate.c $(OPERATION_DIR)/op4_swap.c

CHECK_SRC := $(SRC_DIR)/input0_handle.c $(SRC_DIR)/move0_init_a.c \
		$(SRC_DIR)/move0_init_b.c \
		$(SRC_DIR)/move1_cost.c $(SRC_DIR)/move2_move.c \
		$(SRC_DIR)/stack0_utils.c $(SRC_DIR)/stack1_init.c \
		$(SRC_DIR)/stack2_sort.c $(SRC_DIR)/main_utils.c \
		checker.c get_next_line.c get_next_line_utils.c \
		$(OPERATION_BONUS_DIR)/op1_push.c  \
		$(OPERATION_BONUS_DIR)/op2_rotate.c \
		$(OPERATION_BONUS_DIR)/op3_rev_rotate.c \
		 $(OPERATION_BONUS_DIR)/op4_swap.c

# object
OBJ := $(SRC:.c=.o) $(OP_SRC:.c=.o)
CHECK_OBJ = $(CHECK_SRC:.c=.o)

# libft object
LIBFT_SRC := $(LIBFT_DIR)/ft_strcmp.c $(LIBFT_DIR)/ft_calloc.c \
			$(LIBFT_DIR)/ft_strchr.c
LIBFT_OBJ := $(LIBFT_SRC:.c=.o)

# Compiler and Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror $(INC)
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft

# Others
.PHONY: all clean fclean re libft

# default target
all: libft $(NAME) $(CHECK)

# build libft
$(LIBFT): $(LIBFT_OBJ)
	$(MAKE) -C $(LIBFT_DIR)

# linking
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(CHECK): $(CHECK_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECK_OBJ) $(LDFLAGS) $(LDLIBS) -o $(CHECK)

# Compiling
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
	rm -f $(CHECK_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(NAME)
	rm -f $(CHECK)

debug: CFLAGS += -g
debug: fclean all

#rebuild
re: fclean all
