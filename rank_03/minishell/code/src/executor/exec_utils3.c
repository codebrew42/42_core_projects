/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:42:47 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/05 20:59:03 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	free_prev_cmds(t_cmd **root, t_cmd **current)
{
	t_cmd	*tmp;

	while (*root != *current)
	{
		tmp = (*root)->next;
		free(*root);
		*root = tmp;
	}
}

void	set_flags(t_cmd **cmd, int *pids)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		tmp->child = 1;
		tmp->pids = pids;
		if (tmp->paren[1])
			break ;
		tmp = tmp->next;
	}
}
