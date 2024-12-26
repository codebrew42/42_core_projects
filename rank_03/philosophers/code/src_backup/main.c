#include "../includes/philo.h"


int	main(int ac, char **av)W
{
	t_arg		*arg;
	t_philo		*philos = NULL;
	t_table		*table;

	if (ac != 5)
		exit_on_error("Number of arguments should be 5");

	//[1] malloc for *arg* and save data
	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit_on_error("Malloc for arg in main failed");
	get_args(arg, av);

	//[2] init table 
	table = init_table(arg);

	//[3] init and simulate dining 
	// start_dining_simulation(table);

	//[5] debug
	check_functions(arg, philos); //rm

	// [5] join
	//join_threads(table);

	//[6] terminate
	cleanup_table(table);

	display_status("is eating", 1, get_current_time(table));
}