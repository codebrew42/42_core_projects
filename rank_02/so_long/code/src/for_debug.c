#include "../includes/so_long.h"

void	print_t_game(t_game *game)
{
	if (!game)
		return ;

	ft_printf("\nCurrent Row: %d\n\n", game->map_row_idx);
	ft_printf("Max Rows: %d\n\n", game->map_row);
	ft_printf("Max Columns: %d\n\n", game->map_column);
	ft_printf("Collectives: %d\n\n", game->map_collectives);
	ft_printf("Players: %d\n\n", game->map_player);
	ft_printf("Exits: %d\n\n", game->map_exit);
}