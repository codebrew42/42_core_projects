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

int			init_multiple_mutexes(t_data **d, int n_philos);
int			init_single_mutexes(t_data **d);
int			allocate_mem_to_ptrs(t_data **d, int n_philos);
int			parse_input(t_data **d, char **s);
int			init_data(char **s, t_data **d);

int	init_multiple_mutexes(t_data **d, int n_philos)
{
	int			i;

	i = -1;
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
			while (--i >= 0)
				pthread_mutex_destroy(&(*d)->philos[i].meal_lock);
			destroy_n_mutexes((*d)->fork_lock, n_philos);
			return (1);
		}
	}
	return (0);
}

int	init_single_mutexes(t_data **d)
{
	int			i;

	i = -1;
	if (pthread_mutex_init(&(*d)->death_lock, NULL))
		return (1);
	if (pthread_mutex_init(&(*d)->print_lock, NULL))
		return (pthread_mutex_destroy(&(*d)->death_lock) + 1);
	if (pthread_mutex_init(&(*d)->eaters_lock, NULL))
	{
		pthread_mutex_destroy(&(*d)->death_lock);
		pthread_mutex_destroy(&(*d)->print_lock);
		return (1);
	}
	return (0);
}

int	allocate_mem_to_ptrs(t_data **d, int n_philos)
{
	(*d)->fork_lock = malloc(sizeof(pthread_mutex_t) * (n_philos + 1));
	(*d)->philos = malloc(sizeof(t_philo) * (n_philos + 1));
	(*d)->routine_thread = malloc(sizeof(pthread_t) * (n_philos + 1));
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
		return (print_err_msg_and_free("Invalid input", d));
	return (0);
}

int	init_data(char **s, t_data **d)
{
	int			n_philos;

	*d = malloc(sizeof(t_data));
	if (!*d)
		return (print_err_msg("Malloc failed"));
	if (parse_input(d, s))
		exit (1);
	n_philos = (*d)->nbr_of_philos;
	if (allocate_mem_to_ptrs(d, n_philos))
		return (print_err_msg_and_free("Malloc failed", d));
	if (init_single_mutexes(d) || init_multiple_mutexes(d, n_philos))
		return (print_err_msg_and_free("Mutex init failed", d));
	(*d)->completed_meal_philo_count = 0;
	(*d)->dead_philo_id = 0;
	(*d)->current_eaters = 0;
	(*d)->died_is_printed = 0;
	(*d)->max_eaters = n_philos - 1;
	while (--n_philos >= 0)
	{
		(*d)->philos[n_philos].id = n_philos + 1;
		(*d)->philos[n_philos].meal_count = 0;
		(*d)->philos[n_philos].data = *d;
	}
	return (0);
}
