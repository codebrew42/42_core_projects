NAME	= phoneBook
CC		= c++
C_FLAG	= -Wall -Wextra -Werror -std=c++98 -g
SRC		= Contact.cpp main.cpp PhoneBook.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(C_FLAG) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(C_FLAG) -c $< -o $@

clean: $(OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re debug