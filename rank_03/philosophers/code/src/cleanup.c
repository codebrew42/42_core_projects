#include "../includes/philo.h"

void		free_data(t_data **d);
void		destroy_mutex(t_data *d);

void		free_data(t_data **d)
{
	if (!d || !*d)
		return ;
	free((*d)->forks);
	free((*d)->philos);
	free((*d)->routine_thread);
	free(*d);
	*d = NULL;
}
void		destroy_mutex(t_data *d)
{
	int		i;

	pthread_mutex_destroy(&d->death_lock);
	pthread_mutex_destroy(&d->print_lock);
	i = 0;
	while (i < d->number_of_philosophers)
	{
		pthread_mutex_destroy(&d->forks[i]);
		pthread_mutex_destroy(&d->philos[i].meal_lock);
		i++;
	}
}
