#include "../includes/so_long.h"

void	print_t_game(t_game *game)
{
	if (!game)
		return ;

	ft_printf("\nCurrent Row: %d\t", game->map_row_idx);
	ft_printf("Max Rows: %d\t", game->map_row);
	ft_printf("Max Columns: %d\n", game->map_column);
	ft_printf("Collectives: %d\t", game->map_collectives);
	ft_printf("Players: %d\t", game->map_player);
	ft_printf("Exits: %d\t", game->map_exit);
}