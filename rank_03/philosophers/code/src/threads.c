#include "../includes/philo.h"

void	*monitor(void *arg);
void	*routine(void *arg);
void	join_threads(t_data *d, int n_philo);
void	launch_threads(t_data *d);

void	*monitor(void *arg)
{
	t_philo			*p;

	p = (t_philo *)arg;


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

void	launch_threads(t_data *d)
{
	int		i;
	int		n_philo;

	n_philo = d->number_of_philosophers;
	i = 0;
	while (i < n_philo)
	{
		if (pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]))
		{
			free_data(d);
			exit_on_error("pthread_create failed");
		}
		if (pthread_create(&d->philos[i].monitor_thread, NULL, monitor, &d->philos[i]))
		{
			free_data(d);
			exit_on_error("pthread_create failed");
		}
		i++;
	}
	join_threads(d, n_philo);
}
