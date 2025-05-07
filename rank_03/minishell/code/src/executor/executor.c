/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:16:44 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/05 21:05:55 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	executor(t_mshell *data)
{
	t_cmd	*cmds;
	int		*pids;
	int		proc_count;

	setup_signals(SIGNAL_MODE_PARENT_WAITING);
	if (g_signal)
		return (0);
	cmds = NULL;
	pids = NULL;
	if (check_paren(data->ast_root))
		return (ERR);
	proc_count = init_executor(data, &cmds, &pids);
	if (proc_count == ERR)
		exit_cmdproc(data, cmds, 1);
	else if (proc_count < 0)
		return (set_excode(data, 1), free_cmddata(cmds), 1);
	cmds->pids = pids;
	if (proc_count > 0)
		exec_cmds(data, cmds, pids);
	free_cmddata(cmds);
	if (pids)
		free(pids);
	if (proc_count == ERR)
		errno_exit(data);
	return (0);
}

int	exec_cmds(t_mshell *data, t_cmd *cmds, int *pids)
{
	t_cmd	*tmp;
	int		excode;

	tmp = cmds;
	while (tmp)
	{
		if (tmp->paren[0])
			if (create_subshell(data, cmds, &tmp, pids) || !tmp)
				break ;
		if (tmp != cmds && !op_check(&tmp, &(data->dol_questn)))
			break ;
		if (tmp->paren[0])
			continue ;
		tmp->pids = pids;
		if (create_cmdproc(data, &tmp, cmds, pids))
			return (ERR);
		wait_cmdproc(data, pids);
		if (!tmp || (!tmp->op && tmp->paren[1] && !tmp->paren[0]))
			break ;
	}
	excode = data->dol_questn;
	if (cmds->child)
		return (free_cmdproc(data, cmds), exit(excode), 0);
	return (data->dol_questn);
}

int	create_subshell(t_mshell *data, t_cmd *cmds, t_cmd **tmp, int *pids)
{
	int	excode;

	if ((*tmp)->op >= OP_OR && !op_check(tmp, &(data->dol_questn)))
	{
		moveto_parenend(tmp);
		if (*tmp && (*tmp)->paren[1])
			return (1);
		return (0);
	}
	(*tmp)->paren[0]--;
	*pids = fork();
	if (*pids < 0)
		return (ERR);
	else if (!*pids)
	{
		free_prev_cmds(&cmds, tmp);
		return (set_flags(tmp, pids), exec_cmds(data, *tmp, pids));
	}
	(*tmp)->paren[0]++;
	moveto_parenend(tmp);
	wait_cmdproc(data, pids);
	excode = data->dol_questn;
	if (*tmp && (*tmp)->paren[0] && (*tmp)->paren[1])
		return (free_cmdproc(data, cmds), exit(excode), 0);
	return (0);
}

int	create_cmdproc(t_mshell *data, t_cmd **cmd, t_cmd *cmd_root, int *pids)
{
	while (*cmd)
	{
		if (create_pipe(*cmd) == ERR)
			return (ERR);
		if (open_file(data, *cmd, (*cmd)->files) != ERR)
		{
			if ((*cmd)->bi_only)
				exec_builtin(data, *cmd, cmd_root);
			else if (!g_signal)
			{
				*pids = fork();
				if (*pids < 0)
					return (close_pstream(*cmd), ERR);
				if (!*pids++)
					cmd_proc(data, *cmd, cmd_root);
			}
		}
		close_pstream(*cmd);
		if ((*cmd)->paren[1])
			break ;
		*cmd = (*cmd)->next;
		if (!*cmd || (*cmd)->op == OP_AND || (*cmd)->op == OP_OR)
			break ;
	}
	return (0);
}

void	wait_cmdproc(t_mshell *data, int *pids)
{
	int	status;
	int	waited;

	status = 0;
	waited = 0;
	if (!pids)
		return ;
	while (*pids)
	{
		waitpid(*pids, &status, 0);
		*pids = 0;
		waited = 1;
		pids++;
	}
	if (waited && !data->dol_questn)
	{
		if (WIFSIGNALED(status))
			data->dol_questn = WTERMSIG(status) + 128;
		else
			data->dol_questn = WEXITSTATUS(status);
		if (g_signal == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", 2);
	}
}
