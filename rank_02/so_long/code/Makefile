NAME = so_long

# Directories
LIBFT_DIR = libft
MINILIBX_DIR := minilibx-linux

# Header
HEADER := -Iincludes -I$(LIBFT_DIR)/includes 

# Source files
SRC :=	src/init1_game.c	src/init2_map.c		src/init3_path_check.c\
		src/error.c			src/graphic.c		src/control.c\
		src/main.c			src/free.c			src/for_debug_to_remove/for_debug.c #//rm

# Object files
OBJ := $(SRC:.c=.o)

# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADER)

# Others
.PHONY: all clean fclean libft re

# libraries
LIB			:= -L$(LIBFT_DIR) -l$(LIBFT_DIR) 
MINILIBX	:= -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -lz

# Default target
all: $(NAME)

$(NAME): libft/liblibft.a $(OBJ)
	make -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(MINILIBX) -o $(NAME)

# Compilation rule for object files in the main program
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT_DIR)/liblibft.a:
	$(MAKE) -C $(LIBFT_DIR)

# Cleaning
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all