#include "../includes/philo.h"

void		eating(t_philo *p, t_data *d, int p_id, int n_philo);
void		*monitor(void *arg);
void		*routine(void *arg);
int			check_end_condition(t_data *d, int n_philo);
int			launch_threads(t_data *d, int n_philo);

void	eating(t_philo *p, t_data *d, int p_id, int n_philo)
{
	int		first_fork;
	int		second_fork;

	first_fork = RIGHT(p_id, n_philo);
	second_fork = LEFT(p_id, n_philo);
	if (p_id == n_philo)
	{
		first_fork = LEFT(p_id, n_philo);
		second_fork = RIGHT(p_id, n_philo);
	}
	pthread_mutex_lock(&p->data->forks[first_fork]);
	display_status(d, "has taken a fork", p_id);
	pthread_mutex_lock(&p->data->forks[second_fork]);
	display_status(d, "has taken a fork", p_id);

	pthread_mutex_lock(&p->meal_lock);
	p->last_meal_time = display_status(d, "is eating", p_id);
	p->meal_count++;
	pthread_mutex_unlock(&p->meal_lock);
	if (p->meal_count == d->nbr_of_times_each_philo_must_eat)
    {
        pthread_mutex_lock(&d->death_lock);
        d->nbr_of_philos_full++;
        pthread_mutex_unlock(&d->death_lock);
    }
	usleep(p->data->time_to_eat * 1000);
	pthread_mutex_unlock(&p->data->forks[second_fork]);
	pthread_mutex_unlock(&p->data->forks[first_fork]);
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
	while (1)
	{
		if (check_end_condition(d, n_philo))
			return (NULL);
		usleep(500);
	}	
	return (NULL);
}

int	check_end_condition(t_data *d, int n_philo)
{
	pthread_mutex_lock(&d->death_lock);
	if (d->dead_philo_id != 0 || d->nbr_of_philos_full >= n_philo)
	{
		pthread_mutex_unlock(&d->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&d->death_lock);
	return (0);
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
	while (1)
	{
		if (check_end_condition(d, n_philo))
			return (NULL);
		p_id = p->id;
		eating(p, d, p_id, n_philo);

		display_status(d, "is sleeping", p_id);
		usleep(p->data->time_to_sleep * 1000);

		display_status(d, "is thinking", p_id);
		//usleep(500 * 1000); //check time
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
	if (pthread_create(&d->monitor_thread, NULL, monitor, d))
		return (exit_on_error("pthread_create failed", 0));
	while (i < n_philo)
	{
		if (pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]))
		{
			// Need to join already created threads before returning
			while (i > 0)
				pthread_join(d->routine_thread[--i], NULL);
			pthread_join(d->monitor_thread, NULL);
			return (exit_on_error("pthread_create failed", 0));
		}
		i++;
	}
	return (0);
}
