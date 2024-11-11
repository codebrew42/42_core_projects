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

int	clean_exit_double(int fd, t_game *game, char **str, char *msg)
{
	char	**str_arr;
	int		i;

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
	if (msg)
		ft_printf("%s\n", msg);
	return (1);
}

int	clean_exit(int fd, t_game *game, char *str, char *msg)
{
	if (fd >= 0)
		close(fd);
	if (game)
		free_game(game);
	if (str)
		free(str);
	if (msg)
		ft_printf("%s\n", msg);
	return (1);
}

int	report_error(char *str)
{
	if (str)
		ft_printf("Error\n: %s\n", str);
	return (1);
}
