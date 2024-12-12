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



// int			simulation_should_continue(t_philo *p)
// {
// 	return (1);
// }

// int		take_forks(t_philo *p, t_table *t)
// {
// 	return (0);
// }

// void		put_down_forks(t_philo *p, t_table *t)
// {
// 	return ;
// }
/**
void	simulate_philo(t_philo *philo) 
	while (!simulation_should_stop())  //condition (!)
		think(philo);
		if (take_forks(philo)) 
			eat(philo);
			put_down_forks(philo);
			sleep_philo(philo);
}*/
void		simulate_philo(t_philo *p, t_table *t) //or just arg instead of t_table
{
	while (simulation_should_continue(p))
	{
		display_status("is thinking", p->id, 100); //change 100
	}
	if (take_forks(p, t))
	{
		display_status("is eating", p->id, t->args->time_to_eat); //change 100
		put_down_forks(p, t);
		display_status("is sleeping", p->id, t->args->time_to_sleep); //change 100
	}.

	then -> check_all_ate & check_any_death

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
		pthread_create(&current->thread, NULL, simulate_philo, &current);
		current = current->next_philo;
		i++;
	}
}
