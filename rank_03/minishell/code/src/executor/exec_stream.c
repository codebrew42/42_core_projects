/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_stream.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:30:26 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/04 16:43:03 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	open_file(t_mshell *data, t_cmd *cmd, t_rdct *file)
{
	while (file)
	{
		if (file->type == TYPE_REDIR_IN || file->type == TYPE_REDIR_HDC)
			file->fd = open(file->path, O_RDONLY);
		if (file->type == TYPE_REDIR_HDC)
			unlink(file->path);
		if (file->type == TYPE_REDIR_OUT)
			file->fd = open(file->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else if (file->type == TYPE_REDIR_APP)
			file->fd = open(file->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (file->fd < 0)
		{
			if (cmd->child || !cmd->next || cmd->op >= OP_OR || cmd->paren[1])
				data->dol_questn = 1;
			return (errno_msg(cmd->args[0], file->path), ERR);
		}
		if (file->path == cmd->file_path[0])
			cmd->fdin = file->fd;
		else if (file->path == cmd->file_path[1])
			cmd->fdout = file->fd;
		else
			close(file->fd);
		file = file->next;
	}
	return (0);
}

int	create_pipe(t_cmd *cmd)
{
	if (cmd->op != OP_PIPE)
		return (0);
	if (pipe(cmd->pipe) < 0)
		return (ERR);
	cmd->next->pipe_prev[0] = &(cmd->pipe[0]);
	cmd->next->pipe_prev[1] = &(cmd->pipe[1]);
	return (0);
}

void	close_pstream(t_cmd *cmd)
{
	if (cmd->pipe[1])
		close(cmd->pipe[1]);
	if (cmd->pipe_prev[0])
		close(*(cmd->pipe_prev[0]));
	if (cmd->fdin > 0)
		close(cmd->fdin);
	if (cmd->fdout > 0)
		close(cmd->fdout);
	if (!cmd->next || cmd->op == OP_AND || cmd->op == OP_OR)
		if (cmd->pipe[0])
			close(cmd->pipe[0]);
}
