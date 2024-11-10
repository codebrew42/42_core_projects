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
	int			map_mem_allocated;
	size_t		map_row_idx;
	size_t		map_row;
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


//utils_main.c
void	free_game(t_game *game);
int		clean_exit(int fd, t_game *game, char *str, char *msg);
int		clean_exit_double(int fd, t_game *game, char **str, char *msg);
int		report_error(char *str);
int		init_game(t_game **game);

//for_debug.c : //rm
void	print_t_game(t_game *game);
void	print_map(t_game *game);

#endif