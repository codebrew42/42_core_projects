#include "../includes/philo.h"

void	display_status(char *s, int philo_id, int time)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("%ld.%06ld %d %s", tv.tv_sec, tv.tv_usec, philo_id, s);
	usleep(time);
}

void	exit_on_error(char *s)
{
	printf("Error: %s!\n", s);
	exit(1);
}

void	display_warning(char *s)
{
	printf("Warning: %s might cause an unexpected behavior!\n", s);
}
