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
	void		*mlx_pointer;
	void		*window_pointer;
	char		**map;
	size_t		map_cur_row;
	size_t		map_max_row;
	size_t		map_column;
	size_t		map_collectives;
	size_t		map_player;
	size_t		map_exit;
}	t_game;

/* typedef struct s_map
{
	int		row;
	int		column;
	int		collectives;
	int		player;
	int		exit;
}	t_map;
 */
//utils.c
int	clean_exit(int fd, t_game *game_to_free, char *str_to_free, char *str);
int	free_and_report_error(char *str_to_free, char *str);
int	report_error(char *str);

#endif