#ifndef PHILO_H
# define PHILO_H

#include <pthread.h> //pthread*
#include <string.h> //memset
#include <stdio.h> //printf
#include <stdlib.h> //malloc, free
#include <unistd.h> //usleep
#include <sys/time.h> //gettimeofday
#include <limits.h>

typedef	struct s_arg
{
	int					number_of_philosophers;
	int					number_of_times_each_philosopher_must_eat;
	int					time_to_die;	//time_to_*: in millisec
	int					time_to_eat;
	int					time_to_sleep;
}	t_arg;

typedef	struct s_philo
{
	int					id;
	int					last_meal_time;
	pthread_t			thread;
	struct s_philo		*next_philo;
}	t_philo;

//for [table/backup]
// typedef struct s_forks
// {
// 	pthread_mutex_t		fork;
// 	int					id;
// 	int					in_use;
// 	struct s_forks		*next_fork;
// }	t_forks;

// typedef struct s_table
// {
// 	t_forks				*forks;
// 	t_philo				*philos;
// 	t_arg				*args;
// }	t_table;

typedef struct s_table
{
	pthread_mutex_t		*forks;
	t_philo				*philos;
	t_arg				*args;
}	t_table;

//src/philo.c
t_philo		*init_philo(t_arg *arg);

//src/table.c



//src/table.c [backup]
// void		cleanup_table(t_table *t);
// t_table		*init_table(t_arg *arg, t_philo *p);
// void		validate_forks(t_forks *f, t_arg *a);

//src/parsing.c
int		char_to_int(char c);
int		is_space(char c);
void	save_to_arg(t_arg arg, int flag, char *src, int src_len);
int		get_args(t_arg	*arg, char **s);
int		validate_args(int *arr);

//src/error.c
void	exit_on_error(char *s);
void	display_warning(char *s);
int		ft_strlen(char *s);
int		ft_simple_atoi(char *s);

//src/debuc.c  //rm
void	*display_id(void *i); //maybe no need to rm!
void	print_arg(t_arg *arg);
void	print_arr(int *arr);
void	check_functions(t_arg *arg, t_philo *p);

#endif
