/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:35:52 by jiepark          #+#    #+#              */
/*   Updated: 2024/12/25 20:35:52 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		join_threads(t_data *d, int n_philo);
void		free_data(t_data **d);
void		destroy_mutex(t_data *d);

int	join_threads(t_data *d, int n_philo)
{
	int		i;

	i = 0;
	printf("Starting to join threads. n_philo = %d\n", n_philo);
	while (i < n_philo)
	{
		printf("Attempting to join routine thread %d\n", i);
		if (pthread_join(d->routine_thread[i], NULL))
		{
			printf("Failed to join routine thread %d\n", i);
			return (exit_on_error("pthread_join failed", 0));
		}
		printf("Successfully joined routine thread %d\n", i);
		i++;
	}
	printf("Attempting to join monitor thread\n");
	if (pthread_join(d->monitor_thread, NULL))
	{
		printf("Failed to join monitor thread\n");
		return (exit_on_error("pthread_join failed", 0));
	}
	printf("Successfully joined monitor thread\n");
	return (0);
}

/*
int	join_threads(t_data *d, int n_philo)
{
	int		i;

	i = 0;
	while (i < n_philo)
	{
		if (pthread_join(d->routine_thread[i], NULL))
		{
			printf("check debugging point A: [%d]\n", i);
			//free_data(&d);
			return (exit_on_error("pthread_join failed", 0));
		}
		i++;
	}
	if (pthread_join(d->monitor_thread, NULL))
	{
		printf("check debugging point B\n");
		free_data(&d);
		return (exit_on_error("pthread_join failed", 0));
	}
	return (0);
}*/


void	free_data(t_data **d)
{
	if (!d || !*d)
		return ;
	if ((*d)->forks)
		free((*d)->forks);
	if ((*d)->philos)
		free((*d)->philos);
	if ((*d)->routine_thread)
		free((*d)->routine_thread);
	if (*d)
		free(*d);
	*d = NULL;
}

void	destroy_mutex(t_data *d)
{
	int		i;
	int		n_philo;

	n_philo = d->nbr_of_philos;
	join_threads(d, n_philo);
	pthread_mutex_destroy(&d->death_lock);
	pthread_mutex_destroy(&d->print_lock);
	i = 0;
	while (i < d->nbr_of_philos)
	{
		pthread_mutex_destroy(&d->forks[i]);
		pthread_mutex_destroy(&d->philos[i].meal_lock);
		i++;
	}
	printf("time: %ld, check debugging point C\n", get_current_time() - d->start_time);
}
