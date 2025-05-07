/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:29:01 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/05/04 19:38:55 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "heredoc.h"

static void	hdc_input(t_mshell *data, t_heredoc *hdc);
static void	handl_hdc_input(t_mshell *data, t_heredoc *hdc, char **input);

void	ms_heredoc(t_mshell *data)
{
	t_heredoc	*tmp;
	int			std_in;

	if (g_signal || init_heredoc(data))
		return ;
	tmp = data->hdc;
	while (tmp && !g_signal)
	{
		if (create_hdc_file(tmp))
			errno_exit(data);
		std_in = dup(0);
		hdc_input(data, tmp);
		if (set_stdinout(std_in, 0))
			errno_exit(data);
		close(tmp->fd);
		tmp = tmp->next;
	}
	if (g_signal)
		clean_hdc(data);
}

static void	hdc_input(t_mshell *data, t_heredoc *hdc)
{
	char	*input;

	while (*hdc->lim)
	{
//		ft_putendl_fd(*hdc->lim, 1);//test
		while (!g_signal)
		{
			setup_signals(SIGNAL_MODE_HEREDOC);
			input = readline("> ");
			if (!input)
				break ;
			if (!ft_strncmp(input, *(hdc->lim), ft_strlen(*(hdc->lim)) + 1))
			{
				free(input);
				break ;
			}
			if (!(hdc->lim[1]))
				handl_hdc_input(data, hdc, &input);
			free(input);
		}
		setup_signals(SIGNAL_MODE_INTERACTIVE);
		hdc->lim++;
	}
}

static void	handl_hdc_input(t_mshell *data, t_heredoc *hdc, char **input)
{
	char	*line;

	if (ft_strchr(*input, '$'))
		*input = ev_expander(data, *input);
	line = ft_strjoin(*input, "\n");
	if (!line)
	{
		free(*input);
		errno_exit(data);
	}
	write(hdc->fd, line, ft_strlen(line));
	free(line);
}
