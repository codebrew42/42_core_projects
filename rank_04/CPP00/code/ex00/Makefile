NAME					= megaphone
C++						= c++
C++_FLAGS				= -Wall -Wextra -Werror -std=c++98

SRC						= megaphone.cpp
OBJ						= $(SRC:.cpp=.o)

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++_FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re