/**reason for backup
 * 
 * 	it says, it doesn't need "int in_used", "int id" for forks
 */


#include "../includes/philo.h"


void		validate_forks(t_forks *f, t_arg *a)
{
	int				i;
	int				n_forks;
	t_forks			*current;

	i = 0;
	n_forks = a->number_of_philosophers;
	current = f;
	while (current && i < n_forks)
	{
		pthread_mutex_init(&(f->fork), NULL);
		f->id = i;
		i++;
		current = f->next_fork;
	}
	printf("Forks properly validated\n");
}



t_table		*init_table(t_arg *arg, t_philo *p)
{
	t_table		*t;
	int			n_forks;

	if (!arg)
		exit_on_error("Invalid Arguments");
	if (!p)
		exit_on_error("Philisophers are not properly initialized");
	t = malloc(sizeof(t_table));
	if (!t)
		exit_on_error("Malloc failed");
	t->args = arg;
	t->philos = p;
	//malloc fork
	n_forks = arg->number_of_philosophers;
	t->forks = malloc(n_forks * sizeof(t_forks));
	if (!t->forks)
	{
		cleanup_table(t);
		exit_on_error("Malloc failed");
	}
	validate_forks(t->forks, arg);
	return (t);
}
