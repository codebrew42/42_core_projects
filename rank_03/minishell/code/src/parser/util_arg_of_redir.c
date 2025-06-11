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

int		collect_arg(t_token **tmp, t_ast *cmd_node, t_token *start, int *i);
char	*strip_quotes(char *str);
t_ast	*handle_cat_redir(t_ast *node, t_ast **cur, t_ast **root);
char	*preserve_quotes_content(char *str);
int		needs_processing(const char *arg);

int	collect_arg(t_token **tmp, t_ast *cmd_node, t_token *start, int *i)
{
	char	*value;
	char	*processed_val;

	while (*tmp && is_not_op_or_paren((*tmp)->type))
	{
		if ((*tmp)->type == TYPE_TMP_WORD
			&& (*tmp == start || !is_redirection_type((*tmp)->prev->type)))
		{
			value = ft_strdup((*tmp)->value);
			if (!value)
				return (0);
			processed_val = handle_redir_quotes(value);
			cmd_node->args[(*i)++] = processed_val;
			if (!processed_val)
				return (0);
		}
		*tmp = (*tmp)->next;
	}
	return (1);
}

char	*strip_quotes(char *str)
{
	int		i;
	int		j;
	char	*result;
	char	quote;

	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && !quote)
			quote = str[i++];
		else if (str[i] == quote)
		{
			quote = 0;
			i++;
		}
		else
			result[j++] = str[i++];
	}
	result[j] = '\0';
	return (result);
}

t_ast	*handle_cat_redir(t_ast *node, t_ast **cur, t_ast **root)
{
	t_ast	*redir_node;
	char	*stripped;

	if (node->args[1])
		stripped = strip_quotes(node->args[1]);
	else
		stripped = NULL;
	if (!stripped)
		return (free_ast(node), NULL);
	free(node->args[1]);
	node->args[1] = NULL;
	redir_node = create_ast_node(TYPE_REDIR_IN);
	if (!redir_node)
		return (free(stripped), free_ast(node), NULL);
	redir_node->args = malloc(sizeof(char *) * 2);
	if (!redir_node->args)
		return (free(stripped), free_ast(node), free(redir_node), NULL);
	redir_node->args[0] = stripped;
	redir_node->args[1] = NULL;
	save_to_position(root, cur, node);
	redir_node->left = node;
	node->right = redir_node;
	return (redir_node);
}

char	*preserve_quotes_content(char *str)
{
	int		i;
	int		len;
	t_list	*segments;
	char	*final_result;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len == 0 || !needs_processing(str))
		return (ft_strdup(str));
	i = 0;
	segments = NULL;
	while (i < len)
	{
		process_redir_segment(str, &i, &segments);
	}
	final_result = join_redir_segments(segments);
	ft_lstclear(&segments, free);
	return (final_result);
}

int	needs_processing(const char *arg)
{
	int	i;

	if (!arg)
		return (0);
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\'' || arg[i] == '"' || arg[i] == '$')
			return (1);
		i++;
	}
	return (0);
}
