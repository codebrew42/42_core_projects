NAME		= Fixed
SRC			= main.cpp	Fixed.cpp
CC			= c++
C_FLAG		= -Wall -Werror -Wextra -std=c++98
DEBUG_FLAG	= -DDEBUG
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(C_FLAG) $(OBJ) -o $@
 
%.o: %.cpp
	$(CC) $(C_FLAG) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: C_FLAG += $(DEBUG_FLAG)
debug: re

.PHONY: fclean clean all re debug