/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:40:57 by kyabuuch          #+#    #+#             */
/*   Updated: 2024/06/18 21:16:45 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_gnl.h"

int	main(void)
{
	int	fd1;
	int	fd2;
	char	*line;

	fd1 = open("test/read_error.txt", O_RDONLY);
	fd2 = open("test/lines_around_10.txt", O_RDONLY);
	ft_call_print_gnl(fd1);
	ft_call_print_gnl(fd2);
	ft_call_print_gnl(fd1);
	ft_call_print_gnl(fd2);
	line = "";
	while (line)
	{
		line = get_next_line(fd1);
		free(line);
	}
	ft_call_print_gnl(fd1);
	close(fd1);
	ft_call_print_gnl(fd2);
	fd1 = open("test/read_error.txt", O_RDONLY);
	ft_call_print_gnl(fd1);
	ft_call_print_gnl(fd2);
	ft_call_print_gnl(fd1);
	ft_call_print_gnl(fd1);
	ft_call_print_gnl(fd2);
	ft_call_print_gnl(fd2);
	ft_call_print_gnl(fd1);
	ft_call_print_gnl(fd1);
	close(fd1);
	close(fd2);
	return (0);
}

void	ft_call_print_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		puts("null");
	else
		printf("%s", line);
	free(line);
}
