## issue with : ft_itoa

if i didnt free ft_itoa(g->steps - 1), 
it caused leak. 

## TO FIX

Looking at the leak summary (70 blocks of memory, each likely from `ft_itoa` calls), this suggests that the strings created by `ft_itoa` might be accumulating over time. Let's check where else we might need memory management.

In your current code:
```c:42_core_projects_git/rank_02/so_long/code/src/graphic.c
void	display_steps(t_game *g)
{
	char	*steps_str;
	int		x;
	int		y;

	steps_str = ft_itoa(g->steps);
	if (!steps_str)
		return ;  // This could be one source of leaks - early return without freeing
	x = (g->map_column * PIXEL) / 2 - (48 / 2);
	y = (g->map_row * PIXEL) + 10;
	if (g->steps == 0)
		mlx_string_put(g->p_mlx, g->p_window, x + 40, y, 0x000000, "0");
	else
		mlx_string_put(g->p_mlx, g->p_window, x + 40, y, 0x000000,
			ft_itoa(g->steps - 1));  // <-- This is causing a leak!
	mlx_string_put(g->p_mlx, g->p_window, x, y, 0XFFF100, "Steps: ");
	mlx_string_put(g->p_mlx, g->p_window, x + 40, y, 0XFFF100, steps_str);
	free(steps_str);
	steps_str = NULL;
}
```

The leak is coming from the second `ft_itoa` call inside `mlx_string_put`! Here's the fix:

```c:42_core_projects_git/rank_02/so_long/code/src/graphic.c
void	display_steps(t_game *g)
{
	char	*steps_str;
	char	*prev_steps_str;
	int		x;
	int		y;

	steps_str = ft_itoa(g->steps);
	if (!steps_str)
		return ;
	x = (g->map_column * PIXEL) / 2 - (48 / 2);
	y = (g->map_row * PIXEL) + 10;
	
	if (g->steps == 0)
		mlx_string_put(g->p_mlx, g->p_window, x + 40, y, 0x000000, "0");
	else
	{
		prev_steps_str = ft_itoa(g->steps - 1);
		if (prev_steps_str)
		{
			mlx_string_put(g->p_mlx, g->p_window, x + 40, y, 0x000000, prev_steps_str);
			free(prev_steps_str);
		}
	}
	
	mlx_string_put(g->p_mlx, g->p_window, x, y, 0XFFF100, "Steps: ");
	mlx_string_put(g->p_mlx, g->p_window, x + 40, y, 0XFFF100, steps_str);
	free(steps_str);
	steps_str = NULL;
}
```

The key changes are:
1. Created a separate variable `prev_steps_str` for the previous step count
2. Properly free both allocated strings
3. Added error checking for memory allocation

This should resolve the memory leak as we're now properly freeing all allocated memory from both `ft_itoa` calls.