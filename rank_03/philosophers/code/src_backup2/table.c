#include "../includes/philo.h"

//check
void		init_philo(t_philo **philos_head, t_data *d, int n_philos)
{
	t_philo			*current;
	int				i;

	*philos_head = malloc(n_philos * sizeof(t_philo));
	if (!*philos_head)
		exit_on_error("Malloc failed");
	d->philos = *philos_head;
	current = *philos_head;
	i = 1;
	while (current && i <= n_philos)
	{
		current->data = d;
		current->id = i;
		current->last_meal_time = 0;
		current->death_timestamp = d->time_to_die;
		if (i < n_philos)
			current->next_philo = current + 1;
		else
			current->next_philo = NULL;
		pthread_mutex_init(current->p_lock);
		current++;
		i++;
	}
}

//check
void		cleanup_table(t_data *d)
{
	int			i;
	int			n_forks;

	if (!d)
		return ;
	n_forks = d->number_of_philosophers;
	i = 0;
	//to fix
	while (i < n_forks)
	{
		pthread_mutex_destroy(&d->forks[i]);
		i++;
	}
	free(d->forks);
	free(d->philos);
}

void		init_mutex(t_data *d, int n_forks)
{
	int		i;

	i = 0;
	while (i < n_forks)
	{
		if (pthread_mutex_init(&d->forks[i], NULL))
		{
			while (--i)
				pthread_mutex_destroy(&d->forks[i]);
			free(d->forks);
			free(d->philos);
			exit_on_error("Mutex initialization failed");
		}
		i++;
	}
	pthread_mutex_init(&d->d_lock, NULL);
}

void		init_table(t_data *d)
{
	int					n_forks;
	int					i;

	init_philo(&d->philos, d, d->number_of_philosophers);
	d->forks = malloc(sizeof(pthread_mutex_t) * d->number_of_philosophers);
	if (!d->forks)
		exit_on_error("Malloc for forks failed");
	i = 0;
	while (i < d->number_of_philosophers)
	{
		pthread_mutex_init(&d->forks[i], NULL);
		i++;
	}
}
