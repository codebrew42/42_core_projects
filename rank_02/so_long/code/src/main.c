/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:40:13 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/10 21:40:13 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_close(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}

/**
 * @note (found one issue for eval) of MLX function
 */
int	main(int ac, const char **av)
{
	t_game	*game;

	if (ac != 2)
		return (report_error("Usage: ./so_long map.ber"));
	if (init_game(&game) || is_valid_map(game, av[1]) || read_map(game, av[1]))
		return (1);
	if (init_pointers(game)) //here: put has_valid_map(game);
		return (1);
	place_images_in_game(game);
	render_map(game);
	mlx_key_hook(game->p_window, key_control, game);
	mlx_hook(game->p_window, CLOSE_BUTTON, 0, handle_close, game);
	mlx_loop(game->p_mlx);
	free_game(game);
	return (0);
}
