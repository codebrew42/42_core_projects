#include "../includes/philo.h"


// int main() 
// {
//     long long timestamp = current_timestamp_millis();
//     printf("Current timestamp in milliseconds: %lld\n", timestamp);
//     return 0;
// }


}

int	main(int ac, char **av)
{
	t_arg	*arg;

	if (ac != 2)
		return (1);
	get_args(arg, av[1]);
	init_philo();
	init_table();
	
}