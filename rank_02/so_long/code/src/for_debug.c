/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:39:59 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/10 21:39:59 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h> 

void	print_path_data(t_path *path)
{
	printf("\nprintf path data\n");
	printf("x_prev, y_prev: %zu, %zu\n", path->x_prev, path->y_prev);
	printf("it_found, exit_found: %zu, %zu\n", path->items_found, path->exit_found);

}

void	print_game_map(t_game *game)
{
	   for (size_t row = 0; row < game->map_row; row++) {
       for (size_t col = 0; col < game->map_column; col++) {
           printf("p[%zu,%zu]%c \n", row, col, game->map[row][col]);
       }
   }
}

void	print_int_map(int **map, t_game *game)
{
	int	i;
	int j;
	int	rows = game->map_row;
	int	cols = game->map_column;


	i = 0;
	ft_printf("\npath finding map\n");
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] >= 0)
				printf("+%d ", map[i][j]);
				//printf("(%d,%d)+%d ", i, j, map[i][j]);
			else
				printf("%d ", map[i][j]);
				//printf("(%d,%d)%d ", i, j, map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_printf("\nFinished printing map\n");
}


void	print_map(t_game *game)
{
	int	i;

	if (!game || !game->map_mem_allocated)
		return ;
	i = 0;
	ft_printf("\n");
	while (game->map[i])
	{
		ft_printf("(adr: %p)%s", (void *)game->map[i], game->map[i]);
		i++;
	}
}



void	print_t_game(t_game *game)
{
	if (!game)
		return ;

	ft_printf("\nCurrent Row: %d\t", game->map_row_idx);
	ft_printf("Max Rows: %d\t", game->map_row);
	ft_printf("Max Columns: %d\n", game->map_column);
	ft_printf("items: %d\t", game->map_items);
	ft_printf("Players: %d\t", game->map_player);
	ft_printf("Exits: %d\t", game->map_exit);
	ft_printf("Maps: ");
	print_map(game);
	ft_printf("Player Pos: %d, %d", game->x_player_pos, game->y_player_pos);
}