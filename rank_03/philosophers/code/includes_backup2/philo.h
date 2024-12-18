#ifndef PHILO_H
# define PHILO_H

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

typedef	struct s_data
{
	size_t					number_of_philosophers;
	size_t					time_to_die;	//time_to_*: in millisec
	size_t					time_to_eat;
	size_t					time_to_sleep;
	size_t					number_of_times_each_philosopher_must_eat;
	int						philos_finished_meal;
	int						philo_dead;
	pthread_mutex_t			d_lock;
	pthread_mutex_t			*forks;
	struct s_philo			*philos;
}	t_data;

typedef	struct s_philo
{
	struct s_data		*data;
	int					id;
	long				last_meal_time;
	size_t				death_timestamp;
	pthread_mutex_t		p_lock;
	pthread_t			thread;
	struct s_philo		*next_philo;
}	t_philo;

//display.c
long long		get_current_time(void);
void			display_status(char *status, int philo_id, long long timestamp);
void			exit_on_error(char *s);
void			display_warning(char *s);

//main.c
//parsing.c
int				validate_args(int *arr);
int				get_args(t_data *data, char **s);

//table.c
t_philo			*init_philo(t_data *d);
void			cleanup_table(t_data *d);
void			init_mutex(t_data *d, int n_forks);
void			init_table(t_data *d);

//utils.c
void			join_threads(t_data *d);
int				char_to_int(char c);
int				ft_strlen(char *s);
int				ft_simple_atoi(char *s);

//rm_debuc.c  //rm
void			*display_id(void *i); //maybe no need to rm!
void			print_arg(t_data *arg);
void			print_arr(int *arr);
void			check_functions(t_data *arg, t_philo *p);

#endif
