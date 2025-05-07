/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:56:03 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/02/14 18:09:09 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

void	handle_sigint(int sig)
{
	write(1, "\n", 1);
	rl_on_new_line(); //show the prompt
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(void)
{
	char	*input;
	struct sigaction	act;

	act.sa_handler = &handle_sigint;
	sigaction(SIGINT, &act, NULL);
	while(1)
	{
		input = readline(">> ");
		if (!input) //break if ctrl + D
			break ;
		if (*input)
			add_history(input);
		write(1, input, ft_strlen(input));
		free(input); //still memory leak, but the subject says ok...
	}
	return (0);
}
