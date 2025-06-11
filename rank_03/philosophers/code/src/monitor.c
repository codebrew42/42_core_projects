/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:31:57 by jiepark           #+#    #+#             */
/*   Updated: 2025/01/29 16:31:58 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int			check_all_completed_meal(t_data *d, int n_philo);
int			check_and_print_a_philo_died(t_data *d, int p_id);
void		*monitor(void *arg);

int	check_all_completed_meal(t_data *d, int n_philo)
{
	pthread_mutex_lock(&d->death_lock);
	if (d->completed_meal_philo_count == d->nbr_of_philos)
	{
		d->dead_philo_id = -1;
		pthread_mutex_unlock(&d->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&d->death_lock);
	return (0);
}

int	check_and_print_a_philo_died(t_data *d, int id)
{
	if (check_philo_id(&d->philos[id - 1]))
		return (1);
	pthread_mutex_lock(&d->philos[id - 1].meal_lock);
	if (get_current_time() - d->philos[id - 1].last_meal_time >= d->time_to_die)
	{
		d->dead_philo_id = id;
		print_status_and_return_time(d, "died", id);
		pthread_mutex_unlock(&d->philos[id - 1].meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&d->philos[id - 1].meal_lock);
	return (0);
}

/**
 * @note structure : while(1)(usleep(500))->return (NULL);
 */
void	*monitor(void *arg)
{
	t_data		*d;
	int			i;

	d = (t_data *)arg;
	usleep(d->time_to_eat * 1000);
	while (1)
	{
		i = 0;
		while (i < d->nbr_of_philos)
		{
			if (check_and_print_a_philo_died(d, i + 1))
				return (NULL);
			i++;
			usleep(100);
		}
		if (check_all_completed_meal(d, d->nbr_of_philos))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
