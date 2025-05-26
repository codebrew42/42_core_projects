NAME		= ZombieHorde
CC			= c++
CFLAG		= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp Zombie.cpp zombieHorde.cpp
#imp
OBJ			= $(SRC:.cpp=.o)

#imp
all: $(NAME)

#imp
$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@

#imp
%.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean