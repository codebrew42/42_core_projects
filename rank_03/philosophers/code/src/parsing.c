#include "../includes/philo.h"


/**
 * @return 1 on error and invalid arg, 0 on success
 */
int	validate_args(int	*arr)
{
	int		i;
	int		len;

	if (!arr)
		return (1);
	if (arr[0] <= 0)
		exit_on_error("av[1] equl to 0");
	if (arr[0] > 200)
		display_warning("Number of philo greater than 200");
	i = 1;
	while (i <= 3)
	{
		if (arr[i] <= 0)
			exit_on_error("av[2]-av[4] equl to 0");
		if (arr[i] < 60)
			display_warning("Time shorter than 60ms");
		i++;
	}
	return (0);
}

/**
 * @brief copy each string, convert it to int, and save it to 't_arg'
 * @return 1 on error, 0 on success
 */
int get_args(t_data *data, char **s)
{
	int flag;
	int arr[4];

	flag = 1;
	while (flag <= 4)
	{
		arr[flag - 1] = ft_simple_atoi(s[flag]);
		flag++;
	}
	validate_args(arr);
	data->number_of_philosophers = arr[0];
	data->time_to_die = arr[1];
	data->time_to_eat = arr[2];
	data->time_to_sleep = arr[3];
	return (0);
}
