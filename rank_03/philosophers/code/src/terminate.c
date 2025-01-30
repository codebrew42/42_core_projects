/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:35:52 by jiepark          #+#    #+#              */
/*   Updated: 2024/12/25 20:35:52 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		join_threads(t_data *d, int n_philo);
void	free_data(t_data **d);
int		destroy_n_mutexes(pthread_mutex_t *p, int max_i);
int		destroy_all_mutexes(t_data *d, int n_philos);

int	join_threads(t_data *d, int n_philo)
{
	return (1);
}

/**
 * @note why using double pointer?: to NULL after freeing
 */
void	free_data(t_data **d)
{
	if (!d)
		return ;
	if ((*d)->fork_lock)
		free((*d)->fork_lock);
	if ((*d)->philos)
		free((*d)->philos);
	if ((*d)->routine_thread)
		free((*d)->routine_thread);
	free(*d);
	*d = NULL;
}

/**
 * @return	0 on error, 1 on success by using return value of
 * 			pthread_mutex_destroy
 * @note	max_i will be skipped, assuming it's not created
 * 			when coding: use "&p[o]" instead of "p"
**/
int	destroy_n_mutexes(pthread_mutex_t *p, int max_i)
{
	int	ret;

	if (!p || max_i <= 0)
		return (1);
	if (max_i == 1)
	{
		return (pthread_mutex_destroy(&p[0]));
	}
	while (max_i >= 0)
	{
		ret = pthread_mutex_destroy(&p[max_i]);
		if (!ret)
			return (ret);
		max_i--;
	}
	return (0);
}

int	destroy_all_mutexes(t_data *d, int n_philos)
{
	int	ret;

	if (pthread_mutex_destroy(&d->death_lock))
		return (1);
	if (pthread_mutex_destroy(&d->print_lock))
		return (1);
	while (--n_philos >= 0)
	{
		if (pthread_mutex_destroy(&d->philos[n_philos].meal_lock))
			return (1);
		if (pthread_mutex_destroy(&d->fork_lock[n_philos]))
			return (1);
	}
	return (0);
}

