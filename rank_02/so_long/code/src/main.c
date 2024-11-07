/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:50:14 by jiepark           #+#    #+#             */
/*   Updated: 2024/11/07 17:50:16 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**temp_map = NULL;
	int		i;
	int		fd;
	size_t		prev_map_column;

	fd = open(param, O_RDONLY);
	if (fd < 0)
		return (1);
			write(1, "E", 1);

/*
	if ((ft_strcmp(param, ".ber") != 0))
		return (1);
			write(1, "E", 1);

	if (fd < 0 || (ft_strcmp(param, ".ber") != 0))
		return (1);
			write(1, "E", 1);
*/
    temp_map = malloc(sizeof(char *) * 500); //max row:edit
    if (!temp_map)
	{
        return (free_close_and_report_error(fd, NULL, "malloc failed!"));
	}
	i = 0;
	init_game(game);
	while (1)
	{
		temp_map[i] = get_next_line(fd);
		prev_map_column = ft_strlen(temp_map[i]);
			write(1, "C", 1);

		if (!temp_map[i])
		{
			if (!game->map_row)
				return (free_close_and_report_error(fd, *temp_map, "leer map!"));
			game->map[i + 1] = NULL;
			break ;
		}
			write(1, "D", 1);

		game->map[i] = malloc(prev_map_column + 1);
		if (!game->map[i] || prev_map_column != ft_strlen(temp_map[i]))
			return (free_close_and_report_error(fd, *temp_map, "malloc or column length!"));
		game->map[i] = temp_map[i];
		game->map_row++;
		i++;
	}
	game->map[i] = NULL; // Set the last element to NULL
    free(temp_map); // Free temp_map after copying
    close(fd); // Close the file descriptor
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game = NULL;

	if (ac != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (read_valid_map(av[1], game) == 1)
		return (1);	
	//dsp check
	 for (int i = 0; i < game->map_row; i++)
    {
        printf("%s", game->map[i]); // Print each line of the map
    }
    // Free the allocated map after use
    for (int i = 0; i < game->map_row; i++)
    {
        free(game->map[i]); // Free each line
    }
    free(game->map); // Free the map array itself
	write(1, "A", 1);
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
