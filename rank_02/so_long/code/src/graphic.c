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

	game->image.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/floor.xpm", &i, &j);
	game->image.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/wall.xpm", &i, &j);
	game->image.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/player.xpm", &i, &j);
	game->image.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/exit.xpm", &i, &j);
	game->image.items = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/item.xpm", &i, &j);
}
//check dir: .../images?

void	render_map(t_game *game)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < game->map_row)
	{
		x = 0;
		while (x < game->map_column)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.wall, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.floor, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.player, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.exit, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->window_ptr,
					game->image.items, x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}
