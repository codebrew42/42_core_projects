#include "../includes/philo.h"

long long		get_current_time(t_table *t)
{
	struct timeval		tv;
	long long			res;

	if (gettimeofday(&tv, NULL))
	{
		cleanup_table(t);
		exit_on_error("Getting timestamp failed");
	}
	res = tv.tv_sec * 1000LL + tv.tv_usec * 1000;
	return (res);
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
