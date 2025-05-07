/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:07:43 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/01 18:40:18 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

static int	isoption_n(char *s);

int	ms_echo(char **av)
{
	int	op_n;
	int	ac;

	ac = count_args(av);
	op_n = 0;
	while (*(++av) && isoption_n(*av))
	{
		op_n = 1;
		ac--;
	}
	while (--ac)
	{
		ft_putstr_fd(*av++, 1);
		if (ac > 1)
			ft_putchar_fd(' ', 1);
	}
	if (!op_n)
		write(1, "\n", 1);
	return (0);
}

static int	isoption_n(char *s)
{
	if (!ft_strncmp(s, "-n", 2))
	{
		s = s + 2;
		while (*s && *s == 'n')
			s++;
		if (!*s)
			return (1);
	}
	return (0);
}
