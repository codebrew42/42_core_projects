# ex04

NAME = replacementProgram
SRC = main.cpp
OBJ = $(SRC:.cpp=.o) #memorize 1
CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ) #memorize 2
	$(CC) $(CFLAG) $(OBJ) -o $@

%.o : %.cpp #memorize 3
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re