NAME = so_long

# Directories
LIBFT_DIR = libft

# Header
HEADER := -Iincludes -I$(LIBFT_DIR)/includes 

# Source files
SRC := src/main.c src/utils.c

# Object files
OBJ := $(SRC:.c=.o)

# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADER)

# Others
.PHONY: all clean fclean libft re

# libraries
LIB := -L$(LIBFT_DIR) -llibft 

# Default target
all: $(NAME)

$(NAME): $(OBJ) libft/liblibft.a 
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

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