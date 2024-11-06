#include "../includes/so_long.h"

void	init_game(t_game *game)
{
	game->mlx_pointer = NULL;
	game->window_pointer = NULL;
	game->map = NULL;
	game->map_column = 0;
	game->map_row = 0;
}

int	read_valid_map(char *param, t_game *game)
{
	int		fd;
	char	**temp_map = NULL;
	int		i;

	fd = open(param, O_RDONLY);
	if (fd < 0 || (ft_strcmp(param, ".ber") != 0))
		return (1);
	i = 0;
	init_game(game);
	while (1)
	{
		temp_map[i] = get_next_line(fd);
		if (!temp_map[i])
		{
			if (!game->map_row)
				return (report_error("Error: leer map!"));
			break ;
		}
		game->map_row++;
		i++;
	}
	game->map = malloc(sizeof(char *) * (game->map_row + 1));
	if (!game->map)
		return (1);
	game->map = temp_map;
	game->map[game->map_row + 1] = NULL;
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game = NULL;

	if (ac != 2)
		return (1);
	if (read_valid_map(av[1], game) == 1)
		return (1);	
}

/*
int main()
{
	void    *mlx_connection;
	void	*mlx_window1;
	void	*mlx_window2;
	int		i;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (1);
	//create two windows
	mlx_window1 = mlx_new_window(mlx_connection, 500, 500, "window1");
	if (mlx_window1 == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	mlx_window2 = mlx_new_window(mlx_connection, 500, 500, "window2");
	if (mlx_window2 == NULL)
	{
		mlx_destroy_window(mlx_connection, mlx_window1);
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	//color
	i = 0;
	int j = 0;
	while (i++ < 100)
	{	
		while (j++ < 150)
			mlx_pixel_put(mlx_connection, mlx_window1, 100+i, 100+j, 0xff2500);
	}
	//to keep the proc alive
	mlx_loop(mlx_connection);
}
*/