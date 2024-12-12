#include "../includes/philo.h"

t_philo		*init_philo(t_arg *arg)
{
	int				n_philos;
	t_philo			*philos_head;
	t_philo			*current;
	int				i;

	if (!arg)
		exit_on_error("Arguments are not properly savd");
	n_philos = arg->number_of_philosophers;
	philos_head = malloc(n_philos * sizeof(t_philo));
	if (!philos_head)
		exit_on_error("Malloc failed");
	current = philos_head;
	while (current && i <= n_philos)
	{
		current->id = i;
		current->last_meal_time = 0;
		current->has_died = 0;
		if (i < n_philos)
			current->next_philo = current + 1;
		else
			current->next_philo = philos_head;
		current++;
		i++;
	}
	return (philos_head);
}

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
		pthread_mutex_destroy(&t->forks[i]);
		i++;
	}
	free(t->args);
	free(t->forks);
}

void		init_mutex(t_table *t, int n_forks, t_arg *a)
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
			exit_on_error("Mutex initialization failed");
		}
		i++;
	}
}

t_table		*init_table(t_arg *a)
{
	int					n_forks;
	int					i;
	t_table				*t;

	if (!a)
		exit_on_error("Arguments not properly saved");
	n_forks = a->number_of_philosophers;
	t->forks = malloc(n_forks * sizeof(pthread_mutex_t));
	if (!t->forks)
	{
		free(a);
		exit_on_error("Malloc in table.c failed");
	}
	init_mutex(t, n_forks, a);
	t->args = a;
	return (t);
}
