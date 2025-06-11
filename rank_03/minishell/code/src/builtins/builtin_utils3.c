/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:09:50 by                   #+#    #+#             */
/*   Updated: 2025/04/10 00:20:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	set_env_oldpwd(t_env **env)
{
	t_env	*new;
	char	*pwd;

	pwd = get_working_dir(*env);
	if (!pwd)
		return (ERR);
	if (!set_env_val(*env, "OLDPWD", pwd))
		return (0);
	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (free(pwd), ERR);
	new->key = ft_strdup("OLDPWD");
	new->value = pwd;
	lst_add_env(env, new);
	return (0);
}

int	set_env_pwd(t_env **env, char *path)
{
	t_env	*new;

	if (!set_env_val(*env, "PWD", path))
		return (0);
	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (ERR);
	new->key = ft_strdup("PWD");
	if (!new->key)
		return (ERR);
	new->value = path;
	lst_add_env(env, new);
	return (0);
}

int	no_alpha_name(char *s)
{
	while (*s)
	{
		if (*s == '=')
			break ;
		if (ft_isalpha(*s))
			break ;
		s++;
	}
	if (!*s || *s == '=')
		return (1);
	return (0);
}

int	spchar_in_name(char *s)
{
	while (*s)
	{
		if (!ft_isalnum(*s) && *s != '_')
			break ;
		s++;
	}
	if (!*s || *s == '=')
		return (0);
	return (1);
}
