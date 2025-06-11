/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:39:53 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/10 21:39:53 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'P'
		|| c == 'E' || c == 'C' || c == '\n');
}

int	free_path_and_clean_exit(t_path *path, t_game *game, char *msg)
{
	free_path(path, game->map_row);
	clean_exit(-1, game, NULL, msg);
	return (1);
}

int	clean_exit_double(int fd, t_game *game, char **str, char *msg)
{
	char	**str_arr;
	int		i;

	if (msg)
		ft_printf("%s\n", msg);
	if (fd >= 0)
		close(fd);
	if (game)
		free_game(game);
	if (str)
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
	return (1);
}

int	clean_exit(int fd, t_game *game, char *str, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (fd >= 0)
		close(fd);
	if (game)
		free_game(game);
	if (str)
		free(str);
	exit(0);
	return (1);
}

int	report_error(char *str)
{
	if (str)
		ft_printf("Error\n: %s\n", str);
	return (1);
}
