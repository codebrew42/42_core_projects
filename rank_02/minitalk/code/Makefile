# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 13:50:58 by jiepark           #+#    #+#              #
#    Updated: 2024/10/23 13:50:58 by jiepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories and Libraries
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
INC = -I include -I $(PRINTF_DIR)/includes

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Source and Object files
CLIENT_SRC = client.c
SERVER_SRC = server.c
OBJ = $(CLIENT_SRC:.c=.o) $(SERVER_SRC:.c=.o)

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(LIBFT_DIR) -L$(PRINTF_DIR)
LDLIBS = -lft -lftprintf

# Targets
.PHONY = all clean fclean re

# Default: Build everything
all: $(LIBFT) $(PRINTF) server client

# Server target
server: $(SERVER_SRC:.c=.o) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $< $(LDFLAGS) $(LDLIBS) -o $@

# Client target
client: $(CLIENT_SRC:.c=.o) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $< $(LDFLAGS) $(LDLIBS) -o $@

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build libraries
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Cleaning rules
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(LIBFT) $(PRINTF) server client

re: fclean all
