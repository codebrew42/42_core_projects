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

#include "includes/get_next_line.h"

char	*update_stash(char *stash)
{
	char	*res;

	if (!stash)
		return (NULL);
	res = ft_strchr(stash, '\n');
	if (*res == '\n')
		res++;
	return (res);
}

/**
 * @brief	(Always) Allocates memory for the string to return, extracts line from the src up until '\\n' or '\0'.
 * 
 * If '\\n' doesn't exist in 'src', it mallocs and copies "src" as a whole and returns it.
 * Otherwise, it copies src until '\\n' and returns that.
 * 
 * @return	A string(If successful)
 * @return	NULL(else: leer src, ...)
 * @note	The returning value will be freed in the main().
 */
char	*extract_line(char *src)
{
	char	*end_of_line;
	char	*dest;
	char	*temp_src;
	int		len;

	if (!src)
		return (NULL);
	end_of_line = ft_strchr(src, '\n');
	if(!end_of_line)
		len = ft_strlen(src);
	else
	{
		temp_src = src;
		len = 0;
		while (*temp_src++ != *end_of_line) //to check
			len++;
	}
	printf("extracted line: len(%d)", len); //rm
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	dest = ft_memcpy(dest, src, len);
	dest[len] = '\0';
	return (dest);
}

/**
 * @pre BUFFER_SIZE must be defined in the header to specify the max-number of 
 * bytes to read at once.
 * 		static char *stash should be defined in the function
 * @param fd obtained from the open() function, which is used to read from
 *  the file.
 * @brief	(If 'static char *stash' is leer) Allocates memory for a buffer(stash) to 
 * hold the data, Reads a line up to BUFFER_SIZE bytes from a file through the given "fd"
 * 
 * (Always) Extracts a line that ends with either '\\n' or '\0', 
 * Updates stash for the next call
 * @return (if successful) A pointer to the extracted line (else) NULL (e.g., invalid fd, memory allocation failure, or end of file).
 */
char	*get_next_line(int fd)
{
	char			*line;
	int				bytes_read;
	static char		*stash;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!stash)
	{
		stash = malloc(BUFFER_SIZE + 1);
		if (!stash)
			return (NULL);
		bytes_read = read(fd, stash, BUFFER_SIZE);
		stash[BUFFER_SIZE] = '\0';
		if (bytes_read <= 0)
		{
			free(stash);
			return (NULL);
		}
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}

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
	int i = 0; //rm
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("\tof funcion call(%d): %s\n", i++, line); //rm
		free(line);
	}
	close(fd); //(!)
	return (0);
}