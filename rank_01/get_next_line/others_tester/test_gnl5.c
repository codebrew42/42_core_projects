/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:05:03 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/06/19 17:38:23 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_gnl.h"

int	main(void)
{
	int	fd;
	char	*line;
	int	i;

	fd = open(FILE_NAME, O_RDONLY);
	i = 0;
	while (i++ < 2)
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
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	line = get_next_line(fd);
	if (!line)
		puts("null");
	close(fd);
	fd = open(FILE_NAME, O_RDONLY);
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
