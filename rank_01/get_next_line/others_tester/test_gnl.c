/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:09:25 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/06/15 11:54:38 by kyabuuch         ###   ########.fr       */
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
			//puts("null");
			break;
		}
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
