#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h> //for usleep
#include <stdlib.h>
#define MAX 10
#define MAX_2 100

void	*print_hi(void	*arg)
{
	int	i;

	i = 0;
	while (i < MAX)
	{
		printf("hi\n");
		i++;
		usleep(10000); //10000 = 10ms = 0.01s
	}
	return (NULL);
}


void	*print_jin(void	*arg)
{
	int	i;

	i = 0;
	while (i < MAX)
	{
		printf("Jin\n");
		i++;
		usleep(10000); //10000 = 10ms = 0.01s
	}
	return (NULL);
}

void	*print_name(void	*arg)
{
	int		i;
	char	*name;

	name = (char *)arg;

	i = 0;
	while (i < MAX)
	{
		printf("%c%c%c%c\n", name[0], name[1], name[2], name[3]);
		i++;
	}
	return (NULL);
}

void	*routine(void *arg)
{
	int *n;
	int	i;

	n = (int *)arg;
	i = 0;
	while (i < MAX_2)
	{
		(*n)++;
		i++;
	}
	return (NULL);
}

void	exit_on_error(int *n, int exit_code)
{
	free(n);
	exit(exit_code);
}


void	func_ver3(void)
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_t	t3;

	//if non-zero returned, is an err in creation
	if (pthread_create(&t1, NULL, print_hi, NULL))
		exit(1);
	if (pthread_create(&t2, NULL, print_jin, NULL))
		exit(1);
	if (pthread_create(&t3, NULL, print_name, "Kazu"))
		exit(1);

	if (pthread_join(t1, NULL))
		exit(1);
	if (pthread_join(t2, NULL))
		exit(1);
	if (pthread_join(t3, NULL))
		exit(1);
}

void	func_ver4(void)
{
	int			*n;
	pthread_t	t1;
	pthread_t	t2;

	n = malloc(sizeof(int));
	if (n == NULL)
		exit(1);
	*n = 0;
	if (pthread_create(&t1, NULL, routine, n))
		exit_on_error(n, 2);
	if (pthread_create(&t2, NULL, routine, n))
		exit_on_error(n, 2);

	if (pthread_join(t1, NULL))
		exit_on_error(n, 3);
	if (pthread_join(t2, NULL))
		exit_on_error(n, 3);
	printf("NUM: %d\n", *n);
}



//why 'jin' is printed before 'hi'? : that's because of the thread scheduling.
//thread1 and thread2 are created at the same time, so the scheduler decides which thread to run first.
//in this case, thread2 is decided to run first, so 'jin' is printed first.

// void	func_ver2(void)
// {
// 	pthread_t	thread1;
// 	pthread_t	thread2;

// 	pthread_create(&thread1, NULL, print_hi, NULL);
// 	pthread_create(&thread2, NULL, print_jin, NULL);
// 	pthread_join(thread1, NULL);
// 	pthread_join(thread2, NULL);
// }

void	func_ver1(void)
{
	print_hi(NULL);
	print_name("Jin");
}

int	main(void)
{
	func_ver4();
	return (0);
}
