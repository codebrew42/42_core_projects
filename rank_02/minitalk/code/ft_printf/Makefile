NAME := libftprintf.a

SRCS := ft_printf_sub_print.c ft_printf_utils.c ft_printf.c
OBJS := $(SRCS:%.c=%.o)

LIBFT_DIR := libft
INC_DIR := includes
HEADER := -I$(INC_DIR)

CC := cc
FLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(INC_DIR)/*.h
	$(CC) -c $(FLAGS) $(HEADER) $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
