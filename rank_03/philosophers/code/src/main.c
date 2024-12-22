#include "../includes/philo.h"
void	display_warning_message(char *s);
int		exit_on_error(char *s, int exit_flag);

void	display_warning_message(char *s)
{
	printf("Warning: %s\n", s);
}

int		exit_on_error(char *s, int exit_flag)
{
	printf("Error: %s\n", s);
	if (exit_flag == 1)
		exit(1);
	return (1);
}
int		main(int ac, char **av)
{
	t_data		*d;
	int			n_philo;
	if (ac != 6)
		return (exit_on_error("Number of arguments should be 5", 1));

	//init var
	init_data(&av[1], &d);

	//launch thread
	n_philo = d->number_of_philosophers;
	launch_threads(d, n_philo);

	//free and destroy
	join_threads(d, n_philo);
	destroy_mutex(d);
	free_data(&d);

}