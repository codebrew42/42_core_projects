/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_save_to_ast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:59:44 by jiepark           #+#    #+#             */
/*   Updated: 2025/03/17 18:59:45 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		save_to_position(t_ast **root, t_ast **current, t_ast *node);
t_ast		*create_ast_node(t_type type);
static int	count_cmd_args(t_token *tokens);
char		*process_token_value(t_token **tokens);
char		**collect_cmd_args(t_token **tokens);

void	save_to_position(t_ast **root, t_ast **current, t_ast *node)
{
	if (!(*root))
	{
		*root = node;
		(*root)->left = NULL;
	}
	else if (*current)
	{
		while (*current && (*current)->right)
			*current = (*current)->right;
		node->left = *current;
		(*current)->right = node;
	}
}

t_ast	*create_ast_node(t_type type)
{
	t_ast	*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (!node)
		return (NULL);
	node->type = type;
	node->args = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static int	count_cmd_args(t_token *tokens)
{
	int		arg_count;
	t_token	*tmp;

	arg_count = 0;
	tmp = tokens;
	if (tmp && tmp->type == TYPE_REDIR_HDC)
		tmp = tmp->next;
	while (tmp && (tmp->type == TYPE_TMP_WORD))
	{
		arg_count++;
		tmp = tmp->next;
	}
	return (arg_count);
}

char	*process_token_value(t_token **tokens)
{
	char	*processed;
	char	*temp;

	processed = ft_strdup((*tokens)->value);
	if (!processed)
		return (NULL);
	if ((*tokens)->next && (*tokens)->next->type == TYPE_ENV_VAR)
	{
		temp = ft_strjoin(processed, (*tokens)->next->value);
		free(processed);
		processed = temp;
		*tokens = (*tokens)->next;
	}
	return (processed);
}

char	**collect_cmd_args(t_token **tokens)
{
	char	**args;
	int		arg_count;
	int		i;
	char	*processed;

	arg_count = count_cmd_args(*tokens);
	args = ft_calloc(arg_count + 1, sizeof(char *));
	if (!args)
		return (NULL);
	if ((*tokens)->type == TYPE_REDIR_HDC)
		*tokens = (*tokens)->next;
	i = -1;
	while (++i < arg_count && *tokens && (*tokens)->type == TYPE_TMP_WORD)
	{
		processed = process_token_value(tokens);
		if (!processed)
			return (free_strarr(args), NULL);
		args[i] = processed;
		if (!args[i])
			return (free_strarr(args), NULL);
		if (i < arg_count - 1)
			*tokens = (*tokens)->next;
	}
	args[i] = NULL;
	return (args);
}
