#include "../includes/philo.h"

int			check_already_ended(t_data *d);
void		eating(t_philo *p, t_data *d, int p_id, int n_philo);
void		*monitor(void *arg);
void		*routine(void *arg);
int			launch_threads(t_data *d, int n_philo);

int	check_already_ended(t_data *d)
{
	pthread_mutex_lock(&d->death_lock);
	if (d->dead_philo_id != -1 || d->nbr_of_philos_full == d->nbr_of_philos)
	{
		printf("debugging D: dead_philo_id: %d, nbr_of_philos_full: %d\n", d->dead_philo_id, d->nbr_of_philos_full);
		pthread_mutex_unlock(&d->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&d->death_lock);
	return (0);
}

void	eating(t_philo *p, t_data *d, int p_id, int n_philo)
{
	int		first_fork;
	int		second_fork;

	if (check_already_ended(d))
		return ;
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
	if (p->meal_count == p->data->nbr_of_times_each_philo_must_eat)
		p->data->nbr_of_philos_full++;
	usleep(p->data->time_to_eat * 1000);
	pthread_mutex_unlock(&p->meal_lock);
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
		i = 0;
		while (i < n_philo)
		{
			if (check_already_ended(d))
				return (NULL);
			pthread_mutex_lock(&d->philos[i].meal_lock);
			if (d->philos[i].last_meal_time + d->time_to_die < get_current_time())
			{
				display_status(d, "died", i);
				d->dead_philo_id = i + 1;
				pthread_mutex_unlock(&d->philos[i].meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&d->philos[i].meal_lock);
			i++;
		}
		usleep(500);
	}	
	return (NULL);
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
		if (check_already_ended(d))
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

	i = 0;
	if (pthread_create(&d->monitor_thread, NULL, monitor, d))
		exit_on_error("pthread_create failed", 0);
	while (i < n_philo)
	{
		if (pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]))
			exit_on_error("pthread_create failed", 0);
		i++;
	}
	return (0);
}


