NAME					= megaphone
CXX						= c++
CXXFLAGS				= -Wall -Wextra -Werror -std=c++98

SRC						= Megaphone.cpp
OBJ						= $(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re