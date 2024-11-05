/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:48:13 by jiepark           #+#    #+#             */
/*   Updated: 2024/06/26 18:48:14 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_free_param(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;
	size_t	i;

	if (count > (SIZE_MAX / size))
		return (NULL);
	dest = malloc(count * size);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < count * size)
		dest[i++] = 0;
	return (dest);
}

char	*ft_strndup(char *src, int nbr)
{
	char	*dest;
	int		i;

	dest = malloc((nbr + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < nbr && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
