#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> //open
# include <errno.h>
# include <string.h>
# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/get_next_line/includes/get_next_line.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	void	*mlx_pointer;
	void	*window_pointer;
	char	**map;
	int		map_row;
	int		map_column;

} t_game;

//utils.c
int report_error(char *str);

#endif