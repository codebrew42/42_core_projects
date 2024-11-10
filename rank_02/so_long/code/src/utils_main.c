/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:01:59 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/07 18:01:59 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	if (!game)
		return ;
	game->map_row_idx = 0;
	while (game->map_mem_allocated && game->map_row_idx < game->map_row)
	{
		free(game->map[game->map_row_idx]);
		game->map_row_idx++;
	}
	free(game->map);
	free(game);
}
// int	clean_exit(int fd, t_game *game, char **str, char *msg)
// {
// 	int		i;

// 	if (fd >= 0)
// 		close(fd);
// 	if (game)
// 		free_game(game);
// 	if (str)
// 	{
// 		// Try to dereference first element to check if it's a valid pointer
// 		if (str[0] && (size_t)str[0] > 4096)  // Basic pointer validity check
// 		{
// 			// It's likely a double array
// 			i = 0;
// 			while (str[i])
// 				free(str[i++]);
// 			free(str);
// 		}
// 		else
// 			// It's a single string
// 			free(str);
// 	}
// 	if (msg)
// 		ft_printf("%s", msg);
// 	return (1);
// }

int	clean_exit_double(int fd, t_game *game, char **str, char *msg)
{
	char	**str_arr;
	int		i;

	if (fd >= 0)
		close(fd);
	if (game)
		free_game(game);
	if (str)
	{
		str_arr = (char **)str;
		i = 0;
		while (str_arr[i])
		{
			free(str_arr[i]);
			i++;
		}
		free(str_arr);
	}
	if (msg)
		ft_printf("%s", msg);
	return (1);
}

int	clean_exit(int fd, t_game *game, char *str, char *msg)
{
	if (fd >= 0)
		close(fd);
	if (game)
		free_game(game);
	if (str)
		free(str);
	if (msg)
		ft_printf("%s", msg);
	return (1);
}

int	report_error(char *str)
{
	if (str)
		ft_printf("%s", str);
	return (1);
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
