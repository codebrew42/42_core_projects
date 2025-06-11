NAME		=	get_next_line

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	get_next_line.c	#get_next_line_utils.c
OBJ_DIR		=	objects
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR	=	../../../rank_00/libft/code
LIBFT_SRCS	=	$(LIBFT_DIR)/ft_strchr.c	$(LIBFT_DIR)/ft_strlen.c \
				$(LIBFT_DIR)/ft_memcpy.c	$(LIBFT_DIR)/ft_strjoin.c \
				$(LIBFT_DIR)/ft_strdup.c	$(LIBFT_DIR)/ft_calloc.c
LIBFT_OBJS	=	$(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re