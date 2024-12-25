#include "../includes/philo.h"

void		eating(t_philo *p, int p_id, int n_philo);
void		*monitor(void *arg);
void		*routine(void *arg);
int			launch_monitor_threads(t_data *d, int n_philo);
int			launch_routine_threads(t_data *d, int n_philo);

void	eating(t_philo *p, int p_id, int n_philo)
{
	pthread_mutex_lock(&p->data->forks[RIGHT(p_id, n_philo)]);
	display_status("has taken a fork", p_id);
	pthread_mutex_lock(&p->data->forks[LEFT(p_id, n_philo)]);
	display_status("has taken a fork", p_id);

	pthread_mutex_lock(&p->meal_lock);
	p->last_meal_time = get_current_time();
	display_status("is eating", p_id);
	p->meal_count++;
	usleep(p->data->time_to_eat * 1000);
	pthread_mutex_unlock(&p->meal_lock);

	pthread_mutex_unlock(&p->data->forks[RIGHT(p_id, n_philo)]);
	pthread_mutex_unlock(&p->data->forks[LEFT(p_id, n_philo)]);
}

/** @brief "{time} {id} died" should be displayed in 10 sec if a philo dies
 *  @return id of the dead philosopher, -1 if no philosopher dies
 */
void	*monitor(void *arg)
{
	t_data			*d;
	int				i;
	int				n_philo;

	d = (t_data *)arg;
	n_philo = d->nbr_of_philos;
	i = 0;
	while (i < n_philo && !d->dead_philo_id)
	{
		pthread_mutex_lock(&d->philos[i].meal_lock);
		if (d->philos[i].last_meal_time + d->time_to_die < get_current_time())
		{
			d->dead_philo_id = i;
			pthread_mutex_unlock(&d->philos[i].meal_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&d->philos[i].meal_lock);
		i++;
	}
	return (NULL);
}

/** @note always void *func(void *arg)
 * 
 */
void	*routine(void *arg)
{
	t_philo			*p;
	int				n_philo;
	int				p_id;

	p = (t_philo *)arg;
	n_philo = p->data->nbr_of_philos;
	while (1)
	{
		p_id = p->id;
		eating(p, p_id, n_philo);
 
		display_status("is sleeping", p_id);
		usleep(p->data->time_to_sleep * 1000);

		display_status("is thinking", p_id);
		usleep(1000); //check time
	}
	return (NULL);
}

/**
 * @return 1 if an error occurs, 0 if no error 
 */
int	launch_routine_threads(t_data *d, int n_philo)
{
	int		i;

	i = 0;
	while (i < n_philo)
	{
		if (pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]))
			exit_on_error("pthread_create failed", 0);
		i++;
	}
	return (0);
}

/**
 * @return 1 if an error occurs, 0 if no error 
 */
int	launch_monitor_threads(t_data *d, int n_philo)
{
	int		i;
	int		dead_philo_id;

	while(!d->dead_philo_id)
	{
		i = 0;
		while (i < n_philo)
		{
			if (pthread_create(&d->philos[i].monitor_thread, NULL, monitor, &d->philos[i]))
				exit_on_error("pthread_create failed", 0);
			pthread_mutex_lock(&d->death_lock);
			dead_philo_id = d->dead_philo_id;
			pthread_mutex_unlock(&d->death_lock);
			if (dead_philo_id != -1)
			{
				display_status("died", dead_philo_id);
				return (1);
			}
			if (d->every_philo_has_eaten == 1)
				return (1);
			i++;
		}
	}
	return (0);
}
