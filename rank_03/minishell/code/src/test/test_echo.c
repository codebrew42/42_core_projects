/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:47:01 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/03/15 12:01:11 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

int	main(int ac, char **av)
{
	(void)ac;
	ms_echo(av);
	return (0);
}
