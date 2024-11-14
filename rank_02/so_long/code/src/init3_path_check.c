#include "../includes/so_long.h"

/**
 * @return	depends on the next position
 * 	returns 
 * 		 1, "Stop searching" on success(Exit found, All items found)
 * 		 2, "Keep searching" (valid position: C, 0, P)
 * 		 0, "Stop searching" (out of map, already visited, encounters wall, exit found but not all items found)
 * 		-1, "Stop seraching" undefined or 'P'(invalid)
  */
int	check_next_position(t_path *path, t_game *game, size_t x, size_t y)
{
	char	next;

	if (y >= game->map_row || x >= game->map_column)
		return (0);
	next = game->map[y][x];
	if (path->visited[y][x] != 0)
		return (0);
	path->visited[y][x] = 1;
	if (next == 'E' && game->map_items == path->items_found)
		return (1);
	else if (next == 'E' || next == '1')
		return (0);
	else if (next == 'C' || next == '0' || next == 'P')
	{
		if (next == 'C')
			path->items_found++;
		return (2);
	}
	return (-1);
}

// int check_next_position(t_path *path, t_game *game, size_t x, size_t y)
// {
//     char    next;

//     if (y >= game->map_row || x >= game->map_column)
//         return (0);
//     next = game->map[y][x];
//     if (path->visited[y][x] != 0)
//         return (0);
//     path->visited[y][x] = 1;
    
//     // Handle collectibles first
//     if (next == 'C')
//     {
//         path->items_found++;
//         return (2);
//     }
//     // Check exit condition
//     if (next == 'E')
//     {
//         path->exit_found = 1;
//         if (path->items_found == game->map_items)
//             return (1);
//         return (0);
//     }
//     // Handle valid movement spaces
//     if (next == '0' || next == 'P')
//         return (2);
//     // Handle walls
//     if (next == '1')
//         return (0);
//     // Handle invalid characters
//     return (-1);
// }

/**
 * @return 0 if valid path not found, 1 if any found
 */
int	path_finder(t_path *path, t_game *game, int x, int y)
{
	size_t	next_x;
	size_t	next_y;
	int		i;
	int		res;
	int		dx[4];
	int		dy[4];

	init_direction(dx, dy);
	i = 0;
	while (i < 4)
	{
		next_x = x + dx[i];
		next_y = y + dy[i];
		res = check_next_position(path, game, next_x, next_y);
		if (res == 1)
			return (1);
		if (res == 2)
		{
			if (path_finder(path, game, next_x, next_y))
				return (1);
		}
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
// Add this debug function
void debug_path_state(t_path *path, t_game *game)
{
    ft_printf("Debug:\n");
    ft_printf("Items found: %d/%d\n", path->items_found, game->map_items);
    ft_printf("Exit found: %d\n", path->exit_found);
    ft_printf("Player pos: (%d, %d)\n", game->x_player_pos, game->y_player_pos);
}


int	has_no_valid_path(t_game *game)
{
	t_path	*path;

	if (allocate_path_data(&path, game))
		return (clean_exit(-1, game, NULL, "Error\n: has_no_valid_path1"));
	if (init_int_arr(path, game))
		return (free_path_and_clean_exit(path, game, "Error\n: init_int_arr"));

    // Add debug print before path finding
    ft_printf("Starting path check:\n");
    ft_printf("Total items needed: %d\n", game->map_items);
    ft_printf("Starting position: (%d, %d)\n", game->x_player_pos, game->y_player_pos);
    
    path->visited[game->y_player_pos][game->x_player_pos] = 1;
    if (!path_finder(path, game, game->x_player_pos, game->y_player_pos))
    {
        // Add debug print on failure
        debug_path_state(path, game);
        return (free_path_and_clean_exit(path, game, "Error\n: no_valid_path2"));
    }
	//if (!path_finder(path, game, game->x_player_pos, game->y_player_pos))
//		return (free_path_and_clean_exit(path, game, "Error\n: no_valid_path2"));
	free_path(path, game->map_row);
	return (0);
}
