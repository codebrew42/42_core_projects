NAME		= Zombie
SRC			= main.cpp	Zombie.cpp NewZombie.cpp RandomChump.cpp
CC			= c++
C_FLAG		= -Wall -Werror -Wextra -std=c++98
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

.PHONY: fclean clean all re