/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:17:34 by jiepark           #+#    #+#             */
/*   Updated: 2024/05/15 11:24:53 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	count_words(const char *s, char c)
{
	int	in_word;
	int	len;

	in_word = 0;
	len = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			len++;
		}
		s++;
	}
	return (len);
}

static void	ft_free(char **s, int idx)
{
	while (idx >= 0)
		free(s[idx--]);
	free(s);
}

static char	**cp_words(char **dest, const char *s, char c)
{
	int	i;
	int	len;
	int	word_idx;

	i = 0;
	word_idx = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			dest[word_idx] = malloc(sizeof(char) * (len + 1));
			if (!dest[word_idx])
				return (ft_free(dest, word_idx), NULL);
			ft_memcpy(dest[word_idx], s + i, len);
			dest[word_idx++][len] = '\0';
			i += len;
		}
	}
	dest[word_idx] = NULL;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	int		nb_words;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	dest = malloc(sizeof(char *) * (nb_words + 1));
	if (!dest)
		return (NULL);
	if (!cp_words(dest, s, c))
		return (NULL);
	return (dest);
}
