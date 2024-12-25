#include "../includes/philo.h"

void		display_status(char *s, int p_id);
uint64_t	get_current_time(void);

void	display_status(char *s, int p_id)
{
	uint64_t	current_t;

	current_t = get_current_time();
	printf("%u %d %s", current_t, p_id, s);
}

uint64_t	get_current_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}