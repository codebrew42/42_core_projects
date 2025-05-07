/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:59:31 by jiepark           #+#    #+#             */
/*   Updated: 2025/04/30 16:41:49 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	setup_signals(int mode);
void	execution_signal_handler(int sig_nbr);
void	interactive_sigint_handler(int sig);
void	heredoc_sigint_handler(int sig);

void	setup_signals(int mode)
{
	if (mode == SIGNAL_MODE_INTERACTIVE)
	{
		set_terminal_print_off();
		signal(SIGINT, interactive_sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == SIGNAL_MODE_CHILD)
	{
		set_terminal_print_off();
		signal(SIGINT, cmdproc_signal_handler);
		signal(SIGQUIT, cmdproc_signal_handler);
	}
	else if (mode == SIGNAL_MODE_HEREDOC)
	{
		set_terminal_print_off();
		signal(SIGQUIT, SIG_IGN);
		set_terminal_print_on();
		signal(SIGINT, heredoc_sigint_handler);
	}
	else if (mode == SIGNAL_MODE_PARENT_WAITING)
	{
		set_terminal_print_off();
		signal(SIGINT, execution_signal_handler);
		signal(SIGQUIT, execution_signal_handler);
	}
}

void	interactive_sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	g_signal = sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	heredoc_sigint_handler(int sig)
{
	(void)sig;
	g_signal = sig;
	close(0);
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	execution_signal_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n", 2);
}

void	cmdproc_signal_handler(int sig)
{
	g_signal = sig;
}
