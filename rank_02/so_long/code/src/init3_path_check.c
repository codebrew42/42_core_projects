#include "../includes/so_long.h"

// int check_next_position(t_path *path, t_game *game, size_t x, size_t y)
// {

// }

// int is_valid_move(t_path *path, t_game *game, size_t x, size_t y)
// {

// }

// int explore_directions(t_path *path, t_game *game, size_t x, size_t y)
// {

// }

int	surrounded_by_walls(t_path *path, t_game *game, int dx[], int dy[])
{
	int	i;
	int	*visit_cur;
	
	i = 0;
	while (i < 4)
	{
		visit_cur = &path->visited[path->y_prev + dy[i]][path->x_prev + dx[i]];
		if (visit_cur == 0)
			break ;
		if (i == 3) //not found, why? 4 dir surrounded with walls
			return (free_path_and_clean_exit(path, game, "Error\n: no path"));
		i++;
	}
	return (0);
}

/**
 * @return 0 if no valid path found, 1 if any found
 */
int	valid_path_found(t_path *path, t_game *game, int dx[], int dy[])
{
	char	next_pos;
	int		i;
	int		*visit_cur;

	printf("%zu,%zu", path->x_prev, path->y_prev); //rm
	i = 0;
	while (1)
	{
		if (surrounded_by_walls(path, game, dx, dy))
			return (0);
		next_pos = game->map[path->y_prev + dy[i]][path->x_prev + dx[i]];
		visit_cur = &path->visited[path->y_prev + dy[i]][path->x_prev + dx[i]];
		if (visit_cur != -1) //0: available(C/P/E/0), -1: not available(Wall)
		{
			if (next_pos == 'E' && path->items_found == game->map_items) //suc: found
			{
				free_path(path, game->map_row);
				return (4);//4: on success
			}
			else if (next_pos == 'C')
			{
				visit_cur = 1;
				path->items_found++;
				path->x_prev = path->x_prev + dx[i];
				path->y_prev = path->y_prev + dy[i];
				return (valid_path_found(path, game, dx, dy));
			}
			else if (next_pos == '0')
			{
				visit_cur = 1;
				path->x_prev = path->x_prev + dx[i];
				path->y_prev = path->y_prev + dy[i];
				return (valid_path_found(path, game, dx, dy));
			}
		}
		else
			return (1); //check
		i++;
	}
	return (0);
}


/**
 * @brief create an int array 'path->visited[][]' same size as game->map:
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
	//print_game_map(game); //rm
	while (i < game->map_row)
	{
		j = 0;
		while (j < game->map_column)
		{
			//printf("[%zu,%zu] %c ", i, j, game->map[i][j]); //rm
			if (game->map[i][j] == '0' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'P' || game->map[i][j] == 'E')
				path->visited[i][j] = 0;
			else
				path->visited[i][j] = -1;
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
	(*path)->visited = malloc(sizeof(int *) * (game->map_row));
	if (!(*path)->visited)
		return (free_path_and_clean_exit(*path, game, "Error\n: Malloc"));
	i = 0;
	while (i < game->map_row)
	{
		(*path)->visited[i] = malloc(sizeof(int) * (game->map_column));
		if (!(*path)->visited[i])
		{
			while (--i > 0)
			{
				free((*path)->visited[i]);
			}
			free((*path)->visited);
			return (free_path_and_clean_exit(*path, game, "Error\n: Malloc"));
		}
		i++;
	}
	return (0);
}

int	has_no_valid_path(t_game *game)
{
	t_path	*path;
	int		dx[4];
	int		dy[4];

	dx[0] = 1;
	dy[0] = 0;
	dx[1] = 0;
	dy[1] = 1;
	dx[2] = -1;
	dy[2] = 0;
	dx[3] = 0;
	dy[3] = -1;
	if (allocate_path_data(&path, game))
		return (clean_exit(-1, game, NULL, "Error\n: has_no_valid_path"));
	if (init_int_arr(path, game))
		return (free_path_and_clean_exit(path, game, "Error\n: init_int_arr"));
	path->visited[path->y_prev][path->x_prev] = 1;
	if (valid_path_found(path, game, dx, dy))
		return (free_path_and_clean_exit(path, game, "Error\n: no_valid_path"));
	free_path(path, game->map_row);
	return (0);
}
