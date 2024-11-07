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
NAME         = liblibft.a

# Updated source files
SRCS         = ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_isalnum.c \
               ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
               ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
               ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
               ft_strchr.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
               ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
               ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
               ft_strdup.c ft_last_node.c ft_lstadd_back.c ft_lstadd_front.c \
               ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
               ft_lstsize.c ft_strcmp.c

BSRCS        = ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c  \
               ft_lstsize.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

# Object files
OBJS         = $(patsubst %.c, %.o, $(SRCS))
BOBJS        = $(patsubst %.c, %.o, $(BSRCS))

# Header file
HEADER       = includes/libft.h
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

# Bonus target
bonus: $(OBJS) $(BOBJS)
	$(AR) $(NAME) $^

# Clean object files
clean:
	$(RM) $(OBJS) $(BOBJS)

# Full clean
fclean: clean
	$(RM) $(NAME)

# Rebuild the library
re: fclean all

.PHONY: all clean fclean re bonus
