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

char	*extract_line(char *s);
int		get_next_newline_idx(char *s);

/**
 * @brief	move pointer to the next position of the first newline, if it exists
 * 			or make pointer point to NULL, if it does not exist
 */
char	*update_stash(char *s)
{
	int		i;

	if (!s)
		return (NULL);
	i = get_next_newline_idx(s);
	if (!i)
		return (NULL);
	return (s + i + 1);
}

/**
 * @brief	copy untill the first newline symbol of the string, if it exists
 * 			or untill end of the string, if it doesn't exist
 */
char	*extract_line(char *s)
{
	int		len;
	char	*res;

	len = 0;
	if (!s)
		return (NULL);
	len = get_next_newline_idx(s);
	if (!len)
		len = ft_strlen(s);
	res = malloc(len + 1);
	if (len)
		len++;
	else
		len =  ft_strlen(s);
	res = ft_memcpy(res, s, len);
	res[len] = '\0';
	return (res);
}

int	get_next_newline_idx(char *s)
{
	int	len;

	len = 0;
	if (!*s)
		return (0);
	while (s[len])
	{
		if (s[len] == '\n')
			break ;
		len++;
	}
	return (len);
}
/**
 * @brief read a line untill it encounters EOF or /n from a file
 * @return 0 on error
 * @return 1 if it encounters end of file(EOF)
 */
int		read_to_stash(int fd, char **stash)
{
	int		bytes_read;
	char	*buff;
	char	*temp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buff);
			free(*stash);
			return (0);
		}
		if (bytes_read == 0)
		{
			free(buff);
			break ;
		}
		buff[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buff);
		free(buff);
		free(*stash);
		*stash = temp;
		if (!*stash)
			return (0);
		if (get_next_newline_idx(*stash))
			break ;
	}
	return (1);
}


char	*get_next_line(int fd)
{
	char			*res;
	static char		*stash = NULL;
	//int				flag;


	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	while (1)
	{
		// flag = read_to_stash(fd, &stash);
		// if (!flag)
		// {

		// }
		// if (flag || get_next_newline_idx(stash))
		// 	break ;
	}
	res = extract_line(res);
	stash = update_stash(stash);
	return (res);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i=1; //rm

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("\tfuncion call(%d): %s", i++, line); //rm
		free(line);
	}
	close(fd);
	return (0);
}
