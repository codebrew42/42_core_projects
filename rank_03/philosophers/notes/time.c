

#include <sys/time.h>
#include <stdio.h>

//option 1
long long current_timestamp_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
}

//option 2
void	get_time(struct timeval *tv)
{
	gettimeofday(tv, NULL);
	printf("%ld sec\n", tv->tv_sec);
	printf("%ld microsec\n", tv->tv_usec);
	printf("%ld years passed since 1970\n", tv->tv_sec / 60 / 60 / 24/ 365);

}

int		main(void)
{
	struct timeval tv;
	
	get_time(&tv);
}