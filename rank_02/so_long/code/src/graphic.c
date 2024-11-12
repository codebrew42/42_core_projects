/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:55:02 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/12 18:55:02 by jiepark         ###   ########.fr        */
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

void	render_image(t_game *game, void *image, int x, int y)
{
	if (!game || !image)
		return ;
	mlx_put_image_to_window(game->p_mlx, game->p_window, image,
		x * PIXEL, y * PIXEL);
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
			render_image(game, game->image.floor, x, y);
			if (game->map[y][x] == '1')
				render_image(game, game->image.wall, x, y);
			else if (game->map[y][x] == 'E')
				render_image(game, game->image.exit, x, y);
			else if (game->map[y][x] == 'C')
				render_image(game, game->image.item, x, y);
			else
			{
				render_image(game, game->image.player,
					game->x_player_pos, game->y_player_pos);
			}
			x++;
		}
		y++;
	}
}
