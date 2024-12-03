#include "../includes/philo.h"


long long current_timestamp_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
}

// int main() 
// {
//     long long timestamp = current_timestamp_millis();
//     printf("Current timestamp in milliseconds: %lld\n", timestamp);
//     return 0;
// }

void	get_args(t_arg	*av, char *s)
{


}

int	main(int ac, char **av)
{
	t_arg	*av;

	if (ac != 2)
		return (1);
	get_args(av, av[1]);
	init_philo();
	init_table();
	
}