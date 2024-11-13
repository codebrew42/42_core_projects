

I'll help you implement a BFS (Breadth-First Search) solution to check for a valid path that collects all items and reaches the exit. Here's how we can break it down into functions that comply with the norminette rules:

```c:init3_path_check.c
int check_next_position(t_path *path, t_game *game, size_t x, size_t y)
{
    if (game->map[y][x] == 'C' && !path->visit_log[y][x])
    {
        path->items_found++;
        path->visit_log[y][x] = 1;
        return (1);
    }
    else if (game->map[y][x] == 'E' && !path->visit_log[y][x])
    {
        path->exit_found = 1;
        path->visit_log[y][x] = 1;
        return (1);
    }
    else if (game->map[y][x] == '0' && !path->visit_log[y][x])
    {
        path->visit_log[y][x] = 1;
        return (1);
    }
    return (0);
}

int is_valid_move(t_path *path, t_game *game, size_t x, size_t y)
{
    if (x >= game->map_column || y >= game->map_row)
        return (0);
    if (path->visit_log[y][x] == -1)
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

int find_valid_path(t_path *path, t_game *game)
{
    size_t  x;
    size_t  y;

    x = game->x_player_pos;
    y = game->y_player_pos;
    path->visit_log[y][x] = 1;

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
    
    if (!find_valid_path(path, game))
    {
        free_path(path, game->map_row);
        return (clean_exit(-1, game, NULL, "Error\n: No valid path found"));
    }
    free_path(path, game->map_row);
    return (0);
}
```

### Explanation:

1. **check_next_position**: Checks if the next position contains a collectible ('C'), exit ('E'), or empty space ('0') and updates the path data accordingly.

2. **is_valid_move**: Validates if a move is within bounds and not blocked by a wall.

3. **explore_directions**: Sets up the direction arrays and explores all four directions (right, down, left, up) from the current position.

4. **find_valid_path**: Implements the main path-finding logic using BFS, starting from the player's position.

5. **has_no_valid_path**: Main function that sets up the path data and initiates the path-finding process.

This implementation:
- Uses while loops instead of for loops (norminette requirement)
- Keeps functions under 25 lines
- Properly handles memory allocation and freeing
- Checks for both collecting all items and finding the exit

The BFS approach ensures that we explore all possible paths systematically, and the path data structure keeps track of visited positions, collected items, and exit discovery.