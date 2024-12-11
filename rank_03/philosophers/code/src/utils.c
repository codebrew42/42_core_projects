#include "../includes/philo.h"

void		join_threads(t_table *t)
{
	int				i;
	int				n_philos;
	t_philo			*current;

	n_philos = t->args->number_of_philosophers;
	i = 0;
	current = t->philos;
	while (i <= n_philos && current)
	{
		pthread_join(current->thread, NULL);
		current = current->next_philo;
	}
}

/**
 * @note char(48) = 0, char(57) = 9
 * @return -1, if invalid <=> 0-9, if converted
 */
int		char_to_int(char c)
{
	int		res;

	res = -1;
	if (c >= 48 && c <= 57)
		res = c - 48;
	return (res);
}

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

/**
 * @brief the number given as a param is always greater than 0
 */
int		ft_simple_atoi(char *s)
{
	long	res;
	long	temp;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		temp = char_to_int(s[i]);
		if (temp == -1)
			exit_on_error("Parameter should be digits(also excluding '-')");
		res = res * 10 + temp;
		i++;
	}
	if (res > INT_MAX)
		return (-1);
	return ((int)res);
}