/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:35:47 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/04/10 15:15:27 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

int	ms_env(t_env *env)
{
	if (!env)
		return (0);
	ft_putstr_fd(env->key, 1);
	write(1, "=", 1);
	if (env->value)
		ft_putstr_fd(env->value, 1);
	write(1, "\n", 1);
	return (ms_env(env->next));
}
