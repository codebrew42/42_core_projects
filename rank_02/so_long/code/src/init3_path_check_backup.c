/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3_path_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:57:24 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/13 17:57:24 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

/**
 * @brief create an int array 'path->visit_log[][]' same size as game->map:
  * init path->visit_log : check game->map, 
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
	//print_game_map(game); //rm
	while (i < game->map_row)
	{
		j = 0;
		while (j < game->map_column)
		{
			//printf("[%zu,%zu] %c ", i, j, game->map[i][j]); //rm
			if (game->map[i][j] == '0' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'P' || game->map[i][j] == 'E')
				path->visit_log[i][j] = 0;
			else
				path->visit_log[i][j] = -1;
			j++;
		}
		//printf("\n"); //rm
		i++;
	}
	return (0);
}

/**
 * @brief malloc 't_path path'
 * 			malloc path->visited[][], init path->visited (padding with 0)
 * @note 
 * 1)not cp map: check(game->map[x][y]) assign val to(path->visited[][])
 * 2)how to cp game->map to t_path path->map
 */
int	allocate_path_data(t_path **path, t_game *game)
{
	size_t		i;

	*path = malloc(sizeof(t_path));
	if (!*path)
		return (1);
	(*path)->visit_log = malloc(sizeof(int *) * (game->map_row));
	if (!(*path)->visit_log)
		return (free_path_and_clean_exit(*path, game, "Error\n: Malloc"));
	i = 0;
	while (i < game->map_row)
	{
		(*path)->visit_log[i] = malloc(sizeof(int) * (game->map_column));
		if (!(*path)->visit_log[i])
		{
			while (--i > 0)
			{
				free((*path)->visit_log[i]);
			}
			free((*path)->visit_log);
			return (free_path_and_clean_exit(*path, game, "Error\n: Malloc"));
		}
		i++;
	}
	return (0);
}

/**
 * @brief	1.set direction arrays(right->down->up->left)
 * 			2.recursively find any valid path of the given map 
 * 				: using dfs(deapth-first search)
 * @return 0 on success, 1 on fail which means the map has no valid path
 * @note	
 */
int	find_any_valid_path(t_path *path, t_game *game)
{
	int				dx[4];
	int				dy[4];
	size_t			x_cur;
	size_t			y_cur;
	size_t			i;

	if (!path || !game)
		return (1);
	dx[0] = 1;
	dy[0] = 0;
	dy[1] = 1;
	dx[1] = 0;
	dx[2] = -1;
	dy[3] = 0;
	dx[3] = -1;
	dy[2] = -1;
	path->visit_log[path->x_prev][path->y_prev] = 1;
	//print_path_data(path); //rm
	while(1)
	{
		i = 0;
		x_cur = path->x_prev;
		y_cur = path->y_prev;
		i = find_target('C', path, path->x_prev, path->y_prev);//-1:not found
		if (i >= 0 && i <= 4 && !path->visit_log[x_cur + dx[i]][y_cur + dy[i]])
		{
			x_cur = path->x_prev + dx[i];
			y_cur = path->y_prev + dy[i];
			path->items_found++;
			path->visit_log[x_cur][y_cur] = 1;
		}
		i = find_target('E', path, path->x_prev, path->y_prev); 

		else if (find_target('E', path, path->x_prev, path->y_prev))
		{
			if (path->items_found == game->map_items)
				return (0) //SUC, free it 
			else

		}

		else // == 0

	}

	curruent == 'c'/'e'? -> update 'path'
	try all four dir
		if the next pos == valid -> recursively call dfs(path, next_x, next_y)
		if invalid -> next dir(right->down->up->next) use dx[], dy[]
	return (0);
}

/**
 * @brief init path_data
 * (1)init path->visit_log : check game->map, 
 * assign 0 if accesible(P,C,E,0), -1 if not(wall) 
 */
int	has_no_valid_path(t_game *game)
{
	t_path	*path;
	int		res;

	res = 0;
	if (allocate_path_data(&path, game))
		return (clean_exit(-1, game, NULL, "Error\n: has_no_valid_path"));
	if (init_int_arr(path, game))
		return (free_path_and_clean_exit(path, game, "Error\n: Malloc"));
	print_int_map(path->visit_log, game); //rm
// start dfs from player pos
// if all items found, exit_found : free_path -> return()
	if (!find_any_valid_path(path, game))
	free_path(path, game->map_row);
	return (res);
}
