/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:50:16 by                   #+#    #+#             */
/*   Updated: 2025/04/10 15:10:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	free_cmdproc(t_mshell *data, t_cmd *cmd_root)
{
	free_mshell(data);
	if (cmd_root->pids)
		free(cmd_root->pids);
	free_cmddata(cmd_root);
}

void	free_cmddata(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_cmddata(cmd->next);
	if (cmd->path)
		free(cmd->path);
	if (cmd->files)
		free_rdct(cmd->files);
	free(cmd);
}

void	err_cmd(t_mshell *data, t_cmd *cmd_root, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(ERR_CMD, 2);
	free_cmdproc(data, cmd_root);
	exit(CMD_INVALID);
}

void	exit_cmdproc(t_mshell *data, t_cmd *cmd_root, int excode)
{
	free_cmdproc(data, cmd_root);
	exit(excode);
}

void	free_rdct(t_rdct *node)
{
	if (!node)
		return ;
	free_rdct(node->next);
	free(node);
}
