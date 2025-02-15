/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:03:39 by jiepark           #+#    #+#             */
/*   Updated: 2025/01/29 17:04:04 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void		log_meal(t_philo *p, uint64_t meal_time);
void		set_forks(int p_id, int n_philos, int *first, int *second);
int			eat_and_monitor(t_philo *p);
int			check_philo_id(t_philo *p);
void		*routine(void *arg);

void	log_meal(t_philo *p, uint64_t meal_time)
{
	pthread_mutex_lock(&p->meal_lock);
	p->last_meal_time = meal_time;
	p->meal_count++;
	if (p->data->max_mealtime == p->meal_count)
	{
		pthread_mutex_unlock(&p->meal_lock);
		pthread_mutex_lock(&p->data->death_lock);
		p->data->completed_meal_philo_count++;
		pthread_mutex_unlock(&p->data->death_lock);
		return ;
	}
	pthread_mutex_unlock(&p->meal_lock);
}

void	set_forks(int p_id, int n_philos, int *first, int *second)
{
	if (p_id % 2 != 0)
	{
		*first = (p_id - 1) % n_philos;
		*second = p_id % n_philos;
	}
	else
	{
		*first = p_id % n_philos;
		*second = (p_id - 1) % n_philos;
	}
}

int	eat_and_monitor(t_philo *p)
{
	int			first;
	int			second;
	uint64_t	meal_time;

	set_forks(p->id, p->data->nbr_of_philos, &first, &second);
	pthread_mutex_lock(&p->data->fork_lock[first]);
	print_status_and_return_time(p->data, "has taken a fork", p->id);
	if (check_philo_id(p))
	{
		pthread_mutex_unlock(&p->data->fork_lock[first]);
		return (1);
	}
	pthread_mutex_lock(&p->data->fork_lock[second]);
	print_status_and_return_time(p->data, "has taken a fork", p->id);
	if (check_philo_id(p))
	{
		pthread_mutex_unlock(&p->data->fork_lock[second]);
		pthread_mutex_unlock(&p->data->fork_lock[first]);
		return (1);
	}
	log_meal(p, print_status_and_return_time(p->data, "is eating", p->id));
	usleep(p->data->time_to_eat * 1000);
	pthread_mutex_unlock(&p->data->fork_lock[second]);
	pthread_mutex_unlock(&p->data->fork_lock[first]);
	return (0);
}

int	check_philo_id(t_philo *p)
{
	pthread_mutex_lock(&p->data->death_lock);
	if (p->data->dead_philo_id != 0)
	{
		pthread_mutex_unlock(&p->data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&p->data->death_lock);
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*p;
	uint64_t	start;

	p = (t_philo *)arg;
	if (p->id % 2 != 0)
		usleep(p->data->time_to_sleep * 500);
	while (1)
	{
		if (check_and_print_a_philo_died(p->data, p->id))
			return (NULL);
		if (eat_and_monitor(p))
			return (NULL);
		print_status_and_return_time(p->data, "is sleeping", p->id);
		usleep(p->data->time_to_sleep * 1000);
		start = get_current_time();
		print_status_and_return_time(p->data, "is thinking", p->id);
		if (p->data->nbr_of_philos % 2 == 0)
			continue ;
		else
		{
			while (get_current_time() - start < p->data->time_to_sleep)
				usleep(p->data->time_to_sleep / 100);
		}
	}
	return (NULL);
}
