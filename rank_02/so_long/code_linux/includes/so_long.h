
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"

typedef struct s_game
{
	void	*mlx_pointer;
	void	*window_pointer;
	char	**map;

} t_game;

#endif