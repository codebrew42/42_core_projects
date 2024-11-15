/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:19:02 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/13 21:19:02 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_path(t_path *path, size_t rows)
{
	size_t	i;

	i = 0;
	while (i < rows)
		free(path->visited[i++]);
	free(path->visited);
	free(path);
}

void	free_images_window_and_mlx_ptr(t_game *game)
{
	if (game->image.wall)
		mlx_destroy_image(game->p_mlx, game->image.wall);
	if (game->image.floor)
		mlx_destroy_image(game->p_mlx, game->image.floor);
	if (game->image.item)
		mlx_destroy_image(game->p_mlx, game->image.item);
	if (game->image.player)
		mlx_destroy_image(game->p_mlx, game->image.player);
	if (game->image.exit)
		mlx_destroy_image(game->p_mlx, game->image.exit);
	if (game->p_window)
		mlx_destroy_window(game->p_mlx, game->p_window);
	mlx_destroy_display(game->p_mlx);
	free(game->p_mlx);
}

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
	if (game->map)
		free(game->map);
	if (game->p_mlx)
		free_images_window_and_mlx_ptr(game);
	free(game);
}
