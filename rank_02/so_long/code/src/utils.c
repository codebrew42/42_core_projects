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
	if (!game)
		return ;
	game->map_row_idx = 0;
	while (game->map_mem_allocated && game->map_row_idx < game->map_row)
	{
		free(game->map[game->map_row_idx]);
		game->map_row_idx++;
	}
	free(game->map);
	free(game);
}


int	clean_exit(int fd, t_game *game, int double_arr, char **str, char *msg)
{
	char	**str_arr;
	int		i;

	if (fd >= 0)
		close(fd);
	if (game)
		free_game(game);
	if (str)
	{
		if (double_arr)
		{
			str_arr = (char **)str;
			i = 0;
			while (str_arr[i])
			{
				free(str_arr[i]);
				i++;
			}
			free(str_arr);
		}
		else
			free(str);
	}
	ft_printf("Error: %s", msg);
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

