/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_save_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:28:48 by jiepark           #+#    #+#             */
/*   Updated: 2025/05/04 16:28:49 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_ast			*save_an_arg_null(t_token **tokens, t_ast **cur, t_ast **root);
t_ast			*save_an_arg(t_token **tokens, t_ast **cur, t_ast **root);
t_ast			*save_args_hdc(t_token **tokens, t_ast **cur, t_ast **root);
t_ast			*save_args_redirs(t_token **tokens, t_ast **cur, t_ast **root);
t_ast			*save_args(t_token **tokens, t_ast **cur, t_ast **root);

t_ast	*save_an_arg_null(t_token **tokens, t_ast **cur, t_ast **root)
{
	t_ast	*node;

	node = create_ast_node((*tokens)->type);
	if (!node)
		return (NULL);
	node->args = NULL;
	save_to_position(root, cur, node);
	return (node);
}

t_ast	*save_an_arg(t_token **tokens, t_ast **cur, t_ast **root)
{
	t_ast	*node;
	char	*value;

	node = create_ast_node((*tokens)->type);
	if (!node)
		return (NULL);
	if (is_redirection_type((*tokens)->type) && (*tokens)->next
		&& (*tokens)->next->type == TYPE_TMP_WORD)
	{
		node->args = malloc(sizeof(char *) * 2);
		if (!node->args)
			return (free(node), NULL);
		value = ft_strdup((*tokens)->next->value);
		if (!value)
			return (free(node->args), free(node), NULL);
		node->args[0] = handle_redir_quotes(value);
		if (!node->args[0])
			return (free(node->args), free(node), NULL);
		node->args[1] = NULL;
		*tokens = (*tokens)->next;
	}
	save_to_position(root, cur, node);
	return (node);
}

t_ast	*save_args_cmd_and_hdc(t_token **tokens, t_ast **cur, t_ast **root)
{
	int		cmd_args_count;
	int		hdc_args_count;
	int		i;
	t_ast	*cmd_node;

	cmd_args_count = count_cmd_args_only(*tokens);
	hdc_args_count = count_hdc_args_only(*tokens);
	if (create_cmd_and_hdc_nodes(&cmd_node))
		return (NULL);
	if (save_hdc_args(cmd_node, *tokens, hdc_args_count))
		return (free_ast(cmd_node), NULL);
	if (save_cmd_args(cmd_node, *tokens, cmd_args_count))
		return (free_ast(cmd_node), NULL);
	i = -1;
	while (*tokens && ++i < cmd_args_count + hdc_args_count * 2 -1)
		*tokens = (*tokens)->next;
	i = -1;
	save_to_position(root, cur, cmd_node);
	while (*cur && ++i < hdc_args_count)
		*cur = (*cur)->right;
	return (cmd_node);
}

t_ast	*save_args_redirs(t_token **tokens, t_ast **cur, t_ast **root)
{
	t_ast	*cmd_node;
	t_ast	*next_node;
	t_token	*start;

	if (!tokens || !*tokens)
		return (NULL);
	start = *tokens;
	cmd_node = create_ast_node(TYPE_CMD);
	if (!cmd_node)
		return (NULL);
	save_to_position(root, cur, cmd_node);
	if (!save_args_skip_redir(tokens, cmd_node, start))
		return (free_ast(cmd_node), NULL);
	next_node = cmd_node;
	if (!process_redirections(start, &next_node))
		return (free_ast(cmd_node), NULL);
	return (next_node);
}

t_ast	*save_args(t_token **tokens, t_ast **cur, t_ast **root)
{
	t_ast	*node;
	int		i;

	if ((*tokens)->type == TYPE_REDIR_HDC)
	{
		if (!(*tokens)->next || (*tokens)->next->type != TYPE_TMP_WORD)
			return (err_syntax("near unexpected token `newline'\n", NULL), NULL);
		node = create_ast_node(TYPE_REDIR_HDC);
	}
	else
		node = create_ast_node(TYPE_CMD);
	if (!node)
		return (NULL);
	node->args = collect_cmd_args(tokens);
	if (!node->args)
		return (free_ast(node), NULL);
	i = -1;
	while (node->args[++i])
	{
		if (i == 0 && is_file_reader_cmd(node->args[i]) && node->args[i + 1]
			&& is_quoted_path(node->args[i + 1]))
			return (handle_cat_redir(node, cur, root));
	}
	save_to_position(root, cur, node);
	return (node);
}
