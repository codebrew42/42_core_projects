/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:07:35 by jiepark          #+#    #+#              */
/*   Updated: 2024/12/25 20:07:35 by jiepark         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_data
{
	size_t					nbr_of_philos;
	uint64_t				time_to_die;
	uint64_t				time_to_eat;
	uint64_t				time_to_sleep;
	uint64_t				start_time;
	size_t					max_mealtime;
	int						nbr_of_philos_full;
	int						dead_philo_id;
	pthread_mutex_t			death_lock;
	pthread_mutex_t			print_lock;
	pthread_t				monitor_thread;
	pthread_mutex_t			*forks;
	struct s_philo			*philos; 
	pthread_t				*routine_thread;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					has_died;
	int					meal_count;
	uint64_t			last_meal_time;
	pthread_mutex_t		meal_lock;
	struct s_data		*data;
}	t_philo;



#endif
