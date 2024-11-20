/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:52:36 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/11 15:52:36 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @note after moving, render_map() for each func call here
 */
int	move_player_to(t_game *game, int dest_x, int dest_y)
{
	char	dest;

	dest = game->map[dest_y][dest_x];
	if (dest == '1')
		return (5);
	else if (dest == 'E')
	{
		if (game->map_items)
			return (5);
		ft_printf("\nTotal steps: %u\n", game->steps + 1);
		return (clean_exit(-1, game, NULL, CONGRATULATIONS_MSG));
	}
	else if (dest == '0' || dest == 'C')
	{
		game->map[game->y_player_pos][game->x_player_pos] = '0';
		if (dest == 'C')
			game->map_items--;
		game->map[dest_y][dest_x] = 'P';
		game->x_player_pos = dest_x;
		game->y_player_pos = dest_y;
		game->steps++;
		render_map(game);
	}
	return (0);
}

int	handle_movement_input(t_game *game, unsigned int direction)
{
	unsigned int	i;

	if (direction == UP)
		i = move_player_to(game, game->x_player_pos, game->y_player_pos - 1);
	else if (direction == DOWN)
		i = move_player_to(game, game->x_player_pos, game->y_player_pos + 1);
	else if (direction == LEFT)
		i = move_player_to(game, game->x_player_pos - 1, game->y_player_pos);
	else if (direction == RIGHT)
		i = move_player_to(game, game->x_player_pos + 1, game->y_player_pos);
	if (i)
		return (1);
	if (i != CANT_MOVE)
	{
		printf("Steps Taken: %d\n", game->steps);
		printf("Remaining items: %ld\n", game->map_items);
	}
	return (0);
}

int	key_control(unsigned int command, t_game *game)
{
	if (command == KEY_ESC)
		return (clean_exit(-1, game, NULL, NULL));
	if (command == KEY_W || command == KEY_UP)
		handle_movement_input(game, UP);
	if (command == KEY_S || command == KEY_DOWN)
		handle_movement_input(game, DOWN);
	if (command == KEY_A || command == KEY_LEFT)
		handle_movement_input(game, LEFT);
	if (command == KEY_D || command == KEY_RIGHT)
		handle_movement_input(game, RIGHT);
	return (1);
}
