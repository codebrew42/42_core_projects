/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:03:39 by jiepark           #+#    #+#             */
/*   Updated: 2025/01/29 17:04:04 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *p, int p_id, int first_fork, int second_fork);
void	update_eating_status(t_philo *p, t_data *d, int p_id);
void	eating(t_philo *p, t_data *d, int p_id, int n_philo);

void	take_forks(t_philo *p, int p_id, int first_fork, int second_fork)
{
	if (p->data->nbr_of_philos == 1)
	{
		display_status(p->data, "has taken a fork", p_id);
		usleep(p->data->time_to_die * 1000);
		p->data->dead_philo_id = 1;
		pthread_mutex_lock(&p->data->print_lock);
		display_status(p->data, "died", p_id);
		pthread_mutex_unlock(&p->data->print_lock);
		return ;
	}
	pthread_mutex_lock(&p->data->forks[first_fork]);
	display_status(p->data, "has taken a fork", p_id);
	pthread_mutex_lock(&p->data->forks[second_fork]);
	display_status(p->data, "has taken a fork", p_id);
}

void	update_eating_status(t_philo *p, t_data *d, int p_id)
{
	pthread_mutex_lock(&p->meal_lock);
	p->last_meal_time = display_status(d, "is eating", p_id);
	p->meal_count++;
	if (p->meal_count != 0 && p->meal_count == d->max_mealtime)
	{
		pthread_mutex_lock(&d->death_lock);
		d->nbr_of_philos_full++;
		if (d->nbr_of_philos_full == d->nbr_of_philos)
		{
			d->dead_philo_id = -1;
			pthread_mutex_unlock(&d->death_lock);
			return ;
		}
		pthread_mutex_unlock(&d->death_lock);
	}
	pthread_mutex_unlock(&p->meal_lock);
}

void	eating(t_philo *p, t_data *d, int p_id, int n_philo)
{
	int		first_fork;
	int		second_fork;

	if (n_philo == 1)
	{
		take_forks(p, p_id, 0, 0);
		return ;
	}
	if (p_id % 2 == 0)
	{
		first_fork = p_id - 2;
		second_fork = p_id - 1;
	}
	else
	{
		first_fork = p_id - 1;
		second_fork = p_id;
	}
	take_forks(p, p_id, first_fork, second_fork);
	update_eating_status(p, d, p_id);
	usleep(p->data->time_to_eat * 1000);
	pthread_mutex_unlock(&p->data->forks[second_fork]);
	pthread_mutex_unlock(&p->data->forks[first_fork]);
}
