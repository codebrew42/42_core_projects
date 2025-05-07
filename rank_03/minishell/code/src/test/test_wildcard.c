/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wildcard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:35:01 by                   #+#    #+#             */
/*   Updated: 2025/04/30 17:32:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "test_ms.h"
#include "expander.h"

int	g_signal = 0;

int	main(int ac, char **av, char **envp)
{
	t_mshell	*data;
	init_mshell(&data, envp);
	char	*line;
	char	**args;

	(void)ac;
	(void)av;
	args = NULL;
	line = ft_strdup("*.supp");
	if (line)
	{
		args = wc_expander(data, line);
		if (args)
			testprint_args(args);
		free_matrix(args, 0);
	}
	free(line);
	free_mshell(data);
	return (0);
}
