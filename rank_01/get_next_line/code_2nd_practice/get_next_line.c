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
char	*build_single_line(int fd, char **stash);
int		get_next_newline_idx(char *s);

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
		res = ft_memcpy(res, s, len);
	else
		res =ft_memcpy(res, s, ft_strlen(s));
	res[len] = '\0';
	return (res);
}

char	*build_single_line(int fd, char **stash)
{
	int		bytes_read;
	char	*buff;
	char	*res;

	res = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buff);
		if (!bytes_read)
			return (*stash);
		return (NULL);
	}
	buff[BUFFER_SIZE] = '\0';
	res = ft_strjoin(*stash, buff);
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

char	*get_next_line(int fd)
{
	char			*res;
	static char		*stash = NULL;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	while (!stash || !get_next_newline_idx(stash))
	{
		res = build_single_line(fd, &stash);
		if (!res)
			return (NULL);
		if (get_next_newline_idx(res) || !stash)
			break ;
	}
	if (get_next_newline_idx(res))
	{
		res = extract_line(res);
		stash = update_stash(res);
	}
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
