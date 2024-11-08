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
/* 
int	read_map_characters(t_game *game, char *line, int fd)
{
	int		i;

	if (game->map_cur_row && ft_strlen(line) != game->map_column)
		return (clean_exit(fd, game, line, "Map is not rectangular"));
	if (game->map_cur_row == 0 || game->map_cur_row == game->map_column)
	{
		i = 0;
		while (i < game->map_column)
		{
			if (game->map[game->map_cur_row][i] != '1')
				return (clean_exit(fd, game, line, "Missing wall"));
			i++;
		}
	}
	i = 0;
	while (i < game->map_column)
	{
		if (game->map[game->map_cur_row][0] != '1' ||
			game->map[game->map_cur_row][game->map_column - 1] != '1')
			return (clean_exit(fd, game, line, "Missing wall"));
		if (game->map[game->map_cur_row][i] != 'C')
			game->map_collectives++;
		if (game->map[game->map_cur_row][i] != 'P')
			game->map_player++;
		if (game->map[game->map_cur_row][i] != 'E')
			game->map_exit++;
		i++;
	}
} */


int	has_valid_wall(t_game *game, char *line, int fd)
{
	size_t		i;
	size_t		len;

	len = ft_strlen(line);
	if (!len || !line)
		return (clean_exit(fd, game, line, "Empty line"));
	if (game->map_cur_row == game->map_max_row)
	{
		if (!(len == game->map_column && line[len - 1] == '\n')
			|| (len == game->map_column - 1 && line[len - 1] != '\n'))
			return (clean_exit(fd, game, line, "Map is not rectangular"));
	}
	if (!game->map_cur_row || game->map_cur_row == game->map_max_row)
	{
		i = 0;
		while ((i < len - 1 && line[len - 1] == '\n')
			|| (i < len && line[len - 1] != '\n'))
		{
			if (line[i] != '1')
				return (clean_exit(fd, game, line, "Missing wall"));
			i++;
		}
	}
	return (0);
}

int	update_map_max_row(t_game *game, const char *param)
{
	int		fd;
	char	*line;
	size_t	line_count;

	fd = open(param, O_RDONLY);
	if (fd < 0)
		return (1);
	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free (line);
		line_count++;
	}
	close (fd);
	game->map_max_row = line_count;
	return (0);
}

int	is_valid_map(t_game *game, const char *param)
{
	int		fd;
	char	*line;

	fd = open(param, O_RDONLY);
	if (fd < 0 || !ft_strnstr(param, ".ber", ft_strlen(param)))
		return (report_error("Opening \".ber\" file failed"));
	if (update_map_max_row(game, param))
		return (report_error("Opening file failed"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!game->map_cur_row)
				return (clean_exit(fd, game, line, "Leer map"));
			break ;
		}
		game->map_column = ft_strlen(line);
		if (has_valid_wall(game, line, fd))
			return (1);
		ft_printf("%s\n", line); //rm
		free(line);
		game->map_cur_row++;
	}
	close(fd);
	return (0);
}
/**
 * @brief Saves a map to 'game', counting 'C/P/E' line by line
 * @return 0 if the map is successfully read, 1 if it fails or is an invalid map
 * @note how to free 'char **'?
 */
int	read_map(t_game *game, const char *param)
{
	char		**temp_map;
	size_t		i;
	int			fd;

	fd = open(param, O_RDONLY);
	if (fd < 0 || ft_strnstr(param, ".ber", ft_strlen(param)))
		return (report_error("Opening file failed"));
	i = 0;
	temp_map = malloc(sizeof(char *) * (game->map_cur_row + 1));
	if (!temp_map)
		return (report_error("Malloc failed"));
	while (i < game->map_cur_row)
	{
		temp_map[i] = get_next_line(fd);

	}
	game->map[i] = NULL;
	free (temp_map);
	close(fd);
	return (0);
}


int	init_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (report_error("Malloc failed"));
	(*game)->mlx_pointer = NULL;
	(*game)->window_pointer = NULL;
	(*game)->map = NULL;
	(*game)->map_cur_row = 0;
	(*game)->map_max_row = 0;
	(*game)->map_column = 0;
	(*game)->map_collectives = 0;
	(*game)->map_player = 0;
	(*game)->map_exit = 0;
	return (0);
}


int	main(int ac, const char **av)
{
	t_game	*game;

	if (ac != 2)
		return (report_error("Usage: ./so_long map.ber"));
	if (init_game(&game))
		return (1);
	if (is_valid_map(game, av[1])) //update: map->row map->column
		return (1);
	// if (read_map(game, av[1])) //checK: nbr of c, p, e
	// 	return (1);	
	//dsp check

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
