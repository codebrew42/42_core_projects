/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:01:59 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/07 18:01:59 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	size_t	i;

	if (!game)
		return ;
	i = 0;
	while (i < game->map_max_row)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}


int	clean_exit(int fd, t_game *game_to_free, char *str_to_free, char *str)
{
	close(fd);
	if (game_to_free)
		free_game(game_to_free);
	if (str_to_free)
		free(str_to_free);
	ft_printf("Error: %s", str);
	return (1);
}

int	free_and_report_error(char *str_to_free, char *str)
{
	free(str_to_free);
	ft_printf("Error: %s", str);
	return (1);
}

int	report_error(char *str)
{
	ft_printf("Error: %s", str);
	return (1);
}

