NAME		:=	philo

SRC			:=	src/display.c \
				src/init.c \
				src/main.c \
				src/terminate.c \
				src/threads.c

OBJ_DIR		:= obj

OBJ			:= $(SRC:src/%.c=$(OBJ_DIR)/%.o)

CC			:= gcc
CFLAG		:= -Wall -Wextra -Werror -I includes
RM			:= rm -rf

$(NAME)		: $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OBJ_DIR)/$(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean			:
	$(RM) $(OBJ_DIR)

fclean			: clean
	$(RM) $(OBJ_DIR)/$(NAME)

re				: fclean all

all				: $(NAME)

.PHONY			: all clean fclean re
