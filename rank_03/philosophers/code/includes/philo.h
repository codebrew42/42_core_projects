#ifndef PHILO_H
# define PHILO_H

#include <pthread.h> //pthread*
#include <string.h> //memset
#include <stdio.h> //printf
#include <stdlib.h> //malloc, free
#include <unistd.h> //usleep
#include <sys/time.h> //gettimeofday

typedef	struct s_arg
{
	size_t		number_of_philosophers;
	size_t		number_of_times_each_philosopher_must_eat;
	size_t		time_to_die;	//time_to_*: in millisec
	size_t		time_to_eat;
	size_t		time_to_sleep;
}	t_arg;

typedef	struct s_philo
{
	int			id;
	pthread_t	thread;


}	t_philo;

typedef struct s_prog_data
{
	t_philo		philos;
	t_arg		args;

}	t_prog_data;


#endif
