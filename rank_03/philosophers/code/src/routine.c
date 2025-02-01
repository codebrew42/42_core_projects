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
int			take_fork(t_philo *p, int index);
int			eat_and_monitor(t_philo *p);
void		*routine(void *arg);

void	log_meal(t_philo *p, uint64_t meal_time)
{
	pthread_mutex_lock(&p->meal_lock);
	p->last_meal_time = meal_time;
	p->meal_count++;
	pthread_mutex_lock(&p->data->death_lock);
	if (p->data->max_mealtime == p->meal_count)
		p->data->completed_meal_philo_count++;
	pthread_mutex_unlock(&p->data->death_lock);
	pthread_mutex_unlock(&p->meal_lock);
}

int	take_fork(t_philo *p, int index)
{
	pthread_mutex_lock(&p->data->fork_lock[index]);
	print_status_and_return_time(p->data, "has taken a fork", p->id);
	return (0);
}

void	set_forks(int p_id, int n_philos, int *first, int *second)
{
	int	temp;

	if (p_id == 1)
		*first = n_philos - 1;
	else
		*first = p_id - 2;
	*second = p_id - 1;
	if (p_id % 2 == 0)
	{
		temp = *first;
		*first = *second;
		*second = temp;
	}
}

int	eat_and_monitor(t_philo *p)
{
	int			first_fork;
	int			second_fork;
	t_data		*d;

	set_forks(p->id, p->data->nbr_of_philos, &first_fork, &second_fork);
	take_fork(p, first_fork);
	if (check_and_print_a_philo_died(p->data, p->id))
		(pthread_mutex_unlock(&p->data->fork_lock[first_fork]) + 1);
	take_fork(p, second_fork);
	if (!check_and_print_a_philo_died(p->data, p->id))
	{
		log_meal(p, print_status_and_return_time(p->data, "is eating", p->id));
		usleep(p->data->time_to_eat * 1000);
	}
	pthread_mutex_unlock(&p->data->fork_lock[second_fork]);
	pthread_mutex_unlock(&p->data->fork_lock[first_fork]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	while (1)
	{
		if (eat_and_monitor(p))
			return (NULL);
		// if (check_all_completed_meal(p->data, p->data->nbr_of_philos))
		// 	return (NULL);
		print_status_and_return_time(p->data, "is sleeping", p->id);
		usleep(p->data->time_to_sleep * 1000);
		if (check_and_print_a_philo_died(p->data, p->id)
			|| check_all_completed_meal(p->data, p->data->nbr_of_philos))
			return (NULL);
		print_status_and_return_time(p->data, "is thinking", p->id);
	}
	return (NULL);
}