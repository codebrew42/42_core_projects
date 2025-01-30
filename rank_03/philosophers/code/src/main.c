/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:36:11 by jiepark          #+#    #+#              */
/*   Updated: 2024/12/25 20:36:11 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		launch_threads(t_data *d, int n_philos);

void	display_all_philos_data_for_debug(t_data *d)
{
	int			i;

	printf(" * * * * *\n");
	printf("[1] data\n");
	printf("nbr_of_philos: %zu\n", d->nbr_of_philos);
	printf("time_to_die: %lu\n", d->time_to_die);
	printf("time_to_eat: %lu\n", d->time_to_eat);
	printf("time_to_sleep: %lu\n", d->time_to_sleep);
	printf("start_time: %lu\n", d->start_time);
	printf("max_mealtime: %zu\n", d->max_mealtime);
	printf("nbr_of_full_philos: %d\n", d->nbr_of_full_philos);
	printf("dead_philo_id: %d\n\n", d->dead_philo_id);
	printf(" * * * * *\n");
	printf("[2]Philosophers data\n");
	i = 0;
	while (i < d->nbr_of_philos)
	{
		printf("loop %d:Philosopher id[%d]\n", i, d->philos[i].id);
		printf("meal_count: %d\n", d->philos[i].meal_count);
		printf("last_meal_time: %lu\n\n", d->philos[i].last_meal_time);
		i++;
	}
	printf(" END * * * * *\n");
}

int	launch_threads(t_data *d, int n_philos)
{
	d->start_time = get_current_time();


}

int	main(int ac, char **av)
{
	t_data		*d;
	int			n_philos;

	if (ac != 5 && ac != 6)
		return (print_err_msg("Number of arguments is not 4 or 5"));
	init_data(&av[1], &d);
	//display_all_philos_data_for_debug(d); //rm
	n_philos = d->nbr_of_philos;
	//printf("current time %lu\n", get_current_time()); //rm
	//print_status_and_return_current_time(d, "start\n", 0); //rm
	launch_threads(d, n_philos);
	// join_threads();
	destroy_all_mutexes(d, n_philos);
	free_data(&d);
}
