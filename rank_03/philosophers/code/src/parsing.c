#include "../includes/philo.h"

/**
 * @return 0-9 converted from param 'c', -1 if invalid
 */
int		digit_to_int(char c)
{
	int		res;

	if (c >= 48 && c <= 57)
		res = c - 48;
	else
		res = -1;
	return (res);
}

int		is_space(char c)
{
	return (c == 32);
}

void	save_to_arg(t_arg arg, int count, char *src, int src_len)
{
	int		i;
	int		res;
	int		temp;

	i = 0;
	while (src[i] && i < src_len)
	{
		temp = digit_to_int(src[i]);
		res = res * 10 + temp;
		i++;
	}
	if (count == 0)
		arg.number_of_philosophers = res;
	else if (count == 1)
		arg.time_to_die = res;
	else if (count == 2)
		arg.time_to_eat = res;
	else if (count == 3)
		arg.time_to_sleep = res;
}

/**
 * @brief copy each string, convert it to int, and save it to 't_arg'
 * 
 */
int	get_args(t_arg	arg, char *s)
{
	int		i;
	int		len;
	int		count;

	if (!s)
		return (1);
	i = 0;
	len = 0;
	count = 0;
	while (s[i])
	{
		len = 0;
		while (digit_to_int(s[i]) >= 0)
		{
			len++;
			i++;
		}
		if (len > 0 && (is_space(s[i]) || !s[i]))
		{
			save_to_arg(arg, count, s[i - len], len);
			count++;
		}
		i++;
	}
	return (0);
}
