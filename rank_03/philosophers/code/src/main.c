#include "../includes/philo.h"


int	main(int ac, char **av)
{
	t_arg		*arg;
	t_philo		*philos;
	t_table		*table;

	if (ac != 5)
		exit_on_error("Number of arguments should be 5");

	//[1] malloc for *arg* and save data
	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit_on_error("Malloc for arg in main failed");
	get_args(arg, av);

	//[2] init philo 
	philos = init_philo(arg);

	//[3] init table & check "a", "p"
	table = init_table(arg, philos);


	check_functions(arg, philos); //rm
	cleanup_table(table);
}