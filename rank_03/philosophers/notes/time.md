



## gettimeofday
### things to know
- 1 sec = 1 000 000 microsec
- 1 sec = 1 000 millisec

```c
struct timeval
{
	time_t			tv_sec; //sec fromo jan 1,1970
	susecondes_t	tv_usec; //microsec
}

int	gettimeofday(struct timeval *tv, struct timezone *tz)
{

}
```