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
	while (i < n_philo)
	{
		if (pthread_join(d->routine_thread[i], NULL))
		{
			free_data(&d);
			return (exit_on_error("pthread_join failed", 0));
		}
		i++;
	}
	if (pthread_join(d->monitor_thread, NULL))
	{
		free_data(&d);
		return (exit_on_error("pthread_join failed", 0));
	}
	return (0);
}


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

	pthread_mutex_destroy(&d->death_lock);
	pthread_mutex_destroy(&d->print_lock);
	i = 0;
	while (i < d->nbr_of_philos)
	{
		pthread_mutex_destroy(&d->forks[i]);
		pthread_mutex_destroy(&d->philos[i].meal_lock);
		i++;
	}
	n_philo = d->nbr_of_philos;
	join_threads(d, n_philo);

}
