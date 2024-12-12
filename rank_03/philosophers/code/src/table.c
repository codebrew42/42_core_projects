#include "../includes/philo.h"

t_philo		*init_philo(t_data *d)
{
	int				n_philos;
	t_philo			*philos_head;
	t_philo			*current;
	int				i;

	n_philos = d->number_of_philosophers;
	philos_head = malloc(n_philos * sizeof(t_philo));
	if (!philos_head)
		exit_on_error("Malloc failed");
	d->philos = philos_head;
	current = philos_head;
	while (current && i <= n_philos)
	{
		current->id = i;
		current->last_meal_time = 0;
		current->has_died = 0;
		current->time_to_die = d->time_to_die;
		if (i < n_philos)
			current->next_philo = current + 1;
		else
			current->next_philo = philos_head;
		current++;
		i++;
	}
	return (philos_head);
}

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
}

void		init_table(t_data *d)
{
	int					n_forks;
	int					i;

    d->philos = init_philo(d);
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
