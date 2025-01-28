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

void	display_data(t_data *d)
{
	printf("* * * display starts... * * *\n");

	printf("nbr_of_philos: %zu\n", d->nbr_of_philos);
	printf("time_to_die: %lu\n", d->time_to_die);
	printf("time_to_eat: %lu\n", d->time_to_eat);
	printf("time_to_sleep: %lu\n", d->time_to_sleep);
	printf("nbr_of_times_each_philo_must_eat: %zu\n", d->nbr_of_times_each_philo_must_eat);

	printf("nbr_of_philos_full: %d\n", d->nbr_of_philos_full);
	printf("dead_philo_id: %d\n", d->dead_philo_id);
	printf("start_time: %lu\n", d->start_time);

	printf("* * * printing philosophers * * *\n");
	for (size_t i = 0; i < d->nbr_of_philos; i++)
	{
		printf("philos[%zu].id: %d\n", i, d->philos[i].id);
		printf("philos[%zu].has_died: %d\n", i, d->philos[i].has_died);
		printf("philos[%zu].meal_count: %d\n", i, d->philos[i].meal_count);
		printf("philos[%zu].last_meal_time: %lu\n", i, d->philos[i].last_meal_time);
		printf("philos[%zu].death_timestamp: %lu\n", i, d->philos[i].death_timestamp);
	}
	printf("* * * display ends... * * *\n");
}

int	main(int ac, char **av)
{
	t_data		*d;
	int			n_philo;

	if (ac != 5 && ac != 6)
		return (exit_on_error("Number of arguments should be 5 or 6", 1));
	init_data(&av[1], &d);
	n_philo = d->nbr_of_philos;

	//rm
	//display_data(d);
	//display_status(d, "is eating\n", 1);

	launch_threads(d, n_philo);


	destroy_mutex(d);
	free_data(&d);
}
