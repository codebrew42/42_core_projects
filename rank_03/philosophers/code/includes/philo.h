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
	int						nbr_of_full_philos;
	int						dead_philo_id;
	pthread_mutex_t			death_lock;
	pthread_mutex_t			print_lock;
	pthread_mutex_t			*fork_lock;
	pthread_t				monitor_thread;
	struct s_philo			*philos;
	pthread_t				*routine_thread;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					meal_count;
	uint64_t			last_meal_time;
	pthread_mutex_t		meal_lock;
	struct s_data		*data;
}	t_philo;

/* * * * * init.c * * * */
int			init_data(char **s, t_data **d);
int			init_mutexes(t_data **d, int n_philos);
int			allocate_mem_to_ptrs(t_data **d, int n_philos);
int			parse_input(t_data **d, char **s);

/* * * * * monitor.c * * * */

/* * * * * print.c * * * */
uint64_t	print_status_and_return_current_time(t_data *d, char *s, int p_id);
uint64_t	get_current_time(void);
int			print_err_msg(char *s);
int			print_err_msg_and_free(char *s, t_data **d);

/* * * * * routine.c * * * */

/* * * * * terminate.c * * * */
int			join_threads(t_data *d, int n_philo);
void		free_data(t_data **d);
int			destroy_n_mutexes(pthread_mutex_t *p, int max_i);
int			destroy_all_mutexes(t_data *d, int n_philos);

#endif
