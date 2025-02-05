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

void		wait_time(uint64_t wait_time);
void		log_meal(t_philo *p, uint64_t meal_time);
int			take_fork(t_philo *p, int index);
int			eat_and_monitor(t_philo *p);
void		*routine(void *arg);

void	wait_time(uint64_t wait_time)
{
	uint64_t	start;
	uint64_t	now;

	start = get_current_time();
	usleep(wait_time * 900);
	while (1)
	{
		now = get_current_time();
		if ((now - start) >= wait_time)
			break;
		//usleep(wait_time * 100);
		usleep(300);
	}
}

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
	while (1)
	{
		if (!pthread_mutex_lock(&p->data->fork_lock[index]))
		{
			print_status_and_return_time(p->data, "has taken a fork", p->id);
			return (0);
		}
		wait_time(50);
	}
	return (1);
}

void	set_forks(int p_id, int n_philos, int *first, int *second)
{
	int	temp;

	// if (p_id == n_philos)
	// {
	// 	*first = 0;
	// 	*second = p_id - 1;
	// }
	if (p_id % 2 == 0)
	{
		*first = (p_id - 1) % n_philos;
		*second = p_id % n_philos;
	}
	else
	{
		*first = p_id % n_philos;
		*second = (p_id - 1) % n_philos;
	}
	if (*first > *second)
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
	uint64_t	meal_time;

	set_forks(p->id, p->data->nbr_of_philos, &first_fork, &second_fork);
	take_fork(p, first_fork);
	take_fork(p, second_fork);
	meal_time = print_status_and_return_time(p->data, "is eating", p->id);
	log_meal(p, meal_time);
	wait_time(p->data->time_to_eat);
	pthread_mutex_unlock(&p->data->fork_lock[second_fork]);
	pthread_mutex_unlock(&p->data->fork_lock[first_fork]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	if (p->id % 2)
		usleep(3000);
	while (1)
	{
		if (eat_and_monitor(p))
			return (NULL);
		// if (check_all_completed_meal(p->data, p->data->nbr_of_philos))
		// 	return (NULL);
		print_status_and_return_time(p->data, "is sleeping", p->id);
		wait_time(p->data->time_to_sleep);
		if (check_and_print_a_philo_died(p->data, p->id)
			|| check_all_completed_meal(p->data, p->data->nbr_of_philos))
			return (NULL);
		print_status_and_return_time(p->data, "is thinking", p->id);
	}
	return (NULL);
}