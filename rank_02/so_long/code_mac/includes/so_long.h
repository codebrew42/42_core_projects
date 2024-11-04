
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"
# include "../../MLX42/include/MLX42/MLX42.h"

typedef struct s_game
{
	void	*mlx_pointer;
	void	*window_pointer;
	char	**map;

} t_game;

#endif