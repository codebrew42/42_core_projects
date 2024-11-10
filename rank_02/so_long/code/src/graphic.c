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