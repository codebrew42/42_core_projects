#include "../includes/philo.h"


void	free_data(t_data *d)
{
	if (!d)
		return ;
	

}

int		exit_on_error(char *s, int exit_flag)
{
	printf("Error: %s\n", s);
	if (exit_flag == 1)
		exit(1);
	return (1);
}

int		main(int ac, char **av)
{
	t_data		*d;

	if (ac != 5)
		return (exit_on_error("Number of arguments should be 5"));

	//init var
	if (init_data(av[1], &d))
		return (free_data(d));


	//launch thread


	//free and destroy


}