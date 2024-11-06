NAME = so_long

# directory
LIBFT_DIR = libft
INC_DIR = libft/includes ft_printf/includes get_next_line/includes includes
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line

# header
INC := -I$(INC_DIR)

# src files
SRC := src/main.c src/utils.c

# object
OBJ := $(SRC:.c=.o)

# compiler options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# others
.PHONY: all clean fclean libft ft_printf get_next_line

# default target
all: $(NAME) libft ft_printf get_next_line
	$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lft_printf -L$(GET_NEXT_LINE_DIR) -lget_next_line -o $(NAME)

# Build libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Build ft_printf
ft_printf:
	$(MAKE) -C $(FT_PRINTF_DIR)

# Build get_next_line
get_next_line:
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

# Compilation rule for object files in the main prog
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# includes files in sub-directories
#vpath = get_next_line ft_printf

#rebuild
re: fclean all