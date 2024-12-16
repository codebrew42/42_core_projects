#include "../includes/philo.h"

void	*display_id(void *i)
{
	int		nbr;

	nbr = *(int *)i;
	printf("thread no.[%d] is created\n", nbr);
	usleep(400);
	return (NULL);
}

void	print_arg(t_data *arg)
{
	printf("arg[1] nbr_of_phi: %d\n", arg->number_of_philosophers);
	//printf("number_of_times_each...: %zu\n", arg.number_of_times_each_philosopher_must_eat);
	printf("arg[2] tt_die: %d\n", arg->time_to_die);
	printf("arg[3] tt_eat: %d\n", arg->time_to_eat);
	printf("arg[4] tt_sleep: %d\n", arg->time_to_sleep);
}

void	print_arr(int *arr)
{
	int i = 0;

	while (arr[i])
	{
		printf("arr[%d]: %d\n", i, arr[i]);
		i++;
	}
}

void	check_functions(t_data *arg, t_philo *p)
{
	int		i;
	t_philo	*tmp;

	i = 1;
	//[1] char_to_int
	printf("............checking starts............\n");
	printf("\t* * * * 1st func: \"char_to_int\" * * * *\n");
	printf("char to int(0) : %d\n", char_to_int('5'));
	printf("char to int(9) : %d\n", char_to_int('a'));
	//[2] print arg
	printf("\t* * * *2nd func: \"print_arg\" * * * *\n");
	print_arg(arg); //rm
	printf("............checking ends............\n");
	// [3] init phil
	printf("\t* * * *3rd func: \"init_philos\" * * * *\n");
	tmp = p;
	while(i <= arg->number_of_philosophers)
	{
		printf("philo [%d] has id [%d]\n", i, tmp->id);
		tmp++;
		i++;
	}
}