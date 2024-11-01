# Define the name of the library
NOM=libmlx.a

# List all source files
SRC=mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m \
    mlx_xpm.c mlx_int_str_to_wordtab.c mlx_png.c mlx_mouse.m

# Create object files from source files
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)

# Additional compiler flags
CFLAGS+=-O2 -Imlx -Wall -Wextra -Werror

# Rule to compile the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile the object files from .m files
%.o: %.m
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the static library
all: $(NOM)

$(NOM): $(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

# Clean up object files and the library
clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

# Rebuild everything
re: clean all

