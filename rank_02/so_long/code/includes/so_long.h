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

/* to save images */
typedef struct s_image
{
	void	*wall;
	void	*floor;
	void	*collectives;
	void	*player;
	void	*exit;
}	t_image;

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
	t_image		image;
}	t_game;




/* init1_game.c : t_game game Initialization and Cleanup */
int	init_pointers(t_game *game);
void	free_game(t_game *game);
int		init_game(t_game **game);

/* init2_map.c : Map Initialization and Validation  */
int		validate_map_characters(t_game *game, char *line);
int		has_invalid_wall(t_game *game, char *line, int fd);
int		ct_row(t_game *game, const char *param);
int		is_valid_map(t_game *game, const char *map);
int		read_map(t_game *game, const char *param);

/* error.c : Report Error and Cleanup*/
int		clean_exit_double(int fd, t_game *game, char **str, char *msg);
int		clean_exit(int fd, t_game *game, char *str, char *msg);
int		report_error(char *str);

/* graphic.c : Report Error and Cleanup*/
void	place_images_in_game(t_game *game);


/* Debug Functions - for_debug.c */ //rm
void	print_t_game(t_game *game); //rm
void	print_map(t_game *game); //rm

/* Game Window and Events - utils_window.c */
/*
int		init_window(t_game *game);
int		handle_keypress(int keysym, t_game *game);
int		handle_window_close(t_game *game);
*/

#endif