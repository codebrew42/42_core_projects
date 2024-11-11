/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:44:11 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/10 21:44:11 by jiepark         ###   ########.fr        */
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
	//ft_printf("row(%d): C/P/E: %d/%d/%d\t", game->map_row_idx, game->map_collectives, game->map_player, game->map_exit);
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
			return (clean_exit(-1, game, NULL, "Error: invalid \'C\'"));
		if (game->map_player != 1)
			return (clean_exit(-1, game, NULL, "Error: invalid \'P\'"));
		if (game->map_exit != 1)
			return (clean_exit(-1, game, NULL, "Error: invalid \'E\'"));
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
	ft_printf("adr:%p", (void *)net_len); //rm
	if (!net_len || !line)
		return (clean_exit(fd, game, line, "Error: Reading line"));
	if (line[net_len - 1] == '\n')
		net_len--;
	if (net_len != game->map_column - 1)
		return (clean_exit(fd, game, line, "Error: Map is not rectangular"));
	if (!game->map_row_idx || game->map_row_idx == game->map_row - 1)
	{
		i = 0;
		while (i < net_len)
		{
			if (line[i] != '1')
				return (clean_exit(fd, game, line, "Error: Missing mid-wall"));
			i++;
		}
	}
	if (line[0] != '1' || line[net_len - 1] != '1')
		return (clean_exit(fd, game, line, "Error: Missing top/bottom-Wall"));
	return (0);
}

int	ct_row(t_game *game, const char *map_path)
{
	int		fd;
	char	*line;
	size_t	line_count;

	fd = open(map_path, O_RDONLY);
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
int	is_valid_map(t_game *game, const char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0 || !ft_strnstr(map, ".ber", ft_strlen(map)) || ct_row(game, map))
		return (clean_exit(fd, game, NULL, "Error: invalid \".ber\" file"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!game->map_row_idx)
				return (clean_exit(fd, game, NULL, "Error: Leer map"));
			break ;
		}
		if (!game->map_row_idx)
			game->map_column = ft_strlen(line);
		if (has_invalid_wall(game, line, fd))
			return (clean_exit(fd, NULL, NULL, NULL));
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
int	read_map(t_game *game, const char *map_path)
{
	int			fd;
	size_t		i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (clean_exit(fd, game, NULL, "Error: Opening file failed"));
	game->map = malloc(sizeof(char *) * (game->map_row + 1));
	if (!game->map)
		return (clean_exit(fd, game, NULL, "Error: Malloc \'game->map\'"));
	i = 0;
	game->map_mem_allocated = 1;
	while (i < game->map_row)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			return (clean_exit_double(fd, game, NULL, "Error: Malloc"));
		game->map_row_idx = i;
		if (validate_map_characters(game, game->map[i]))
			return (clean_exit(fd, NULL, NULL, NULL));
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (0);
}
