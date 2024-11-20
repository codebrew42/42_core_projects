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

NAME		= liblibft.a

LIBFT_SRC	= ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_putchar_fd.c ft_strchr.c ft_striteri.c ft_strjoin.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c ft_strdup.c \
			ft_last_node.c ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
			ft_lstnew.c ft_lstsize.c ft_strcmp.c ft_lstlast.c 

GNL_SRC		= get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

PRINTF_SRC	= ft_printf/ft_printf.c \
			ft_printf/printing_utils.c

SRCS		= $(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC)
OBJS		= $(SRCS:.c=.o)

HEADER		= includes/libft.h \
			get_next_line/includes/get_next_line.h \
			ft_printf/includes/ft_printf.h

CFLAGS		= -Wall -Wextra -Werror -fPIE
CC			= cc
RM			= rm -f
AR			= ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -Iget_next_line/includes \
		-Ift_printf/includes -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
