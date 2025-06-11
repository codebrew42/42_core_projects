NAME		:= FIND_SHORTEST

OBJS		:= src/main.c

HEADER		:= includes/find_shortest.h


LIBFT_DIR	:= ../../rank_00/libft/code

LIBFT_OBJS	:= $(LIBFT_DIR)/ft_strcmp.c

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

all: $(NAME)
	@echo "Building $(NAME)"

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Linking $^"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

.PHONY: clean