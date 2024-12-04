#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void	func()
{
	struct timeval start;
	struct timeval end;
	long			requested_sleep;
	long			actual_sleep;

	requested_sleep = 200 * 1000; // 200 millisec = 200 000
	gettimeofday(&start, NULL);
	usleep(requested_sleep);
	gettimeofday(&end, NULL);
	actual_sleep = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

	printf("requested sleep: %ld microsec\n", requested_sleep);
	printf("actual sleep: %ld microsec\n", actual_sleep);
}

int	main()
{
	func();
	return (0);
}