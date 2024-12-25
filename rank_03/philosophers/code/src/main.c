/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:36:11 by jiepark          #+#    #+#              */
/*   Updated: 2024/12/25 20:36:11 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display_warning_message(char *s);
int		exit_on_error(char *s, int exit_flag);

void	display_warning_message(char *s)
{
	printf("Warning: %s", s);
}

int	exit_on_error(char *s, int exit_flag)
{
	printf("Error: %s", s);
	if (exit_flag == 1)
		exit(1);
	return (1);
}

int	main(int ac, char **av)
{
	t_data		*d;
	int			n_philo;

	if (ac != 6)
		return (exit_on_error("Number of arguments should be 5", 1));
	init_data(&av[1], &d);
	n_philo = d->nbr_of_philos;
	launch_threads(d, n_philo);
	join_threads(d, n_philo);
	destroy_mutex(d);
	free_data(&d);
}
