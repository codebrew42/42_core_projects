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

//	init.c
uint64_t	str_to_uint64(char *s);
void		init_elements(t_data **d, int n_philos);
void		allocate_memory(t_data **d, int n_philos);
void		init_data(char **s, t_data **d);

// eating.c
void		take_forks(t_philo *p, int p_id, int first_fork, int second_fork);
void		eating(t_philo *p, t_data *d, int p_id, int n_philo);
void		update_eating_status(t_philo *p, t_data *d, int p_id);

//	threads.c
void		*monitor(void *arg);
void		*routine(void *arg);
int			check_end_condition(t_data *d, int n_philo);
int			check_death(t_data *d, int n_philo);
int			launch_threads(t_data *d, int n_philo);

//	terminate.c
int			join_threads(t_data *d, int n_philo);
void		free_data(t_data **d);
void		destroy_mutex(t_data *d);

//	display.c
uint64_t	display_status(t_data *d, char *s, int p_id);
uint64_t	get_current_time(void);
int			exit_on_error(char *s, int exit_flag);

#endif
