NAME := libget_next_line.a

SRCS := get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:%.c=%.o)

LIBFT_DIR := ../libft
INC_DIR := includes
HEADER := -I$(INC_DIR)

CC := cc
FLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)

%.o: %.c $(INC_DIR)/*.h
	$(CC) -c $(FLAGS) $(HEADER) $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
