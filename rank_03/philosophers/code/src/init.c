#include "../includes/philo.h"


int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

/**
 * @brief the number given as a param is always greater than 0
 */
uint64_t		str_to_uint64(char *s)
{
	long	res;
	long	temp;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			exit_on_error("Parameter should be positive number.", 1);
		temp = s[i] - 48;
		res = res * 10 + temp;
		i++;
	}
	if (res > INT_MAX)
		return (-1);
	return ((uint64_t)res);
}

int		init_philo_and_pthread(t_data **d, int n_philos)
{
	int	i;

	pthread_mutex_init(&(*d)->death_lock, NULL);
	(*d)->forks = malloc(sizeof(pthread_mutex_t) * n_philos);
	(*d)->philos = malloc(sizeof(pthread_mutex_t) * n_philos);
	(*d)->routine_thread = malloc(sizeof(pthread_t) * n_philos);
		(*d)->philos = malloc(sizeof(t_philo) * n_philos);

	if (!(*d)->forks || !(*d)->philos || !(*d)->routine_thread || !(*d)->philos)
		exit_on_error("Malloc failed.", 0);
	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_init(&(*d)->forks[i], NULL);
		pthread_mutex_init(&(*d)->philos[i], NULL);
		i++;
	}
	if (!(*d)->philos)
		exit_on_error("Malloc failed.", 0);


	return (0);

}

int		init_data(char **s, t_data **d)
{
	int			n_philos;

	*d = malloc(sizeof(t_data));
	if (!*d)
		exit_on_error("Malloc failed.");
	(*d)->number_of_philosophers = (size_t)str_to_uint64(s[0]);
	n_philos = (*d)->number_of_philosophers;
	(*d)->time_to_die = str_to_uint64(s[1]);
	(*d)->time_to_eat = str_to_uint64(s[2]);
	(*d)->time_to_sleep = str_to_uint64(s[3]);
	(*d)->number_of_times_each_philosopher_must_eat = str_to_uint64(s[4]);
	(*d)->every_philo_has_eaten = 0;
	(*d)->any_philo_dead = 0;
	if (init_philo_and_pthread(d, n_philos))
	{
		free_data(d);
		exit(1);
	}
	return (0);
}
