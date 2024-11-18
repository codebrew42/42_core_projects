/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:46:34 by jiepark          #+#    #+#              */
/*   Updated: 2024/11/18 20:46:34 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{

	
}

char	*get_next_line(int fd)
{
	char		*line;
	int			bytes_read;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
	{
		errno = EINVAL; //rm: when including <erron.h> setting errno seems unnecessary
		return (-1);
	}
	bytes_read = read(fd, stash, BUFFER_SIZE);
	if (!bytes_read)
		return (0);
	line = extract_line(stash);
	return (stash);
}