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
	size_t					number_of_philosophers;
	uint64_t				time_to_die;	//time*: millisec
	uint64_t				time_to_eat;
	uint64_t				time_to_sleep;
	size_t					number_of_times_each_philosopher_must_eat;
	int						every_philo_has_eaten;
	int						dead_philo_id;
	pthread_mutex_t			death_lock;		//protects access to dead_philo_id
	pthread_mutex_t			print_lock;		//protects access to printf in philo_routine
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
	uint64_t			death_timestamp;
	pthread_mutex_t		meal_lock; //protects access to meal_count&last_meal_time
	pthread_t			monitor_thread;
}	t_philo;


//	init.c
int			ft_strlen(char *s);
uint64_t	str_to_uint64(char *s);
void		init_elements(t_data **d, int n_philos);
void		allocate_memory(t_data **d, int n_philos);
void		init_data(char **s, t_data **d);

//	threads.c
void		*monitor(void *arg);
void		*routine(void *arg);
int			launch_threads(t_data *d, int n_philo);
void		join_threads(t_data *d, int n_philo);

//	main.c
void		display_warning_message(char *s);
int			exit_on_error(char *s, int exit_flag);

//	cleanup.c
void		free_data(t_data **d);
void		destroy_mutex(t_data *d);

#endif
