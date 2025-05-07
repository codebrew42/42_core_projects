/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:51:10 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/04/09 22:53:28 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

int	count_args(char **args)
{
	int	n;

	n = 0;
	while (args[n])
		n++;
	return (n);
}

int	is_symlink(char *cwd, char *link)
{
	struct stat	st_c;
	struct stat	st_l;

	if (stat(cwd, &st_c))
		return (ERR);
	if (stat(link, &st_l))
		return (ERR);
	if (st_c.st_ino == st_l.st_ino)
		return (1);
	return (0);
}

char	*get_fullpath(t_env *env, char *path)
{
	char	*fullp;
	char	*cwd;

	if (path[0] == '/')
		fullp = ft_strdup(path);
	else if (*path && !ft_strncmp(path, ".", 2))
		fullp = getcwd(NULL, 0);
	else if (ft_strlen(path) == 2 && !ft_strncmp(path, "..", 3))
	{
		fullp = getcwd(NULL, 0);
		cwd = ft_strrchr(fullp, '/');
		if (cwd)
			*cwd = 0;
	}
	else
		fullp = create_fullp(env, path, 0);
	return (fullp);
}

char	*create_fullp(t_env *env, char *file, int dot)
{
	char	*fullp;
	char	*cwd;
	char	*slash;

	cwd = get_working_dir(env);
	if (!cwd)
		return (NULL);
	slash = ft_strrchr(cwd, '/');
	if (dot == 2)
		ft_bzero(slash, ft_strlen(slash));
	fullp = ft_strjoin(cwd, "/");
	if (!fullp)
		return (NULL);
	free(cwd);
	cwd = fullp;
	fullp = ft_strjoin(cwd, file);
	free(cwd);
	return (fullp);
}

int	add_cwd_path(t_env *env, char **args, int dot)
{
	char	*fullp;
	char	*file;

	fullp = NULL;
	file = args[0];
	fullp = create_fullp(env, file + dot + 1, dot);
	if (!fullp)
		return (ERR);
	free(file);
	args[0] = fullp;
	return (0);
}
