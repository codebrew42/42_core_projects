/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:49:43 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/06/18 19:08:59 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_gnl.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			puts("null");
			break;
		}
		printf("%s", line);
		free(line);
	}
	close(fd);
	line = NULL;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			puts("null");
			break;
		}
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
