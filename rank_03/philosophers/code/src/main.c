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


int	main(int ac, char **av)
{
	t_data		*d;
	int			n_philo;

	if (ac != 6)
		return (exit_on_error("Number of arguments should be 5", 1));
	init_data(&av[1], &d);
	n_philo = d->nbr_of_philos;
	launch_monitor_threads(d, n_philo);
	launch_routine_threads(d, n_philo);
	join_threads(d, n_philo);
	destroy_mutex(d);
	free_data(&d);
}
