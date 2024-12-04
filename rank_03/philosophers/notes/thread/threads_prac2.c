#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	*routine(void *arg)
{
	printf("Hello from thread no. %s\n", (char *)arg);
	sleep(3);
	printf("Ends %s\n", (char *)arg);
	return (NULL);
}

int	main(int ac, char *av[])
{
	pthread_t		t1;
	pthread_t		t2;


	pthread_create(&t1, NULL, routine, "1");
	pthread_create(&t2, NULL, routine, "2");

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return (0);

}