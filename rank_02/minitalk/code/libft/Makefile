# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 14:00:56 by jiepark           #+#    #+#              #
#    Updated: 2024/10/14 20:00:00 by jiepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME         = libft.a

# Updated source files
SRCS         = ft_atoi.c 

# Object files
OBJS         = $(patsubst %.c, %.o, $(SRCS))

# Header file
HEADER       = libft.h
CFLAGS       = -Wall -Wextra -Werror
CC           = cc
RM           = rm -f
AR           = ar rcs

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	$(AR) $@ $^
	ranlib $(NAME)

# Compile source files into object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS) 

# Full clean
fclean: clean
	$(RM) $(NAME)

# Rebuild the library
re: fclean all

.PHONY: all clean fclean re bonus