NAME = violentGame
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@ #not sure


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re