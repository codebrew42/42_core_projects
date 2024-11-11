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
	if (init_pointers(game))
		return (1);
	print_t_game(game); //rm
	place_images_in_game(game);
	// Add MLX loop to keep window open
	mlx_loop(game->mlx_pointer);
	
	free_game(game);
	ft_printf("suc"); //rm
	return (0);
}

/*
int main()
{
	void    *mlx_connection;
	void	*mlx_window1;
	void	*mlx_window2;
	int		i;

	mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return (1);
	//create two windows
	mlx_window1 = mlx_new_window(mlx_connection, 500, 500, "window1");
	if (mlx_window1 == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	mlx_window2 = mlx_new_window(mlx_connection, 500, 500, "window2");
	if (mlx_window2 == NULL)
	{
		mlx_destroy_window(mlx_connection, mlx_window1);
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return (1);
	}
	//color
	i = 0;
	int j = 0;
	while (i++ < 100)
	{	
		while (j++ < 150)
			mlx_pixel_put(mlx_connection, mlx_window1, 100+i, 100+j, 0xff2500);
	}
	//to keep the proc alive
	mlx_loop(mlx_connection);
}
*/
