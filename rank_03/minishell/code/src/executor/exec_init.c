/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:47:55 by                   #+#    #+#             */
/*   Updated: 2025/05/04 16:41:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

static int	set_cmddata(t_ast *ast, t_cmd *cmds, t_heredoc *hdc);
static int	parse_ast(t_ast *ast, t_cmd **cmds, t_heredoc **hdc);
static int	set_rdct_type(t_ast *ast, t_cmd *cmd, t_type type, t_heredoc **hdc);
static int	add_rdct_lst(t_ast *ast, t_cmd *cmd, t_type type, t_heredoc *hdc);

int	init_executor(t_mshell *data, t_cmd **cmds, int **pids)
{
	int		n_cmd;
	t_cmd	*tmp;

	n_cmd = count_cmd(data->ast_root);
	if (!n_cmd)
		return (-2);
	if (n_cmd == ERR)
		return (ERR);
	*pids = ft_calloc(n_cmd + 1, sizeof(int));
	*cmds = ft_calloc(1, sizeof(t_cmd));
	if (!*cmds)
		return (ERR);
	tmp = *cmds;
	while (--n_cmd)
	{
		tmp->next = ft_calloc(1, sizeof(t_cmd));
		if (!tmp->next)
			return (free_cmddata(*cmds), ERR);
		tmp = tmp->next;
	}
	if (set_cmddata(data->ast_root, *cmds, data->hdc))
		return (ERR);
	if ((*cmds)->bi && !(*cmds)->next)
		(*cmds)->bi_only = 1;
	return (count_cmd(data->ast_root));
}

static int	set_cmddata(t_ast *ast, t_cmd *cmds, t_heredoc *hdc)
{
	while (ast)
	{
		if (parse_ast(ast, &cmds, &hdc))
			return (ERR);
		ast = ast->right;
	}
	return (0);
}

static int	parse_ast(t_ast *ast, t_cmd **cmds, t_heredoc **hdc)
{
	if (ast->type == TYPE_CMD)
	{
		if ((*cmds)->args)
			(*cmds) = (*cmds)->next;
		(*cmds)->args = ast->args;
		(*cmds)->bi = isbuiltin((*cmds)->args[0]);
	}
	else if (ast->type == TYPE_PAREN_OPEN)
		(*cmds)->paren[0]++;
	else if (ast->type == TYPE_PAREN_CLOSE)
		(*cmds)->paren[1]++;
	else if (ast->type == TYPE_PIPE)
	{
		(*cmds)->op = OP_PIPE;
		(*cmds) = (*cmds)->next;
	}
	else if (ast->type == TYPE_OR || ast->type == TYPE_AND)
	{
		(*cmds) = (*cmds)->next;
		(*cmds)->op = ast->type - TYPE_OR + 2;
	}
	else if (set_rdct_type(ast, *cmds, ast->type, hdc))
		return (ERR);
	return (0);
}

static int	set_rdct_type(t_ast *ast, t_cmd *cmd, t_type type, t_heredoc **hdc)
{
	if (add_rdct_lst(ast, cmd, type, *hdc))
		return (ERR);
	if (type == TYPE_REDIR_IN)
	{
		cmd->type_rdct[0] = type;
		cmd->file_path[0] = ast->args[0];
	}
	else if (type == TYPE_REDIR_OUT || type == TYPE_REDIR_APP)
	{
		cmd->type_rdct[1] = type;
		cmd->file_path[1] = ast->args[0];
	}
	else if (type == TYPE_REDIR_HDC)
	{
		cmd->type_rdct[0] = type;
		cmd->file_path[0] = (*hdc)->filename;
		*hdc = (*hdc)->next;
	}
	return (0);
}

static int	add_rdct_lst(t_ast *ast, t_cmd *cmd, t_type type, t_heredoc *hdc)
{
	t_rdct	*tmp;

	tmp = cmd->files;
	if (!tmp)
	{
		cmd->files = ft_calloc(1, sizeof(t_rdct));
		tmp = cmd->files;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_calloc(1, sizeof(t_rdct));
		tmp = tmp->next;
	}
	if (!tmp)
		return (ERR);
	tmp->type = type;
	if (type == TYPE_REDIR_HDC)
		tmp->path = hdc->filename;
	else
		tmp->path = ast->args[0];
	return (0);
}
