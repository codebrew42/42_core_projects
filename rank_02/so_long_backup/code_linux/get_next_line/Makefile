NAME := libget_next_line.a

SRCS := get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:%.c=%.o)

LIBFT_DIR := ../libft
INC_DIR := includes
HEADER := -I$(INC_DIR) -I../libft/includes

CC := cc
FLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)

%.o: %.c $(INC_DIR)/*.h $../libft/includes/libft.h
	$(CC) -c $(FLAGS) $(HEADER) $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
