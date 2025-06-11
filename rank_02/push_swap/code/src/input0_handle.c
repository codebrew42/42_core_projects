/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input0_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:01:07 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/17 19:01:08 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	free_double_arr_on_freeflag(char **str, int free_flag)
{
	char	**temp;

	if (!str || !free_flag)
		return ;
	temp = str;
	while (*temp)
	{
		free(*temp);
		*temp = NULL;
		temp++;
	}
	free(str);
	str = NULL;
}

char	*copy_token(const char *start, int len)
{
	char	*dest;

	if (!start)
		return (NULL);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, start, len);
	dest[len] = '\0';
	return (dest);
}

size_t	count_words(const char *str, char delimiter)
{
	int		res;
	int		word_starts;

	res = 0;
	word_starts = 1;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != delimiter && word_starts)
		{
			res++;
			word_starts = 0;
		}
		else if (*str == delimiter)
			word_starts = 1;
		str++;
	}
	return (res);
}

const char	*get_token_and_len(const char *str, char c, size_t *len)
{
	*len = 0;
	if (*str && *str == c)
		str++;
	while (str[*len] && str[*len] != c)
		(*len)++;
	return (str);
}

char	**tokenize(const char *str, char delimiter)
{
	char		**dest;
	const char	*token_start;
	size_t		token_len;
	size_t		words_nbr;
	size_t		i;

	words_nbr = count_words(str, delimiter);
	dest = malloc(sizeof(char *) * (words_nbr + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < words_nbr)
	{
		token_start = get_token_and_len(str, delimiter, &token_len);
		dest[i] = copy_token(token_start, token_len);
		if (!dest[i])
		{
			free_double_arr_on_freeflag(dest, 1);
			return (NULL);
		}
		i++;
		str = token_start + token_len;
	}
	dest[i] = NULL;
	return (dest);
}
