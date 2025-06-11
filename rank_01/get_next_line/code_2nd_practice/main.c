/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:29:57 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/19 16:29:57 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY); //(!)
	if (fd < 0)
		return (1);
	// if (read(fd, NULL, 0) < 0) // necessary?
	// {
	// 	return (1);
	// }
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
	}
	close(fd); //(!)
	return (0);
}