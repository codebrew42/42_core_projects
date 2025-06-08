NAME = brain
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@

%.o : %.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean clean re