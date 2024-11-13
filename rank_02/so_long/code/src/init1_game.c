/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:40:03 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/10 21:40:03 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_pointers(t_game *game)
{
	game->p_mlx = mlx_init();
	if (!game->p_mlx)
		return (clean_exit(-1, game, NULL, "Error\n: MLX init failed"));
	game->p_window = mlx_new_window(game->p_mlx, (game->map_column - 1) * PIXEL,
			(game->map_row + 1) * PIXEL, "so_long");
	if (!game->p_window)
		return (clean_exit(-1, game, NULL, "Error\n: Window creation failed"));
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
	(*game)->p_mlx = NULL;
	(*game)->p_window = NULL;
	(*game)->map = NULL;
	(*game)->map_mem_allocated = 0;
	(*game)->x_player_pos = 0;
	(*game)->y_player_pos = 0;
	(*game)->steps = 0;
	(*game)->map_row_idx = 0;
	(*game)->map_row = 0;
	(*game)->map_column = 0;
	(*game)->map_items = 0;
	(*game)->map_player = 0;
	(*game)->map_exit = 0;
	return (0);
}
