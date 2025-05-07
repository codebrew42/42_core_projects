/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:03:38 by jiepark           #+#    #+#             */
/*   Updated: 2025/05/05 19:22:01 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

sig_atomic_t	g_signal = 0;

int	main(int ac, char **av, char **envp)
{
	t_mshell	*ms_data;

	if (ac != 1 || av[1])
		return (1);
	if (init_mshell(&ms_data, envp))
		return (1);
	minishell(ms_data);
	return (0);
}

static void	process_command(t_mshell *ms_data, char *input)
{
	int		tokenizer_result;

	if (!*input)
		return ;
	add_history(input);
	errno = 0;
	tokenizer_result = tokenizer(ms_data, input);
	if (tokenizer_result)
	{
		if (tokenizer_result == 2)
			ms_data->dol_questn = 2;
		return ;
	}
	if (!parser(&ms_data->tokens, &ms_data->ast_root))
	{
		ms_data->dol_questn = 2;
		return ;
	}
//	print_token(ms_data); //db
	if (ms_data->ast_root)
		handle_expansions_with_qots(ms_data, ms_data->ast_root);
//	print_ast(ms_data); //db
	g_signal = 0;
	ms_data->dol_questn = 0;
	//print_ast(ms_data); //db
	ms_heredoc(ms_data);
	executor(ms_data);
	//	print_ast(ms_data); //db
}

void	minishell(t_mshell *ms_data)
{
	char	*input;

	while (!ms_data->exit_requested)
	{
		setup_signals(SIGNAL_MODE_INTERACTIVE);
		if (ms_data->tokens)
		{
			free_token_and_reset(&ms_data->tokens);
			ms_data->tokens = NULL;
		}
		if (ms_data->ast_root)
		{
			free_ast(ms_data->ast_root);
			ms_data->ast_root = NULL;
		}
		input = readline("minishell> ");
		if (!input)
			break ;
		process_command(ms_data, input);
		free(input);
	}
	free_mshell(ms_data);
}
