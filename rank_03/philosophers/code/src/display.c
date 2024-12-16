#include "../includes/philo.h"

uint64_t get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
	{
		exit_on_error("gettimeofday() failed");
		return (0);
	}
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

void			display_status(char *status, int philo_id, long long timestamp)
{
	printf("%lld %d %s\n", timestamp, philo_id, status);
}

void			exit_on_error(char *s)
{
	printf("Error: %s!\n", s);
	exit(1);
}

void			display_warning(char *s)
{
	printf("Warning: %s might cause an unexpected behavior!\n", s);
}
