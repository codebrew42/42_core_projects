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

# define CONGRATULATIONS_MSG "🎉 Congratulations! You Won! 🎉\n"
# define PIXEL			32
# define UP				1
# define DOWN			2
# define LEFT			3
# define RIGHT			4
# define CLOSE_BUTTON	17
# define CANT_MOVE		5

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
# endif

typedef struct s_image
{
	void			*wall;
	void			*floor;
	void			*item;
	void			*player;
	void			*exit;
}	t_image;

typedef struct s_path
{
	int				**visited;
	size_t			x_prev;
	size_t			y_prev;
	size_t			items_found;
	size_t			exit_found;
	int				dx[4];
	int				dy[4];
}	t_path;

typedef struct s_game
{
	void			*p_mlx;
	void			*p_window;
	char			**map;
	int				map_mem_allocated;
	unsigned int	x_player_pos;
	unsigned int	y_player_pos;
	unsigned int	steps;
	size_t			map_row_idx;
	size_t			map_row;
	size_t			map_column;
	size_t			map_items;
	size_t			map_player;
	size_t			map_exit;
	t_image			image;
}	t_game;

/* init1_game.c : norm (X: rm notes) */
int		init_int_arr(t_path *path, t_game *game);
void	init_direction(int *dx, int *dy);
int		init_pointers(t_game *game);
int		init_game(t_game **game);

/* init2_map.c : Map Initialization and Validation  */
int		validate_map_characters(t_game *game, char *line, int fd);
int		has_invalid_wall(t_game *game, char *line, int fd);
int		ct_row(t_game *game, const char *param);
int		invalid_map(t_game *game, const char *map);
int		read_map(t_game *game, const char *param);

/* init3. has_path_check.c */
int		check_next_position(t_path *path, t_game *game, size_t x, size_t y);
int		path_finder(t_path *path, t_game *game, int x, int y);
int		allocate_path_data(t_path **path, t_game *game);
int		has_no_valid_path(t_game *game);

/*free.c : norm (OK)*/
void	free_game(t_game *game);
void	free_images_window_and_mlx_ptr(t_game *game);
void	free_path(t_path *path, size_t rows);

/* error.c : Report Error and Cleanup*/
int		is_valid_map_char(char c);
int		free_path_and_clean_exit(t_path *path, t_game *game, char *msg);
int		clean_exit_double(int fd, t_game *game, char **str, char *msg);
int		clean_exit(int fd, t_game *game, char *str, char *msg);
int		report_error(char *str);

/* graphic.c : Report Error and Cleanup*/
void	display_steps(t_game *g);
void	place_images_in_game(t_game *game);
void	render_image(t_game *game, void *image, int x, int y);
void	render_map(t_game *game);

/* controls.c */
int		move_player_to(t_game *game, int dest_x, int dest_y);
int		handle_movement_input(t_game *game, unsigned int direction);
int		key_control(unsigned int command, t_game *game);

#endif