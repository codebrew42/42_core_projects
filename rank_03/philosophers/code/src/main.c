#include "../includes/philo.h"

int main(int ac, char **av)
{
    t_data *data;
    t_philo *philos = NULL;

    if (ac != 5)
        exit_on_error("Number of arguments should be 5");

    //[1] malloc for data and save arguments
    data = malloc(sizeof(t_data));
    if (!data)
        exit_on_error("Malloc for data in main failed");
    get_args(data, av);

    //[2] init philosophers and mutexes
	init_table(data);

    //[3] init and simulate dining 
    // start_dining_simulation(data);

    //[4] debug
    check_functions(data, philos); //rm

    //[5] join threads
    //join_threads(data);

    //[6] cleanup and terminate
    // Cleanup mutexes
    for (int i = 0; i < data->number_of_philosophers; i++)
        pthread_mutex_destroy(&data->forks[i]);
    free(data->forks);
    free(data);

    display_status("is eating", 1, get_current_time());
    return (0);
}