#include "../includes/philo.h"

void	exit_on_error(char *s)
{
	printf("Error: %s!\n", s);
	exit(1);
}

void	display_warning(char *s)
{
	printf("Warning: %s might cause an unexpected behavior!\n", s);
}
