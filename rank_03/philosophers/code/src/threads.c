#include "../includes/philo.h"

void		eating(t_philo *p, t_data *d, int p_id, int n_philo);
void		*monitor(void *arg);
void		*routine(void *arg);
int			check_end_condition(t_data *d, int n_philo);
int			launch_threads(t_data *d, int n_philo);

void	take_forks(t_philo *p, int p_id, int first_fork, int second_fork)
{
	pthread_mutex_lock(&p->data->forks[first_fork]);
	display_status(p->data, "has taken a fork", p_id);
	pthread_mutex_lock(&p->data->forks[second_fork]);
	display_status(p->data, "has taken a fork", p_id);
}

void	eating(t_philo *p, t_data *d, int p_id, int n_philo)
{
	int		first_fork;
	int		second_fork;

	if (p_id % 2 == 0)
	{
		first_fork = p_id - 2;
		second_fork = p_id - 1;
	}
	else
	{
		first_fork = p_id - 1;
		second_fork = p_id;
	}
	take_forks(p, p_id, first_fork, second_fork);
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
		usleep(100);
	}
	return (NULL);
}

int	check_end_condition(t_data *d, int n_philo)
{
	int		i;
	int		current_time;

	i = 0;
	while (i < n_philo)
	{
		pthread_mutex_lock(&d->philos[i].meal_lock);
		current_time = get_current_time() - d->start_time;
		if (d->philos[i].meal_count > 0 &&
			d->philos[i].last_meal_time + d->time_to_die < current_time)
		{
			pthread_mutex_unlock(&d->philos[i].meal_lock);
			pthread_mutex_lock(&d->death_lock);
			d->dead_philo_id = i;
			pthread_mutex_unlock(&d->death_lock);
			return (1);
		}
		pthread_mutex_unlock(&d->philos[i].meal_lock);
		i++;
	}
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
	while (i < n_philo)
	{
		if (pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]))
			return (exit_on_error("pthread_create failed", 0));
		i++;
	}
	if (pthread_create(&d->monitor_thread, NULL, monitor, d))
		return (exit_on_error("pthread_create failed", 0));
	return (0);
}
