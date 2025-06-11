NAME = harl


SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o) #mem1
CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98 #+11
%.o = %(SRC:.cpp)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@

%.o : %.cpp #mem2
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re