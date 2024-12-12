/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:56:43 by jiepark           #+#    #+#             */
/*   Updated: 2024/12/10 18:56:44 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int			simulation_should_continue(t_table *t)
// {
// 	int					i;
// 	struct timeval		tv;
// 	t_philo				*p;

// 	i = 1;
// 	p = t->philos;
// 	while (i <= t->args->number_of_philosophers && p)
// 	{
// 		get_current_time();
// 		if (tv.tv_sec - p->last_meal_time >= t->args->time_to_die)
// 		{
// 			display_status("died", p->id, get_current_time());
// 			cleanup_table(t);
// 			exit_on_error(NULL);
// 		}
// 		p = p->next_philo;
// 	}
// 	return (1);
// }

int			simulation_should_continue(t_philo *p)
{
	int					i;
	long long			current_time;
	t_philo				*p;

	i = 1;
	if (!p)
		return (0);
	current_time = get_current_time();
	if (current_time - p->last_meal_time >= p->time_to_die)
	{
		display_status("died", p->id, get_current_time());
		return (0);
	}
	return (1);
}

int			take_forks(t_philo *p, t_table *t)
{
	int			id;
	int			n_philos;
	
	id = p->id;
	n_philos = t->args->number_of_philosophers;
	if (id != n_philos)
	{
		pthread_mutex_lock(&t->forks[LEFT(id, n_philos)]);
		display_status("has taken a fork", p->id, get_current_time());
		pthread_mutex_lock(&t->forks[RIGHT(id, n_philos)]);
		display_status("has taken a fork", p->id, get_current_time());
	}
	else
	{
		pthread_mutex_lock(&t->forks[RIGHT(id, n_philos)]);
		display_status("has taken a fork", p->id, get_current_time());
		pthread_mutex_lock(&t->forks[LEFT(id, n_philos)]);
		display_status("has taken a fork", p->id, get_current_time());
	}
	return (1);
}

void		put_down_forks(t_philo *p, t_table *t)
{
	int			id;
	int			n_philos;
	
	id = p->id;
	n_philos = t->args->number_of_philosophers;
	if (id != n_philos)
	{
		pthread_mutex_unlock(&t->forks[LEFT(id, n_philos)]);
		pthread_mutex_unlock(&t->forks[RIGHT(id, n_philos)]);
	}
	else
	{
		pthread_mutex_unlock(&t->forks[RIGHT(id, n_philos)]);
		pthread_mutex_unlock(&t->forks[LEFT(id, n_philos)]);
	}
}
/**
void	simulate_philo(t_philo *philo) 
	while (!simulation_should_stop())  //condition (!)
		think(philo);
		if (take_forks(philo)) 
			eat(philo);
			put_down_forks(philo);
			sleep_philo(philo);
}*/
void		*simulate_philo(t_philo *p) //or just arg instead of t_table
{
	int		id;

	id = p->id;

	while (simulation_should_continue(p))
	{
		display_status("is thinking", id, get_current_time()); //change 500
		if (take_forks(p, t))
		{
			display_status("is eating", id, get_current_time());
			usleep(t->args->time_to_eat);
			put_down_forks(p, t);
			display_status("is sleeping", id, get_current_time());
			usleep(t->args->time_to_sleep);
		}
	}
	return (NULL);
}

void		start_dining_simulation(t_table *t)
{
	t_philo			*p;
	t_philo			*current;
	int				i;
	int				n_forks;

	//[3] init philo & check "a", "p"
	p = init_philo(t->args);
	if (!p)
		exit_on_error("Malloc in philos.c failed");
	t->philos = p;
	i = 1;
	current = p;
	n_forks = t->args->number_of_philosophers;
	while (i <= n_forks)
	{
		pthread_create(&current->thread, NULL, &simulate_philo, &current); // only one param
		current = current->next_philo;
		i++;
	}
	join_threads(t);
}
