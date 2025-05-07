/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:44:52 by                   #+#    #+#             */
/*   Updated: 2025/05/04 20:28:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	count_cmd(t_ast *ast)
{
	int	n;

	if (!ast)
		return (ERR);
	n = 0;
	while (1)
	{
		if (ast->type == TYPE_CMD)
			n++;
		if (ast->right)
			ast = ast->right;
		else
			break ;
	}
	return (n);
}

int	op_check(t_cmd **cmd, int *excode)
{
	if ((*cmd)->op == OP_OR && *excode)
	{
		(*cmd)->op = 0;
		*excode = 0;
		return (1);
	}
	if ((*cmd)->op == OP_AND && !*excode)
	{
		(*cmd)->op = 0;
		return (1);
	}
	if (!(*cmd)->op && (*cmd)->paren[1])
		return (1);
	if (!(*cmd)->paren[0] && !(*cmd)->paren[0] && (*cmd)->next)
		*cmd = (*cmd)->next;
	else
		return (0);
	return (op_check(cmd, excode));
}

int	is_directory(char *path)
{
	struct stat	st;

	if (stat(path, &st))
		return (ERR);
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

char	*create_pathstr(char *path, char *cmd)
{
	char	*tmp;

	tmp = NULL;
	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		if (!tmp)
			return (NULL);
	}
	path = tmp;
	tmp = ft_strjoin(path, cmd);
	if (!tmp)
		return (free(path), NULL);
	free(path);
	return (tmp);
}

void	set_excode(t_mshell *data, int code)
{
	data->dol_questn = code;
}
