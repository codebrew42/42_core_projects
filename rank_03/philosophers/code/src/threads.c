/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:31:57 by jiepark           #+#    #+#             */
/*   Updated: 2025/01/29 16:31:58 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		*monitor(void *arg);
int			check_death(t_data *d, int n_philo);
int			check_end_condition(t_data *d, int n_philo);
int			launch_threads(t_data *d, int n_philo);
void		*routine(void *arg);

/** @brief "{time} {id} died" should be displayed in 10 sec if a philo dies
 *  @return id of the dead philosopher, -1 if no philosopher dies
 */
void	*monitor(void *arg)
{
	t_data			*d;
	int				n_philo;

	d = (t_data *)arg;
	n_philo = d->nbr_of_philos;
	while (1)
	{
		if (check_end_condition(d, n_philo))
			return (NULL);
		usleep(50);
	}
	return (NULL);
}

int	check_death(t_data *d, int n_philo)
{
	int		i;
	int		current_time;

	i = 0;
	while (i < n_philo)
	{
		pthread_mutex_lock(&d->philos[i].meal_lock);
		current_time = get_current_time() - d->start_time;
		if ((!d->philos[i].last_meal_time && current_time > d->time_to_die)
			|| (d->philos[i].last_meal_time > 0
				&& current_time - d->philos[i].last_meal_time > d->time_to_die))
		{
			pthread_mutex_unlock(&d->philos[i].meal_lock);
			pthread_mutex_lock(&d->death_lock);
			if (d->dead_philo_id == 0)
				d->dead_philo_id = i + 1;
			display_status(d, "died", d->dead_philo_id);
			pthread_mutex_unlock(&d->death_lock);
			return (1);
		}
		pthread_mutex_unlock(&d->philos[i].meal_lock);
		i++;
	}
	return (0);
}

int	check_end_condition(t_data *d, int n_philo)
{
	pthread_mutex_lock(&d->death_lock);
	if (d->dead_philo_id != 0)
	{
		pthread_mutex_unlock(&d->death_lock);
		return (1);
	}
	if (d->max_mealtime > 0 && d->nbr_of_philos_full >= n_philo)
	{
		pthread_mutex_unlock(&d->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&d->death_lock);
	return (check_death(d, n_philo));
}

/** @note always void *func(void *arg)
 * 
 */
void	*routine(void *arg)
{
	t_philo			*p;
	t_data			*d;
	int				n_philo;
	int				p_id;

	p = (t_philo *)arg;
	d = p->data;
	n_philo = d->nbr_of_philos;
	p_id = p->id;
	while (!check_end_condition(d, n_philo))
	{
		eating(p, d, p_id, n_philo);
		display_status(d, "is sleeping", p_id);
		usleep(p->data->time_to_sleep * 1000);
		display_status(d, "is thinking", p_id);
	}
	return (NULL);
}

/**
 * @return 1 if an error occurs, 0 if no error 
 */
int	launch_threads(t_data *d, int n_philo)
{
	int		i;
	int		j;

	i = 0;
	d->start_time = get_current_time();
	if (pthread_create(&d->monitor_thread, NULL, monitor, d))
		return (exit_on_error("pthread_create failed", 0));
	while (i < n_philo)
	{
		if (pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]))
		{
			while (i > 0)
				pthread_join(d->routine_thread[--i], NULL);
			pthread_join(d->monitor_thread, NULL);
			return (exit_on_error("pthread_create failed", 0));
		}
		i++;
	}
	return (0);
}
