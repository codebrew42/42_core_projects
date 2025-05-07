/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:12:17 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/01 19:03:45 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

static void	check_args(char **args, int *excode);
static int	arg_isdigit(char *s);

int	ms_exit(t_mshell *data, t_cmd *cmd_root, t_cmd *cmd, int *std)
{
	int	excode;

	ft_putendl_fd("exit", 1);
	check_args(cmd->args, &excode);
	if (!cmd->child)
		free(cmd->pids);
	close_pstream(cmd);
	if (std)
	{
		close(std[0]);
		close(std[1]);
	}
	free_cmddata(cmd_root);
	free_mshell(data);
	exit(excode);
}

static void	check_args(char **args, int *excode)
{
	int		n;
	long	l;

	n = count_args(args);
	if (n == 1)
		*excode = 0;
	else if (n == 2 && arg_isdigit(args[1]))
	{
		l = ft_atol(args[1]) % 256;
		if (l < 0)
			*excode = 256 - (l * -1);
		else
			*excode = l;
	}
	else if (!arg_isdigit(args[1]))
	{
		err_msg(ERR_EXIT_NUM, args[1]);
		*excode = 2;
	}
	else
	{
		err_msg(ERR_EXIT_ARG, args[1]);
		*excode = 1;
	}
}

static int	arg_isdigit(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (1);
}
