/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:12:34 by                   #+#    #+#             */
/*   Updated: 2025/04/10 16:00:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

int	ms_unset(t_mshell *data, char **av)
{
	char	**tmp;
	t_env	*to_remv;

	if (!av[1])
		return (0);
	tmp = av;
	while (*(++tmp))
	{
		to_remv = search_env_name(data->env_var, *tmp);
		if (to_remv)
		{
			if (to_remv->key && !ft_strncmp(to_remv->key, "PATH", 5))
			{
				free_matrix(data->path, 0);
				data->path = NULL;
			}
			lst_rm_env(&data->env_var, to_remv);
		}
	}
	return (0);
}
