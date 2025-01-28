#include "../includes/philo.h"

uint64_t	display_status(t_data *d, char *s, int p_id);
uint64_t	get_current_time(void);
void		display_warning_message(char *s);
int			exit_on_error(char *s, int exit_flag);

uint64_t	display_status(t_data *d, char *s, int p_id)
{
	uint64_t	current_t;

	pthread_mutex_lock(&d->print_lock);
	current_t = get_current_time() - d->start_time;
	printf("%lu %d %s\n", current_t, p_id, s);
	pthread_mutex_unlock(&d->print_lock);
	return (current_t);
}

uint64_t	get_current_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	display_warning_message(char *s)
{
	printf("Warning: %s", s);
}

int	exit_on_error(char *s, int exit_flag)
{
	printf("Error: %s", s);
	if (exit_flag == 1)
		exit(1);
	return (1);
}