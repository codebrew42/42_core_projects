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


#ifndef		PHILO_H
# define	PHILO_H
#include <pthread.h> //pthread*
#include <string.h> //memset
#include <stdio.h> //printf
#include <stdlib.h> //malloc, free
#include <unistd.h> //usleep
#include <sys/time.h> //gettimeofday
#include <limits.h>
#include <stdint.h> //uint64_t

#define LEFT(id, n) (id)
#define RIGHT(id, n) ((id + 1) % n)
typedef struct s_data
{
	size_t					nbr_of_philos;
	uint64_t				time_to_die;	//time*: millisec
	uint64_t				time_to_eat;
	uint64_t				time_to_sleep;
	uint64_t				start_time;
	size_t					nbr_of_times_each_philo_must_eat;
	int						every_philo_has_eaten;
	int						dead_philo_id;
	pthread_mutex_t			death_lock;		//protects access to dead_philo_id
	pthread_mutex_t			print_lock;		//protects access to printf in philo_routine
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
	//int					is_eating;
	uint64_t			last_meal_time;
	uint64_t			death_timestamp; //maybe remove
	pthread_mutex_t		meal_lock; //protects access to meal_count&last_meal_time
	struct s_data		*data;
}	t_philo;


//	init.c
int			ft_strlen(char *s);
uint64_t	str_to_uint64(char *s);
void		init_elements(t_data **d, int n_philos);
void		allocate_memory(t_data **d, int n_philos);
void		init_data(char **s, t_data **d);

//	threads.c
void		eating(t_philo *p, t_data *d, int p_id, int n_philo);
void		*monitor(void *arg);
void		*routine(void *arg);
int			launch_monitor_threads(t_data *d, int n_philo);
int			launch_routine_threads(t_data *d, int n_philo);

//	terminate.c
void		join_threads(t_data *d, int n_philo);
void		free_data(t_data **d);
void		destroy_mutex(t_data *d);

//	display.c
uint64_t	display_status(t_data *d, char *s, int p_id);
uint64_t	get_current_time(void);
void		display_warning_message(char *s);
int			exit_on_error(char *s, int exit_flag);


#endif
