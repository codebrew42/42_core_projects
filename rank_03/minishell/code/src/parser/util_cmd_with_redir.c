/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_cmd_with_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:59:37 by jiepark           #+#    #+#             */
/*   Updated: 2025/03/17 18:59:38 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minishell.h"
#include "../include/parser.h"

int		save_args_skip_redir(t_token **tokens, t_ast *cmd_node, t_token *start);
int		count_actual_args(t_token *start);
int		process_redirections(t_token *start, t_ast **last_node);
char	*handle_redir_quotes(char *value);
t_ast	*create_redir_node(t_token *redir, t_token *target, t_ast **last_node);

int	save_args_skip_redir(t_token **tokens, t_ast *cmd_node, t_token *start)
{
	t_token	*tmp;
	int		i;

	cmd_node->args = ft_calloc(count_actual_args(start) + 1, sizeof(char *));
	if (!cmd_node->args)
		return (0);
	i = 0;
	tmp = start;
	if (!collect_arg(&tmp, cmd_node, start, &i))
		return (free_strarr(cmd_node->args), cmd_node->args = NULL, 0);
	tmp = start;
	while (tmp && tmp->next && is_not_op_or_paren(tmp->next->type))
		tmp = tmp->next;
	*tokens = tmp;
	return (1);
}

int	count_actual_args(t_token *start)
{
	t_token	*tmp;
	int		count;

	count = 0;
	tmp = start;
	while (tmp && !is_op_type(tmp->type) && !is_paren_type(tmp->type))
	{
		if (tmp->type == TYPE_TMP_WORD
			&& (tmp == start || !is_redirection_type(tmp->prev->type)))
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	process_redirections(t_token *start, t_ast **last_node)
{
	t_token	*tmp;
	t_ast	*redir_node;

	tmp = start;
	while (tmp && !is_op_type(tmp->type) && !is_paren_type(tmp->type))
	{
		if (is_redirection_type(tmp->type) && tmp->next
			&& tmp->next->type == TYPE_TMP_WORD)
		{
			redir_node = create_redir_node(tmp, tmp->next, last_node);
			if (!redir_node)
				return (0);
			*last_node = redir_node;
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

char	*handle_redir_quotes(char *value)
{
	char	*stripped;

	if (!value)
		return (NULL);
	stripped = preserve_quotes_content(value);
	free(value);
	return (stripped);
}

t_ast	*create_redir_node(t_token *redir, t_token *target, t_ast **last_node)
{
	t_ast	*node;
	char	*value;
	char	*processed_value;

	node = create_ast_node(redir->type);
	if (!node)
		return (NULL);
	node->args = malloc(sizeof(char *) * 2);
	if (!node->args)
		return (free(node), NULL);
	value = ft_strdup(target->value);
	if (!value)
	{
		free(node->args);
		return (free(node), NULL);
	}
	processed_value = handle_redir_quotes(value);
	if (!processed_value)
	{
		free(node->args);
		return (free(node), NULL);
	}
	node->args[0] = processed_value;
	node->args[1] = NULL;
	return ((*last_node)->right = node, node);
}
