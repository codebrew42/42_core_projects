/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_handle_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:59:37 by jiepark           #+#    #+#             */
/*   Updated: 2025/04/08 18:59:38 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	is_quoted_path(char *str)
{
	if (!str)
		return (0);
	return (str[0] == '"' || str[0] == '\'');
}

int	is_file_reader_cmd(char *cmd)
{
	return (!ft_strncmp(cmd, "cat", 4));
}

int	is_double_quoted(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	return (len >= 2 && str[0] == '"' && str[len - 1] == '"');
}

int	has_embedded_redirs(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	if (!tmp || tmp->type != TYPE_TMP_WORD)
		return (0);
	while (tmp && tmp->type == TYPE_TMP_WORD)
		tmp = tmp->next;
	if (tmp && is_redirection_type(tmp->type) && tmp->type != TYPE_REDIR_HDC
		&& tmp->next && tmp->next->type == TYPE_TMP_WORD)
		return (1);
	return (0);
}
