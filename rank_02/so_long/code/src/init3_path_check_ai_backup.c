#include "../includes/so_long.h"

int check_next_position(t_path *path, t_game *game, size_t x, size_t y)
{
    if (game->map[y][x] == 'C' && !path->visited[y][x])
    {
        path->items_found++;
        path->visited[y][x] = 1;
        return (1);
    }
    else if (game->map[y][x] == 'E' && !path->visited[y][x])
    {
        path->exit_found = 1;
        path->visited[y][x] = 1;
        return (1);
    }
    else if (game->map[y][x] == '0' && !path->visited[y][x])
    {
        path->visited[y][x] = 1;
        return (1);
    }
    return (0);
}

int is_valid_move(t_path *path, t_game *game, size_t x, size_t y)
{
    if (x >= game->map_column || y >= game->map_row)
        return (0);
    if (path->visited[y][x] == -1)
        return (0);
    return (1);
}

int explore_directions(t_path *path, t_game *game, size_t x, size_t y)
{
    int dx[4];
    int dy[4];
    int i;

    dx[0] = 1;   // right
    dy[0] = 0;
    dx[1] = 0;   // down
    dy[1] = 1;
    dx[2] = -1;  // left
    dy[2] = 0;
    dx[3] = 0;   // up
    dy[3] = -1;

    i = 0;
    while (i < 4)
    {
        if (is_valid_move(path, game, x + dx[i], y + dy[i]))
            if (check_next_position(path, game, x + dx[i], y + dy[i]))
                return (1);
        i++;
    }
    return (0);
}

int valid_path_found(t_path *path, t_game *game)
{
    size_t  x;
    size_t  y;

    x = game->x_player_pos;
    y = game->y_player_pos;
    path->visited[y][x] = 1;

    while (1)
    {
        if (!explore_directions(path, game, x, y))
            break;
        if (path->items_found == game->map_items && path->exit_found)
            return (1);
    }
    return (0);
}

int has_no_valid_path(t_game *game)
{
    t_path  *path;

    if (allocate_path_data(&path, game))
        return (clean_exit(-1, game, NULL, "Error\n: has_no_valid_path"));
    if (init_int_arr(path, game))
        return (free_path_and_clean_exit(path, game, "Error\n: Malloc"));
    
    if (!valid_path_found(path, game))
    {
        free_path(path, game->map_row);
        return (clean_exit(-1, game, NULL, "Error\n: No valid path found"));
    }
    free_path(path, game->map_row);
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
