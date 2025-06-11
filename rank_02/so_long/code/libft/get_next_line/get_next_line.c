/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024\06/26 18:45:26 by jiepark           #+#    #+#             */
/*   Updated: 2024\06/28 17:51:28 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char	*update_stash(char *stash)
{
	char	*dest;
	int		k;
	int		i;

	if (!stash)
		return (NULL);
	if (!stash[0])
		return (free(stash), NULL);
	k = 0;
	while (stash[k] != '\n' && stash[k])
		k++;
	if (stash[k] == '\0' || stash[k + 1] == '\0')
		return (free(stash), NULL);
	k++;
	dest = ft_calloc(ft_strlen(stash) - k + 1, 1);
	if (!dest)
		return (free(stash), NULL);
	i = 0;
	while (stash[k] != '\0')
		dest[i++] = stash[k++];
	dest[i] = '\0';
	return (free(stash), dest);
}

char	*extract_to_newline_or_eof(char *stash)
{
	int			i;
	int			j;
	char		*dest;

	if (!stash || *stash == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		dest = ft_calloc(i + 2, 1);
	else
		dest = ft_calloc(i + 1, 1);
	if (!dest)
		return (free(stash), NULL);
	j = 0;
	while (stash[j] && stash[j] != '\n')
	{
		dest[j] = stash[j];
		j++;
	}
	if (stash[j] == '\n')
		dest[j++] = '\n';
	dest[j] = '\0';
	return (dest);
}

char	*read_to_newline_or_eof(char *stash, int fd)
{
	int				bytes_read;
	char			*buff;

	if (!stash)
		stash = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buff)
		return (free(stash), NULL);
	while (ft_strchr(stash, '\n') == NULL || !stash)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			stash = NULL;
			return (free(buff), NULL);
		}
		if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		stash = ft_strjoin_free_param(stash, buff);
		if (!stash)
			return (free(buff), NULL);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	if (read(fd, NULL, 0) < 0)
	{
		if (stash != NULL)
			*stash = '\0';
		return (NULL);
	}
	stash = read_to_newline_or_eof(stash, fd);
	if (!stash)
		return (NULL);
	line = extract_to_newline_or_eof(stash);
	stash = update_stash(stash);
	return (line);
}
