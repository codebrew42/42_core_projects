/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:40:03 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/10 21:40:03 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief used in "init3.c"
 */
void	init_direction(int *dx, int *dy)
{
	dx[0] = 1;
	dx[1] = 0;
	dx[2] = -1;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 1;
	dy[2] = 0;
	dy[3] = -1;
}

/**
 * @brief used in "init3.c"
  * creates an int array 'path->visited[][]' same size as game->map:
  * init path->visited : check game->map, 
  * assign 0 if accesible(P,C,E,0), -1 if not(wall, \n)
 * @return 0 on success, 1 on fail
 * @note change its name : init_path_data
 */
int	init_int_arr(t_path *path, t_game *game)
{
	size_t	i;
	size_t	j;

	if (!path || !game || !game->map)
		return (1);
	path->x_prev = game->x_player_pos;
	path->y_prev = game->y_player_pos;
	path->items_found = 0;
	path->exit_found = 0;
	i = 0;
	while (i < game->map_row)
	{
		j = 0;
		while (j < game->map_column)
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'P' || game->map[i][j] == 'E')
				path->visited[i][j] = 0;
			else
				path->visited[i][j] = -1;
			j++;
		}
		i++;
	}
	return (0);
}

int	init_pointers(t_game *game)
{
	game->p_mlx = mlx_init();
	if (!game->p_mlx)
		return (clean_exit(-1, game, NULL, "Error\n: MLX init failed"));
	game->p_window = mlx_new_window(game->p_mlx, (game->map_column - 1) * PIXEL,
			(game->map_row + 1) * PIXEL, "so_long");
	if (!game->p_window)
		return (clean_exit(-1, game, NULL, "Error\n: Window creation failed"));
	return (0);
}

/**
 * @brief Malloc 't_game *game', assign Null, 0 to elements
 * @return 0 if malloc was successful, otherwise 1
 */
int	init_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (report_error("Malloc failed"));
	(*game)->p_mlx = NULL;
	(*game)->p_window = NULL;
	(*game)->image.floor = NULL;
	(*game)->image.wall = NULL;
	(*game)->image.player = NULL;
	(*game)->image.item = NULL;
	(*game)->image.exit = NULL;
	(*game)->map = NULL;
	(*game)->map_mem_allocated = 0;
	(*game)->x_player_pos = 0;
	(*game)->y_player_pos = 0;
	(*game)->steps = 0;
	(*game)->map_row_idx = 0;
	(*game)->map_row = 0;
	(*game)->map_column = 0;
	(*game)->map_items = 0;
	(*game)->map_player = 0;
	(*game)->map_exit = 0;
	return (0);
}
