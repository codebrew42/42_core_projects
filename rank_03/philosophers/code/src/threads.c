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
			break;
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

	p = (t_philo *)arg;
	while (1)
	{
		//lock forks
		pthread_mutex_lock
		//eating

		//unlock forks

		//sleep

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

int	launch_threads(t_data *d, int n_philo)
{
	int		i;

	i = 0;
	while (i < n_philo)
	{
		if (pthread_create(&d->philos[i].monitor_thread, NULL, monitor, &d->philos[i]))
			exit_on_error("pthread_create failed", 0);
		if (d->dead_philo_id != -1)
		{
			display_status("died", d->dead_philo_id);
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
