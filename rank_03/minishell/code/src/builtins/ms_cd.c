/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:30:36 by                   #+#    #+#             */
/*   Updated: 2025/04/23 10:47:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

static int	cd_isvalid(char **args);
static int	handl_dot_path(t_env **env, char *arg);
static int	move_cwd(t_env **env, char *path, char *fullp);

int	ms_cd(t_env **env, char **args)
{
	char	*fullp;

	if (!cd_isvalid(args))
		return (1);
	fullp = NULL;
	if (set_env_oldpwd(env))
		return (ERR);
	if (!args[1])
	{
		fullp = get_env_val(*env, "HOME");
		if (!fullp)
			return (ERR);
		return (move_cwd(env, fullp, fullp));
	}
	else if (!ft_strncmp(args[1], "./", 2) || !ft_strncmp(args[1], "../", 3))
		return (handl_dot_path(env, args[1]));
	else
	{
		fullp = get_fullpath(*env, args[1]);
		if (!fullp)
			return (ERR);
		return (move_cwd(env, args[1], fullp));
	}
	return (0);
}

static int	cd_isvalid(char **args)
{
	int	n;

	n = 0;
	n = count_args(args);
	if (n > 2)
		return (err_msg(ERR_EXIT_ARG, "cd"), 0);
	if (n == 2 && access(args[1], F_OK | X_OK))
		return (errno_msg("cd", args[1]), 0);
	return (1);
}

static int	handl_dot_path(t_env **env, char *arg)
{
	char	*path;
	int		dot;

	if (!ft_strncmp(arg, "./", 2))
		dot = 1;
	else
		dot = 2;
	path = ft_strdup(arg);
	if (!path)
		return (ERR);
	if (add_cwd_path(*env, &path, dot))
		return (free(path), ERR);
	return (move_cwd(env, arg, path));
}

static int	move_cwd(t_env **env, char *path, char *fullp)
{
	int	fp_len;

	fp_len = ft_strlen(fullp);
	if (fullp[fp_len - 1] == '/' && ft_strncmp("/", fullp, 2))
		fullp[fp_len - 1] = 0;
	if (chdir(path))
		return (free(fullp), errno_msg("cd", path), 1);
	if (ft_strchr(fullp, '.'))
	{
		free(fullp);
		fullp = get_working_dir(*env);
		if (!fullp)
			return (ERR);
	}
	if (set_env_pwd(env, fullp))
		return (free(fullp), ERR);
	return (0);
}
