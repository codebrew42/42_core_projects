/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:03:01 by jiepark           #+#    #+#             */
/*   Updated: 2025/03/17 19:03:02 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	find_full_word_end(char *input, int start);
int			handle_word(t_mshell *ms, char *input, int *i);

static int	find_full_word_end(char *input, int start)
{
	int		i;
	char	quote_char;

	i = start;
	while (input[i] && ft_isspace(input[i]))
		i++;
	while (input[i] && !ft_isspace(input[i]) && !ft_strchr("|<>&()", input[i]))
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote_char = input[i];
			i++;
			while (input[i] && input[i] != quote_char)
				i++;
			if (input[i] == quote_char)
				i++;
		}
		else
			i++;
	}
	return (i);
}

int	handle_word(t_mshell *ms, char *input, int *i)
{
	int		start;
	int		end;
	char	*value;

	start = *i;
	end = find_full_word_end(input, start);
	if (end <= start)
		return (0);
	value = ft_substr(input, start, end - start);
	if (!value)
		return (-1);
	if (add_token(ms, TYPE_TMP_WORD, value) < 0)
	{
		free(value);
		return (-1);
	}
	free(value);
	*i = end - 1;
	return (0);
}
