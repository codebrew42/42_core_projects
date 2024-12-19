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
	int						any_philo_dead;
	pthread_mutex_t			death_lock;
	pthread_mutex_t			*forks;
	struct s_philo			*philos;
	pthread_t				*routine_thread;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					has_died;
	int					meal_count;
	int					is_eating;
	uint64_t			last_meal_time;
	uint64_t			death_timestamp;
	pthread_t			sub_routine_thread;
	struct s_philo		*next_philo;
}	t_philo;


//	init
/**
 * 1. init data
 * 2. init philo
 */


#endif