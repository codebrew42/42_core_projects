/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:54:57 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/04/09 23:24:16 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

int	ms_pwd(t_env *env)
{
	char	*pwd;

	pwd = get_working_dir(env);
	if (!pwd)
		return (ERR);
	ft_putendl_fd(pwd, 1);
	free(pwd);
	return (0);
}

//check if symb. link: compare result of getcwd and $PWD
char	*get_working_dir(t_env *env)
{
	char	*cwd;
	char	*env_pwd;
	int		islink;
	int		cwd_len;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	cwd_len = ft_strlen(cwd);
	env_pwd = get_env_val(env, "PWD");
	if (!env_pwd)
		return (cwd);
	if ((int)ft_strlen(env_pwd) >= cwd_len && \
		ft_strncmp(env_pwd, cwd, cwd_len + 1))
	{
		islink = is_symlink(cwd, env_pwd);
		if (islink == ERR)
			return (free(cwd), NULL);
		else if (islink)
			return (free(cwd), ft_strdup(env_pwd));
	}
	return (cwd);
}
