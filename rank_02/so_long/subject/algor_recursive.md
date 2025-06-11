# Question : so_long

## ver1
/**
 * @return 0 if valid path not found, 1 if any found
 */
int	path_finder(t_path *path, t_game *game, int x, int y)
{
	size_t		next_x;
	size_t		next_y;
	int			i;
	int			res;
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
	i = 0;
	while (i < 4)
	{
		next_x = x + dx[i];
		next_y = y + dy[i];
		res = check_next_position(path, game, next_x, next_y);
		if (res == 1)
			return (1);
		else if (res == 2)
		{
			// path_finder(path, game, next_x, next_y);
			if (path_finder(path, game, next_x, next_y) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
## ver2
/**
 * @return 0 if valid path not found, 1 if any found
 */
int	path_finder(t_path *path, t_game *game, int x, int y)
{
	size_t		next_x;
	size_t		next_y;
	int			i;
	int			res;
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
	i = 0;
	while (i < 4)
	{
		next_x = x + dx[i];
		next_y = y + dy[i];
		res = check_next_position(path, game, next_x, next_y);
		if (res == 1)
			return (1);
		else if (res == 2)
		{
			path_finder(path, game, next_x, next_y);

		}
		i++;
	}
	return (0);
}
## Q. why this ver1, ver2 causes diff result

The two versions produce different results because of how they handle the recursive call's return value. Let's analyze both versions:

### Version 1 (Correct)
```c
if (res == 2)
{
    if (path_finder(path, game, next_x, next_y) == 1)
        return (1);
}
```

In this version:
1. Makes recursive call
2. **Checks the return value** of the recursive call
3. If recursive call returns 1 (found valid path), it propagates this success up by returning 1
4. If recursive call returns 0, continues searching other directions

### Version 2 (Incorrect)
```c
if (res == 2)
{
    path_finder(path, game, next_x, next_y);
}
```

In this version:
1. Makes recursive call
2. **Ignores the return value** of the recursive call
3. Even if a valid path is found in deeper recursion, this information is lost
4. Always continues to next direction regardless of result

### Example Scenario:
```
Map:
P 0 C
0 0 E
```

Version 1:
1. Starts at P
2. Moves right (res = 2)
3. Recursive call finds C and E
4. Returns 1 up through recursion
5. Main function gets 1 (success)

Version 2:
1. Starts at P
2. Moves right (res = 2)
3. Recursive call finds C and E
4. Return value is ignored
5. Continues checking other directions
6. Main function gets 0 (failure)

### Fix:
Always check and handle the return value of recursive calls when searching for a path. The correct version (Version 1) properly propagates the success/failure status through the entire recursive call stack.