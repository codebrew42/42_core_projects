#include "../includes/philo.h"

/** @note always void *func(void *arg)
 * 
 */
void	*routine(void *arg)
{
	t_philo *p = (t_philo *)arg;

	while (1)
	{
		//lock forks

		//eating

		//unlock forks

		//sleep

	}
	return (NULL);
}

void	join_threads(t_data *d)
{

	
}

void	launch_threads(t_data *d)
{
	int		i;
	int		n_philo;

	n_philo = d->number_of_philosophers;
	i = 0;
	while (i < n_philo)
	{
		pthread_create(&d->routine_thread[i], NULL, routine, &d->philos[i]);
		i++;
	}

}