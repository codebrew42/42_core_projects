name = so_long

# directory
LIBFT_DIR = libft
INC_DIR = libft ft_printf get_next_line includes
FT_PRINTF_DIR = ft_printf
GET_NEXT_LINE_DIR = get_next_line

# header
INC := -I$(INC_DIR)

# src files
SRC := src/main.c src/utils.c \

LIBFT_SRC := libft/ft_strcmp libft/ft_strlen \

# object
OBJ := $(SRC:.c=.o)

# others
.PHONY: all clean fclean libft

# default target
all: $(NAME) libft 

# build libft : check
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)

$(LIBFT): $(LIBFT_OBJ)
	$(MAKE) $(LIBFT_SRC)

$(FT_PRINTF): $(FT_PRINTF_OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GET_NEXT_LINE): $(GET_NEXT_LINE_OBJ)
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

# Compiling
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
	rm -f $(LIBFT_OBJ)
	rm -f $(FT_PRINTF_OBJ)
	rm -f $(GET_NEXT_LINE_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	rm -f $(NAME)

# includes files in sub-directories
vpath = get_next_line ft_printf

#rebuild
re: fclean all
