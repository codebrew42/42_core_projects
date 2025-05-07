/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdproc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:52:51 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/03 22:00:15 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

static int	check_cmdpath(t_mshell *data, t_cmd *cmd, t_cmd *cmd_rt);
static int	search_cmdpath(t_mshell *data, t_cmd *cmd, t_cmd *cmd_rt);

int	cmd_proc(t_mshell *data, t_cmd *cmd, t_cmd *cmd_root)
{
	setup_signals(SIGNAL_MODE_CHILD);
	cmd->child = 1;
	if (set_cstream(cmd))
	{
		free_cmdproc(data, cmd_root);
		err_exit(NULL, 0);
	}
	if (!cmd->args[0])
		exit_cmdproc(data, cmd_root, g_signal);
	else if (cmd->bi)
	{
		call_builtin(data, cmd, cmd_root, NULL);
		exit_builtin(data, cmd, cmd_root, NULL);
	}
	else if (!g_signal && check_cmd(data, cmd, cmd_root))
		err_cmd(data, cmd_root, cmd->args[0]);
	if (!g_signal && execve(cmd->path, cmd->args, data->envp))
	{
		free_cmdproc(data, cmd_root);
		err_exit(NULL, 0);
	}
	free_cmdproc(data, cmd_root);
	exit (g_signal);
}

int	set_cstream(t_cmd *cmd)
{
	if (cmd->fdout)
	{
		if (set_stdinout(cmd->fdout, 1))
			return (ERR);
	}
	else if (cmd->pipe[0])
	{
		close(cmd->pipe[0]);
		if (set_stdinout(cmd->pipe[1], 1))
			return (ERR);
	}
	if (cmd->fdin)
	{
		if (set_stdinout(cmd->fdin, 0))
			return (ERR);
	}
	else if (cmd->pipe_prev[0])
	{
		if (set_stdinout(*cmd->pipe_prev[0], 0))
			return (ERR);
	}
	return (0);
}

int	check_cmd(t_mshell *data, t_cmd *cmd, t_cmd *cmd_rt)
{
	if (cmd->args[0][0] == '/')
		check_cmdpath(data, cmd, cmd_rt);
	else if (!cmd->args[0][0])
		return (1);
	else if (!ft_strncmp(cmd->args[0], "./", 2))
	{
		if (add_cwd_path(data->env_var, cmd->args, 1))
			exit_cmdproc(data, cmd_rt, errno);
		check_cmdpath(data, cmd, cmd_rt);
	}
	else if (!ft_strncmp(cmd->args[0], "../", 3))
	{
		if (add_cwd_path(data->env_var, cmd->args, 2))
			exit_cmdproc(data, cmd_rt, errno);
		check_cmdpath(data, cmd, cmd_rt);
	}
	else
	{
		if (!data->path)
			return (err_msg(ERR_FILE, cmd->args[0]), \
			exit_cmdproc(data, cmd_rt, 127), 1);
		search_cmdpath(data, cmd, cmd_rt);
	}
	return (0);
}

static int	check_cmdpath(t_mshell *data, t_cmd *cmd, t_cmd *cmd_rt)
{
	char	*path;

	path = cmd->args[0];
	errno = 0;
	if (access(path, F_OK | X_OK))
	{
		if (errno == EACCES)
			return (errno_msg(path, NULL), exit_cmdproc(data, cmd_rt, 126), 1);
		else if (errno == ENOENT)
			return (errno_msg(path, NULL), exit_cmdproc(data, cmd_rt, 127), 1);
		else
			return (free_cmdproc(data, cmd_rt), err_exit(NULL, 0), 1);
	}
	if (is_directory(path) > 0)
		return (err_msg(ERR_DIR, path), exit_cmdproc(data, cmd_rt, 126), 1);
	cmd->path = ft_strdup(path);
	return (0);
}

static int	search_cmdpath(t_mshell *data, t_cmd *cmd, t_cmd *cmd_rt)
{
	char	*fullp;
	char	**path;

	path = data->path;
	fullp = NULL;
	while (*path)
	{
		errno = 0;
		fullp = create_pathstr(*path++, cmd->args[0]);
		if (!fullp)
			return (free_cmdproc(data, cmd_rt), err_exit(NULL, 0), 1);
		if (g_signal || !access(fullp, F_OK | X_OK))
		{
			if (!g_signal && is_directory(fullp))
				return (free(fullp), err_cmd(data, cmd_rt, cmd->args[0]), 1);
			cmd->path = fullp;
			return (0);
		}
		if (errno == EACCES)
			return (errno_msg(fullp, NULL), free(fullp), \
			exit_cmdproc(data, cmd_rt, 126), 1);
		free(fullp);
	}
	err_cmd(data, cmd_rt, cmd->args[0]);
	return (1);
}
