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

t_philo		*init_philo(t_arg *arg)
{
	int				i;
	int				n_philos;
	t_philo			*philos;
	t_philo			*current;

	i = 1;
	if (arg)
		n_philos = arg->number_of_philosophers;
	philos = malloc(n_philos * sizeof(t_philo));
	if (!philos)
		exit_on_error("Malloc failed");
	current = philos;
	while (current && i <= n_philos)
	{
		current->id = i;
		pthread_create(&current->thread, NULL, display_id, &current->id);
		pthread_join(current->thread, NULL);
		if (i < n_philos)
			current->next_philo = current + 1;
		else
			current->next_philo = NULL;
		current++;
		i++;
	}
	return (philos);
}
