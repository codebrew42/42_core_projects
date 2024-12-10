#include "../includes/philo.h"

int		is_space(char c)
{
	return (c == 32);
}

void	save_to_arg(t_arg arg, int flag, char *src, int src_len)
{
	int		i;
	int		res;
	int		temp;

	i = 0;
	while (src[i] && i < src_len)
	{
		temp = char_to_int(src[i]);
		res = res * 10 + temp;
		i++;
	}
}

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
int	get_args(t_arg	*arg, char **s)
{
	int		flag;
	int		res;
	int		arr[4];

	flag = 1;
	while (flag <= 4)
	{
		arr[flag - 1] = ft_simple_atoi(s[flag]);
		flag++;
	}
	validate_args(arr);
	arg->number_of_philosophers = arr[0];
	arg->time_to_die = arr[1];
	arg->time_to_eat = arr[2];
	arg->time_to_sleep = arr[3];
	return (0);
}
