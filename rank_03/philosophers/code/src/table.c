#include "../includes/philo.h"


void		cleanup_table(t_table *t)
{
	int			i;
	int			n_forks;
	t_table		*current;

	if (!t)
		return ;
	n_forks = t->args->number_of_philosophers;
	i = 0;
	//to fix
	while (i < n_forks && current)
	{
		current = t->forks[i];
		pthread_mutex_destroy(&t->forks->fork);
		i++;
	}
	free(t->philos);
	free(t->args);
	free(t->forks);
}

void		init_mutex(t_table *t, int n_forks, t_arg *a, t_philo *p)
{
	int		i;

	i = 0;
	while (i < n_forks)
	{
		if (pthread_mutex_init(&t->forks[i], NULL))
		{
			while (--i)
				pthread_mutex_destroy(&t->forks[i]);
			free(t->forks);
			free(a);
			free(p);
			exit_on_error("Mutex initialization failed");
		}
		i++;
	}
}

t_table		*init_table(t_arg *a, t_philo *p)
{
	int					n_forks;
	int					i;
	t_table				*t;

	if (!a)
		exit_on_error("Arguments not properly saved");
	if (!p)
		exit_on_error("Philos not properly saved");
	n_forks = a->number_of_philosophers;
	t->forks = malloc(n_forks * sizeof(pthread_mutex_t));
	if (!t->forks)
	{
		free(a);
		free(p);
		exit_on_error("Malloc in table.c failed");
	}
	init_mutex(t, n_forks, a, p);
	t->args = a;
	t->philos = p;
	return (t);
}
