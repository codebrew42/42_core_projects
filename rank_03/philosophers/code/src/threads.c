#include "../includes/philo.h"

void		display_status(char *s, int p_id);
uint64_t	get_current_time(void);
void	*monitor(void *arg);
void	*routine(void *arg);
void	join_threads(t_data *d, int n_philo);
int		launch_threads(t_data *d, int n_philo);

void		display_status(char *s, int p_id)
{
	uint64_t	current_t;

	current_t = get_current_time();
	printf("%u %d %s", current_t, p_id, s);
}

uint64_t	get_current_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/** @brief "{time} {id} died" should be displayed in 10 seconds if a philosopher dies
 *  @return id of the dead philosopher, -1 if no philosopher dies
 */
void	*monitor(void *arg)
{
	t_data			*d;
	int				i;
	int				n_philo;

	d = (t_data *)arg;
	n_philo = d->number_of_philosophers;
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

	p = (t_philo *)arg;
	n_philo = p->data->number_of_philosophers;
	while (1)
	{
		//{1}lock forks
		pthread_mutex_lock(&p->data->forks[RIGHT(p->id, n_philo)]);
		pthread_mutex_lock(&p->data->forks[LEFT(p->id, n_philo)]);
		//{2}eat
		pthread_mutex_lock(&p->meal_lock);
			//should i check again? if any philo died?
		p->last_meal_time = get_current_time();
		p->meal_count++;
		display_status("is eating", p->id);
		usleep();
		pthread_mutex_unlock(&p->meal_lock);
		//{3}unlock forks
		pthread_mutex_unlock(&p->data->forks[RIGHT(p->id, n_philo)]);
		pthread_mutex_unlock(&p->data->forks[LEFT(p->id, n_philo)]);

		//{4}sleep
	}
	return (NULL);
}

void	join_threads(t_data *d, int n_philo)
{
	int		i;

	i = 0;
	while (i < n_philo)
	{
		if (pthread_join(&d->routine_thread[i], NULL))
		{
			free_data(d);
			exit_on_error("pthread_join failed", 1);
		}
		if (pthread_join(&d->philos[i].monitor_thread, NULL))
		{
			free_data(d);
			exit_on_error("pthread_join failed", 1);
		}
		i++;
	}
}

/**
 * @return 1 if an error occurs, 0 if no error 
 */
int	launch_threads(t_data *d, int n_philo)
{
	int		i;
	int		dead_philo_id;

	i = 0;
	while (i < n_philo)
	{
		if (pthread_create(&d->philos[i].monitor_thread, NULL, monitor, &d->philos[i]))
			exit_on_error("pthread_create failed", 0);
		dead_philo_id = d->dead_philo_id;
		if (dead_philo_id != -1)
		{
			display_status("died", dead_philo_id);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		if (pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]))
			exit_on_error("pthread_create failed", 0);
		i++;
	}
	return (0);
}
