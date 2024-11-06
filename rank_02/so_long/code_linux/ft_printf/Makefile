NAME := ft_printf.a

SRCS := ft_printf.c printing_utils.c
OBJS := $(SRCS:%.c=%.o)

LIBFT_DIR := ../libft
INC_DIR := includes ../libft/includes
HEADER := -Iincludes -I../libft/includes

CC := gcc
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
