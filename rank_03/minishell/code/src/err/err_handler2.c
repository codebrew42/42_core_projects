/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                      e>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:25:19 by                   #+#    #+#             */
/*   Updated: 2025/04/05 20:31:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	err_cmd_str_msg(char *cmd, char *s, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	if (cmd)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
	}
	if (s)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
}
