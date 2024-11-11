/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:19:47 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/11 15:19:47 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/get_next_line/includes/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# define PIXEL 32

# if defined(__linux__)
#  define KEY_ESC		65307
#  define KEY_W			119
#  define KEY_A			97
#  define KEY_S			115
#  define KEY_D			100
#  define KEY_UP		65362
#  define KEY_LEFT		65361
#  define KEY_DOWN		65364
#  define KEY_RIGHT		65363

# elif defined(__APPLE__) && defined(__MACH__)
#  define KEY_ESC		53
#  define KEY_W			13
#  define KEY_A			0
#  define KEY_S			1
#  define KEY_D			2
#  define KEY_UP		126
#  define KEY_LEFT		123
#  define KEY_DOWN		125
#  define KEY_RIGHT		124

# else
#  error "Unsupported platform"
# endif

/* to save images */
typedef struct s_image
{
	void	*wall;
	void	*floor;
	void	*items;
	void	*player;
	void	*exit;
}	t_image;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*window_ptr;
	char			**map;
	int				map_mem_allocated;
	unsigned int	x_player_position;
	unsigned int	y_player_position;
	unsigned int	steps;
	size_t			map_row_idx;
	size_t			map_row;
	size_t			map_column;
	size_t			map_items;
	size_t			map_player;
	size_t			map_exit;
	t_image			image;
}	t_game;

/* init1_game.c : t_game game Initialization and Cleanup */
int		init_pointers(t_game *game);
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
void	render_map(t_game *game);

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