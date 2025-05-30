NAME = violentGame
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CLFAG) $(OBJ) -o $@

$(OBJ) : $(SRC)
	$(CC) $(CFLAG) -c $< -o $@ #not sure

fclean : clean
	rm -rf $(NAME)

clean : 
	rm -rf $(OBJ)

.PHONY = fclean clean re all