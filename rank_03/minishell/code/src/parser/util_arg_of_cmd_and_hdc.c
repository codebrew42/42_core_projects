/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_arg_of_cmd_and_hdc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:27:34 by jiepark           #+#    #+#             */
/*   Updated: 2025/05/04 16:27:35 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_cmd_args_only(t_token *start);
int		create_cmd_and_hdc_nodes(t_ast **cmd_node);
int		save_hdc_args(t_ast *cmd_node, t_token *tokens, int count);
int		is_hdc_or_tmp_word(t_token *token);
int		save_cmd_args(t_ast *cmd_node, t_token *tokens, int cmd_args_count);

int	count_cmd_args_only(t_token *start)
{
	int		cmd_args_count;
	t_token	*tmp;

	cmd_args_count = 0;
	tmp = start;
	while (tmp && (tmp->type == TYPE_TMP_WORD || tmp->type == TYPE_REDIR_HDC))
	{
		if (tmp->type == TYPE_TMP_WORD)
		{
			tmp = tmp->next;
			cmd_args_count++;
		}
		if (tmp && tmp->type == TYPE_REDIR_HDC)
			tmp = tmp->next->next;
	}
	return (cmd_args_count);
}

int	create_cmd_and_hdc_nodes(t_ast **cmd_node)
{
	*cmd_node = create_ast_node(TYPE_CMD);
	if (!*cmd_node)
		return (1);
	(*cmd_node)->right = create_ast_node(TYPE_REDIR_HDC);
	if (!(*cmd_node)->right)
		return (free_ast(*cmd_node), 1);
	return (0);
}

int	save_hdc_args(t_ast *cmd_node, t_token *tokens, int count)
{
	int		i;

	cmd_node->right->args = ft_calloc(count + 1, sizeof(char *));
	if (!cmd_node->right->args)
		return (1);
	i = 0;
	while (tokens && is_hdc_or_tmp_word(tokens) && i < count)
	{
		if (tokens->type == TYPE_REDIR_HDC)
		{
			cmd_node->right->args[i] = ft_strdup(tokens->next->value);
			if (!cmd_node->right->args[i])
				return (free_strarr(cmd_node->right->args), 1);
			tokens = tokens->next->next;
			i++;
		}
		if (tokens && tokens->type == TYPE_TMP_WORD)
			tokens = tokens->next;
	}
	cmd_node->right->args[i] = NULL;
	return (0);
}

int	is_hdc_or_tmp_word(t_token *token)
{
	if (!token)
		return (0);
	return (token->type == TYPE_REDIR_HDC || token->type == TYPE_TMP_WORD);
}

int	save_cmd_args(t_ast *cmd_node, t_token *tokens, int cmd_args_count)
{
	char	**cmd_args;
	char	*processed;
	int		i;

	cmd_args = ft_calloc(cmd_args_count + 1, sizeof(char *));
	if (!cmd_args)
		return (1);
	i = 0;
	while (tokens && is_hdc_or_tmp_word(tokens) && i < cmd_args_count)
	{
		if (tokens->type == TYPE_REDIR_HDC)
			tokens = tokens->next->next;
		if (tokens && tokens->type == TYPE_TMP_WORD)
		{
			processed = process_token_value(&tokens);
			if (!processed)
				return (free_strarr(cmd_args), 1);
			cmd_args[i++] = processed;
			if (i != cmd_args_count)
				tokens = tokens->next;
		}
	}
	cmd_args[i] = NULL;
	cmd_node->args = cmd_args;
	return (0);
}
