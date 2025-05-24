NAME	= PhoneBook
CC		= c++
C_FLAG	= -Wall -Wextra -Werror -std=c++98
SRC		= contact.cpp main.cpp phoneBook.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
ˆˆ	$(CC) $(C_FLAG) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(C_FLAG) -c $< -o $@

clean: $(OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re