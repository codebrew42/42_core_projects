#ifndef PHILO_H
# define PHILO_H

#include <pthread.h> //pthread*
#include <string.h> //memset
#include <stdio.h> //printf
#include <stdlib.h> //malloc, free
#include <unistd.h> //usleep
#include <sys/time.h> //gettimeofday
#include <limits.h>

#define LEFT(id, n) (id)
#define RIGHT(id, n) ((id + 1) % n)
typedef	struct s_arg
{
	int					number_of_philosophers;
	int					time_to_die;	//time_to_*: in millisec
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
}	t_arg;

typedef	struct s_philo
{
	int					id;
	long				last_meal_time;
	int					has_died;
	int					time_to_die;
	pthread_t			thread;
	struct s_philo		*next_philo;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t		*forks;
	t_philo				*philos;
	t_arg				*args;
}	t_table;

//philo.c

//table.c
t_philo			*init_philo(t_arg *arg);
void			cleanup_table(t_table *t);
void			init_mutex(t_table *t, int n_forks, t_arg *a);
t_table			*init_table(t_arg *a);

//parsing.c
void			save_to_arg(t_arg arg, int flag, char *src, int src_len);
int				get_args(t_arg	*arg, char **s);
int				validate_args(int *arr);

//display.c
long long		get_current_time(void);
void			display_status(char *status, int philo_id, long long timestamp);
void			exit_on_error(char *s);
void			display_warning(char *s);

//utils.c
void			join_threads(t_table *t);
int				char_to_int(char c);
int				ft_strlen(char *s);
int				ft_simple_atoi(char *s);

//debuc.c  //rm
void			*display_id(void *i); //maybe no need to rm!
void			print_arg(t_arg *arg);
void			print_arr(int *arr);
void			check_functions(t_arg *arg, t_philo *p);

#endif
