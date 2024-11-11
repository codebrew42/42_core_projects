/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:31:16 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/11 15:31:16 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_images_in_game(t_game *game)
{
	int	i;
	int	j;

	game->image.floor = mlx_xpm_file_to_image(game->p_mlx,
			"images/floor.xpm", &i, &j);
	game->image.wall = mlx_xpm_file_to_image(game->p_mlx,
			"images/wall.xpm", &i, &j);
	game->image.player = mlx_xpm_file_to_image(game->p_mlx,
			"images/player.xpm", &i, &j);
	game->image.exit = mlx_xpm_file_to_image(game->p_mlx,
			"images/exit.xpm", &i, &j);
	game->image.item = mlx_xpm_file_to_image(game->p_mlx,
			"images/item.xpm", &i, &j);
}

void	render_image(t_game *game, void *image, int width, int height)
{
	if (!game || !image)
		return ;
	mlx_put_image_to_window(game->p_mlx, game->p_window, image, width, height);
}


void	render_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map_row)
	{
		x = 0;
		while (x < game->map_column)
		{
			if (game->map[y][x] == '1')
				render_source(game, game->image.wall, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == '0')
				render_source(game, game->image.floor, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'P')
				render_source(game, game->image.player, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'E')
				render_source(game, game->image.exit, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'C')
				render_source(game, game->image.item, x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}
