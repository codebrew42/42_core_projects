/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyabuuch <kyabuuch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:56:03 by kyabuuch          #+#    #+#             */
/*   Updated: 2025/02/14 17:13:08 by kyabuuch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*input;

	while(1)
	{
		input = readline(">> ");
		if (!input) //break if ctrl + D
			break ;
		write(1, input, ft_strlen(input));
		free(input); //still memory leak, but the subject says ok...
	}
	return (0);
}

