/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:50:10 by jiepark           #+#    #+#             */
/*   Updated: 2024/10/23 13:50:14 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	handle_signal(int sig)
{
	static int		bit = 0;
	static int		data = 0;

	if (sig == SIGUSR2)
		data |= (0x01 << bit);
	bit++;
	if (bit % 8 == 0)
	{
		ft_printf("%c", data);
		bit = 0;
		data = 0;
	}
}

int	main(void)
{
	ft_printf("The server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, handle_signal);
		signal(SIGUSR1, handle_signal);
		pause();
	}
	return (0);
}
