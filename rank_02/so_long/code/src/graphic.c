#include "../includes/so_long.h"

void	place_images_in_game(t_game *game)
{
	int	i;
	int	j;

	game->image.floor = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/floor.xpm", &i, &j);
	game->image.wall = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/wall.xpm", &i, &j);
	game->image.player = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/player.xpm", &i, &j);
	game->image.exit = mlx_xpm_file_to_image(game->mlx_pointer,
			"images/exit.xpm", &i, &j);
	game->image.collectives = mlx_xpm_file_to_image(game->mlx_pointer,
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
			// Determine which image to place based on map cell type
			if (game->map[y][x] == '1') // Assuming '1' represents walls
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->image.wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == '0') // Assuming '0' represents floor
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->image.floor, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'P') // Assuming 'P' represents the player
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->image.player, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E') // Assuming 'E' represents the exit
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->image.exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C') // Assuming 'C' represents collectibles
				mlx_put_image_to_window(game->mlx_pointer, game->window_pointer, game->image.collectives, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
