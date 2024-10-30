/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:13:37 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/06/17 21:46:52 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_gnl.h"

int	main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	char	*line;

	fd1 = open("test/test4.txt", O_RDONLY);
	fd2 = open("test/test5.txt", O_RDONLY);
	fd3 = open("test/test6.txt", O_RDONLY);
	int i = 0;
	while (i++ < 7)
	{
		line = get_next_line(fd1);
		if (!line)
			puts("null");
		else
			printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		if (!line)
			puts("null");
		else
			printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		if (!line)
			puts("null");
		else
			printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
