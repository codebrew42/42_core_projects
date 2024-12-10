#include "../includes/philo.h"

t_table		*init_table(t_arg *a, t_philo *p)
{
	int					n_forks;
	int					i;
	t_table				*t;

	if (!a)
		exit_on_error("Arguments not properly saved");
	n_forks = a->number_of_philosophers;
	t = malloc(sizeof(t_table));
	if (!t)
		exit_on_error("Malloc in table.c failed");
	t->forks = malloc(n_forks * sizeof(pthread_mutex_t));
	if (!t->forks)
	{
		free(t->forks);
		exit_on_error("Malloc in table.c failed");
	}
	i = 0;
	while (i < n_forks)
	{
		if (pthread_mutex_init(&t->forks[i], NULL))
		{
			//destroy on error
			while (--i)
			{
				pthread_mutex_destroy(&t->forks[i]);
			}
			free(t->forks);
			free(t);
		}
		i++;
	}
	t->args = a;
	t->philos = p;
	return (t);
}
