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

int		handle_case_one(t_data *d);
int		launch_threads(t_data *d, int n_philos);

int	handle_case_one(t_data *d)
{
	if (d->nbr_of_philos != 1)
		return (0);
	pthread_mutex_lock(&d->print_lock);
	printf("%lu %d %s\n", 0lu, 1, "has taken a fork");
	pthread_mutex_unlock(&d->print_lock);
	usleep(d->time_to_die * 1000);
	pthread_mutex_lock(&d->print_lock);
	printf("%lu %d %s\n", d->time_to_die, 1, "died");
	pthread_mutex_unlock(&d->print_lock);
	return (1);
}

int	launch_threads(t_data *d, int n_philos)
{
	int			i;

	d->start_time = get_current_time();
	i = 0;
	while (i < n_philos)
	{
		d->philos[i].last_meal_time = d->start_time;
		i++;
	}
	i = 0;
	while (i < n_philos)
	{
		if (pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]))
		{
			if (join_n_threads(d->routine_thread, i))
				return (1);
		}
		i++;
	}
	if (pthread_create(&d->monitor_thread, NULL, monitor, d))
	{
		if (join_n_threads(d->routine_thread, i))
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data		*d;
	int			n_philos;

	if (ac != 5 && ac != 6)
		return (print_err_msg("Number of arguments is not 4 or 5"));
	if (!init_data(&av[1], &d))
	{
		n_philos = d->nbr_of_philos;
		if (!handle_case_one(d))
		{
			if (launch_threads(d, n_philos))
				print_err_msg("thread creation failed");
			else
				join_all_threads(d);
		}
		destroy_all_mutexes(d, n_philos);
	}
	free_data(&d);
	return (0);
}
