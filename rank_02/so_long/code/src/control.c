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

int	move_player_up_or_down(t_game *game, int movement)
{

}

int	move_player_left_or_right(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_player_position;
	j = game->y_player_position;
	if (movement == 0)
	{
		//check goal/zielgebiet
		//if ok
			//mv player
				//if suc -> mv wall
	}
	else if (movement == 2)
	{

	}
	printf("Steps Taken: %i\n", game->steps);
	printf("Remaining items: %i\n", game->map_items);
	return (1);
}


int	key_control(int	command, t_game *game)
{
	if (command == KEY_ESC)
		
	if (command == KEY_W || command == KEY_UP)

	if (command == KEY_S || command == KEY_DOWN)

	if (command == KEY_A || command == KEY_LEFT)

	if (command == KEY_D || command == KEY_RIGHT)

	return (1);
}