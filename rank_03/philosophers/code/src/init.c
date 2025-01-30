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

uint64_t	str_to_uint64(char *s);
int			init_mutexes(t_data **d, int n_philos);
int			allocate_mem_to_ptrs(t_data **d, int n_philos);
int			parse_input(t_data **d, char **s);
int			init_data(char **s, t_data **d);

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

int	init_mutexes(t_data **d, int n_philos)
{
	int			i;

	i = -1;
	pthread_mutex_init(&(*d)->death_lock, NULL);
	pthread_mutex_init(&(*d)->print_lock, NULL);
	while (++i < n_philos)
	{
		if (pthread_mutex_init(&(*d)->fork_lock[i], NULL))
		{
			destroy_n_mutexes((*d)->fork_lock, i);
			return (1);
		}
	}
	i = -1;
	while (++i < n_philos)
	{
		if (pthread_mutex_init(&(*d)->philos[i].meal_lock, NULL))
		{
			destroy_n_mutexes((*d)->fork_lock, n_philos);
			while (--i >= 0)
				pthread_mutex_destroy(&(*d)->philos[i].meal_lock);
			return (1);
		}
	}
	return (0);
}

int	allocate_mem_to_ptrs(t_data **d, int n_philos)
{
	(*d)->fork_lock = malloc(sizeof(pthread_mutex_t) * n_philos);
	(*d)->philos = malloc(sizeof(t_philo) * n_philos);
	(*d)->routine_thread = malloc(sizeof(pthread_t) * n_philos);
	if (!(*d)->fork_lock || !(*d)->philos || !(*d)->routine_thread)
		return (1);
	return (0);
}

int	parse_input(t_data **d, char **s)
{
	(*d)->nbr_of_philos = (size_t)str_to_uint64(s[0]);
	(*d)->time_to_die = str_to_uint64(s[1]);
	(*d)->time_to_eat = str_to_uint64(s[2]);
	(*d)->time_to_sleep = str_to_uint64(s[3]);
	if (s[4])
		(*d)->max_mealtime = str_to_uint64(s[4]);
	else
		(*d)->max_mealtime = 0;
	if ((*d)->nbr_of_philos == 0 || (*d)->time_to_die == 0
		|| (*d)->time_to_eat == 0 || (*d)->time_to_sleep == 0)
		return (1);
	return (0);
}

int	init_data(char **s, t_data **d)
{
	int			n_philos;

	*d = malloc(sizeof(t_data));
	if (!*d)
		return (print_err_msg("Malloc failed"));
	if (parse_input(d, s))
		return (print_err_msg_and_free("Invalid input", d));
	n_philos = (*d)->nbr_of_philos;
	if (allocate_mem_to_ptrs(d, n_philos))
		return (print_err_msg_and_free("Malloc failed", d));
	if (init_mutexes(d, n_philos))
		return (print_err_msg_and_free("Mutex init failed", d));
	(*d)->start_time = get_current_time();
	(*d)->nbr_of_full_philos = 0;
	(*d)->dead_philo_id = 0;
	while (--n_philos >= 0)
	{
		(*d)->philos[n_philos].id = n_philos + 1;
		(*d)->philos[n_philos].meal_count = 0;
		(*d)->philos[n_philos].last_meal_time = (*d)->start_time;
		(*d)->philos[n_philos].data = *d;
	}
	return (0);
}
