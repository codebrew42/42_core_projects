NAME = so_long

# Directories
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line

# Header
HEADER := -Iincludes -I$(LIBFT_DIR)/includes -I$(FT_PRINTF_DIR)/includes -I$(GET_NEXT_LINE_DIR)/includes

# Source files
SRC := src/main.c src/utils.c

# Object files
OBJ := $(SRC:.c=.o)

# Compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEADER)

# Others
.PHONY: all clean fclean libft ft_printf get_next_line re

# libraries
LIB := -L$(LIBFT_DIR) -llibft -L$(FT_PRINTF_DIR) -lft_printf -L$(GET_NEXT_LINE_DIR) -lget_next_line

# Default target
all: $(NAME)

$(NAME): $(OBJ) libft/liblibft.a ft_printf/libft_printf.a get_next_line/libget_next_line.a
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

# Compilation rule for object files in the main program
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft
$(LIBFT_DIR)/liblibft.a:
	$(MAKE) -C $(LIBFT_DIR)

# Build ft_printf
$(FT_PRINTF_DIR)/libft_printf.a:
	$(MAKE) -C $(FT_PRINTF_DIR)

# Build get_next_line
$(GET_NEXT_LINE_DIR)/libget_next_line.a:
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

# Cleaning
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all