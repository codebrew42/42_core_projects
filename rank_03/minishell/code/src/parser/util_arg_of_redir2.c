/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_arg_of_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:59:37 by jiepark           #+#    #+#             */
/*   Updated: 2025/04/08 18:59:38 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	append_redir_segment(t_list **list, char *content);
char	*join_redir_segments(t_list *list);
void	process_redir_segment(char *str, int *i, t_list **segments);

void	append_redir_segment(t_list **list, char *content)
{
	char	*copy;
	t_list	*new_node;

	if (!content)
		return ;
	copy = ft_strdup(content);
	if (!copy)
		err_exit(ERR_MSG_MEM, GENERAL_ERROR);
	new_node = ft_lstnew(copy);
	if (!new_node)
	{
		free(copy);
		err_exit(ERR_MSG_MEM, GENERAL_ERROR);
	}
	ft_lstadd_back(list, new_node);
}

char	*join_redir_segments(t_list *list)
{
	int		total_len;
	char	*final_str;
	t_list	*current;

	total_len = 0;
	current = list;
	while (current)
	{
		total_len += ft_strlen((char *)current->content);
		current = current->next;
	}
	final_str = ft_calloc(total_len + 1, sizeof(char));
	if (!final_str)
		err_exit(ERR_MSG_MEM, GENERAL_ERROR);
	current = list;
	while (current)
	{
		ft_strlcat(final_str, (char *)current->content, total_len + 1);
		current = current->next;
	}
	return (final_str);
}

static void	handle_quoted_redir_segment(char *str, int *i, t_list **segments)
{
	int		start;
	int		len;
	char	*segment_content;
	char	quote_char;

	len = ft_strlen(str);
	quote_char = str[*i];
	(*i)++;
	start = *i;
	while (*i < len && str[*i] != quote_char)
		(*i)++;
	segment_content = ft_substr(str, start, *i - start);
	append_redir_segment(segments, segment_content);
	free(segment_content);
	if (*i < len && str[*i] == quote_char)
		(*i)++;
}

static void	handle_unquoted_redir_segment(char *str, int *i, t_list **segments)
{
	int		start;
	int		len;
	char	*segment_content;

	len = ft_strlen(str);
	start = *i;
	while (*i < len && str[*i] != '\'' && str[*i] != '"')
		(*i)++;
	segment_content = ft_substr(str, start, *i - start);
	append_redir_segment(segments, segment_content);
	free(segment_content);
}

void	process_redir_segment(char *str, int *i, t_list **segments)
{
	if (str[*i] == '\'' || str[*i] == '"')
	{
		handle_quoted_redir_segment(str, i, segments);
	}
	else
	{
		handle_unquoted_redir_segment(str, i, segments);
	}
}
