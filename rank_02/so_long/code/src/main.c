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

/**
 * @brief Saves and checks the map characters for validity
 * 
 * This function iterates over a line of the map, counting the occurrences
 * of 'C', 'P', and 'E' characters, which represent collectives, player, 
 * and exit respectively.
 * 
 * @return 0 on success, 1 on error
 */
int	validate_map_characters(t_game *game, char *line)
{
	size_t		i;

	i = 0;
	//rm
	ft_printf("row(%d): C/P/E: %d/%d/%d\t", game->map_row_idx, game->map_collectives, game->map_player, game->map_exit);
	while (line[i])
	{
		if (line[i] == 'C')
			game->map_collectives++;
		if (line[i] == 'P')
			game->map_player++;
		if (line[i] == 'E')
			game->map_exit++;
		i++;
	}
	if (game->map_row_idx == game->map_row - 1)
	{
		if (game->map_collectives < 1)
			return (clean_exit(-1, game, 0, NULL, "Error: invalid \'C\'"));
		if (game->map_player != 1)
			return (clean_exit(-1, game, 0, NULL, "Error: invalid \'P\'"));
		if (game->map_exit != 1)
			return (clean_exit(-1, game, 0, NULL, "Error: invalid \'E\'"));
	}
	return (0);
}

/**
 * @param net_len = str length except \n
 * @note edge case how to handle? last line doesnt contain '\n'
 * free_double(&line) causes error, but free_double((char **)line) is okay
 * why? &line : takes adr of the line 
 *      (char **)line : casts the value of the line
 */
int	has_invalid_wall(t_game *game, char *line, int fd)
{
	size_t		i;
	size_t		net_len;

	net_len = ft_strlen(line);
	if (!net_len || !line)
		return (clean_exit(fd, game, 0, (char **)line, "Error: Empty line"));
	if (line[net_len - 1] == '\n')
		net_len--;
	if (net_len != game->map_column - 1)
		return (clean_exit(fd, game, 0, (char **)line, "Error: Map not even"));
	if (!game->map_row_idx || game->map_row_idx == game->map_row - 1)
	{
		i = 0;
		while (i < net_len)
		{
			if (line[i] != '1')
				return (clean_exit(fd, game, 0, (char **)line, "Error: Wall"));
			i++;
		}
	}
	if (line[0] != '1' || line[net_len - 1] != '1')
		return (clean_exit(fd, game, 0, (char **)line, "Error: Wall"));
	return (0);
}

int	update_map_row(t_game *game, const char *param)
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
	game->map_row = line_count;
	return (0);
}


/**
 * @brief checks validaty(1.file ".ber" 2.valid wall),
 * updates max_row and column, sets cur_row to 0 for later use
 * @return 0 on error, 1 on success
 */
int	is_valid_map(t_game *game, const char *param)
{
	int		fd;
	char	*line;

	fd = open(param, O_RDONLY);
	if (fd < 0 || !ft_strnstr(param, ".ber", ft_strlen(param))
		|| update_map_row(game, param))
		return (clean_exit(fd, game, 0, NULL, "Error: invalid \".ber\" file"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!game->map_row_idx)
				return (clean_exit(fd, game, 0, NULL, "Error: Leer map"));
			break ;
		}
		if (!game->map_row_idx)
			game->map_column = ft_strlen(line);
		if (has_invalid_wall(game, line, fd))
			return (clean_exit(fd, NULL, 0, NULL, NULL));
		 ft_printf("%s", line); //rm
		// ft_printf("last char: (%c)", line[ft_strlen(line) -1]); //rm
		free(line);
		game->map_row_idx++;
	}
	game->map_row_idx = 0;
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
	int			fd;
	size_t		i;

	fd = open(param, O_RDONLY);
	if (fd < 0)
		return (clean_exit(fd, game, 0, NULL, "Opening file failed"));
	game->map = malloc(sizeof(char *) * game->map_row);
	if (!game->map)
		return (report_error("Malloc failed"));
	i = 0;
	while (i < game->map_row)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			return (clean_exit(fd, game, 1, game->map, "Error: Malloc failed"));
		game->map_row_idx = i;
		validate_map_characters(game, game->map[i]);
		i++;
	}
	game->map_mem_allocated = 1;
	close(fd);
	return (0);
}

/**
 * @brief Malloc 't_game *game', assign Null, 0 to elements
 * @return 0 if malloc was successful, otherwise 1
 */
int	init_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (report_error("Malloc failed"));
	(*game)->mlx_pointer = NULL;
	(*game)->window_pointer = NULL;
	(*game)->map = NULL;
	(*game)->map_row_idx = 0;
	(*game)->map_row = 0;
	(*game)->map_column = 0;
	(*game)->map_collectives = 0;
	(*game)->map_player = 0;
	(*game)->map_exit = 0;
	(*game)->map_mem_allocated = 0;
	return (0);
}


int	main(int ac, const char **av)
{
	t_game	*game;

	if (ac != 2)
		return (report_error("Usage: ./so_long map.ber"));
	if (init_game(&game))
		return (1);
	if (is_valid_map(game, av[1]))
		return (1);
	//print_t_game(game); //rm
	write(1, "AA", 2);
	 if (read_map(game, av[1])) //checK: nbr of c, p, e
		return (1);
	write(1, "BB", 2);

	//dsp check //rm
	// char last_char = game->map[game->map_row - 1][game->map_column - 1];
	// ft_printf("ASCII value of last char: (%d)\n", last_char);
	// ft_printf("last line of the map: (%s)\n", game->map[game->map_row - 1]);
	// ft_printf("last char of the map: (%c)\n", last_char);

	// last_char = game->map[game->map_row - 1][game->map_column - 2];
	// printf("ASCII value of 2nd last char: (%d)\n", last_char);
	// printf("end last char of the map: (%c)\n", last_char);
	free_game(game); //later : 0 -> 1 since it will be malloced
	ft_printf("suc");
	return (0);
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
