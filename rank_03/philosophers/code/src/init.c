/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:36:16 by jiepark          #+#    #+#              */
/*   Updated: 2024/12/25 20:36:16 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int			ft_strlen(char *s);
uint64_t	str_to_uint64(char *s);
void		init_elements(t_data **d, int n_philos);
void		allocate_memory(t_data **d, int n_philos);
void		init_data(char **s, t_data **d);

int	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * @brief the number given as a param is always greater than 0
 */
uint64_t	str_to_uint64(char *s)
{
	long	res;
	long	temp;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
		{
			return (0);
		}
		temp = s[i] - 48;
		res = res * 10 + temp;
		i++;
	}
	if (res > INT_MAX)
		return (0);
	return ((uint64_t)res);
}

//to avoid memleak, use "(*d)->philos[i].*"
void	init_elements(t_data **d, int n_philos)
{
	int			i;
	t_philo		*p;

	i = 0;
	p = (*d)->philos;
	while (i < n_philos)
	{
		pthread_mutex_init(&(*d)->forks[i], NULL);
		p[i].id = i;
		p[i].has_died = 0;
		p[i].meal_count = 0;
		p[i].last_meal_time = 0;
		p[i].death_timestamp = 0;
		pthread_mutex_init(&p[i].meal_lock, NULL);
		p[i].data = *d;
		i++;
	}
}

void	allocate_memory(t_data **d, int n_philos)
{
	(*d)->forks = malloc(sizeof(pthread_mutex_t) * n_philos);
	(*d)->philos = malloc(sizeof(t_philo) * n_philos);
	(*d)->routine_thread = malloc(sizeof(pthread_t) * n_philos);
	if (!(*d)->forks || !(*d)->philos || !(*d)->routine_thread)
	{
		free_data(d);
		exit_on_error("Malloc failed.", 1);
	}
}

void	init_data(char **s, t_data **d)
{
	int			n_philos;

	*d = malloc(sizeof(t_data));
	if (!*d)
		exit_on_error("Malloc failed.", 1);
	(*d)->nbr_of_philos = (size_t)str_to_uint64(s[0]);
	n_philos = (*d)->nbr_of_philos;
	if (n_philos > 200)
		display_warning_message("Number of philosophers is greater than 200");
	(*d)->time_to_die = str_to_uint64(s[1]);
	(*d)->time_to_eat = str_to_uint64(s[2]);
	(*d)->time_to_sleep = str_to_uint64(s[3]);
	(*d)->nbr_of_times_each_philo_must_eat = str_to_uint64(s[4]);
	if (!((*d)->nbr_of_philos) || !((*d)->time_to_sleep) || !((*d)->time_to_eat)
		|| !((*d)->nbr_of_times_each_philo_must_eat) || !((*d)->time_to_die))
	{
		free_data(d);
		exit_on_error("Invalid input.", 1);
	}
	(*d)->every_philo_has_eaten = 0;
	(*d)->dead_philo_id = -1;
	pthread_mutex_init(&(*d)->death_lock, NULL);
	pthread_mutex_init(&(*d)->print_lock, NULL);
	allocate_memory(d, n_philos);
	init_elements(d, n_philos);
}