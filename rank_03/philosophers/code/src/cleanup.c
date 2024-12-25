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

void		free_data(t_data **d);
void		destroy_mutex(t_data *d);

void	free_data(t_data **d)
{
	if (!d || !*d)
		return ;
	free((*d)->forks);
	free((*d)->philos);
	free((*d)->routine_thread);
	free(*d);
	*d = NULL;
}

void	destroy_mutex(t_data *d)
{
	int		i;

	pthread_mutex_destroy(&d->death_lock);
	pthread_mutex_destroy(&d->print_lock);
	i = 0;
	while (i < d->nbr_of_philos)
	{
		pthread_mutex_destroy(&d->forks[i]);
		pthread_mutex_destroy(&d->philos[i].meal_lock);
		i++;
	}
}
