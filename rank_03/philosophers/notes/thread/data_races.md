# data races

## explanation (see **code** section)
- **data races** should be avoided in the programms
- happens because
	- multiple threads read and write to the same mem location
	- if you increment the same mem location on the different threads, you can lose some increment
		```
		Thread 1: Reads n = 500
		Thread 1: Calculates 500 + 1 = 501
		Thread 2: Reads n = 500 (before Thread 1 writes back!)
		Thread 1: Writes 501
		Thread 2: Calculates 500 + 1 = 501
		Thread 2: Writes 501
		```
	- if MAX is 1000000, you might expect *n to be 2000000 (1000000 increments from each thread). However, it can be less, since some increments are lost like above.


## code
```c
void	*routine(void *arg)
{
	int		*n;

	n = (int *)arg;
	while (i < MAX)
	{
		(*n)++;
		i++;
	}
}

void	func(void)
{
	int				*n;
	pthread_t		t1;
	pthread_t		t2;

	n = malloc(sizeof(int));
	if (!n)
		exit(1);
	*n = 0;
	print("AFTER CREATE&JOIN, NUM: %d", *n);
	if(pthread_create(&t1, NULL, routine, n))
		exit(1);
	if(pthread_create(&t2, NULL, routine, n))
		exit(1);

	if(pthread_join(t1, NULL))
		exit(1);
	if(pthread_join(t2, NULL))
		exit(2);
	print("AFTER CREATE&JOIN, NUM: %d", *n);
}

int		main(void)
{
	func();
}

```
### the result
```
c4b12c2% ./threads_prac1                      
BEFORE JOINING, NUM: 0
AFTER JOINING, NUM: 10136208
```
this resulting number varies

- why? each threads have diff speed.
(for example, at some point it can be like...)
- so it can be mixed up
```
					 thread1		 thread2
-get val from mem		2				2
-increment val			3				2
-write back to mem		3				2
```
## how to prevent data races ? mutex
### mutex
- to protect var, printf and so on.
- basically **locker** for some actions you want to take
- only after **unlock** the first thread, the second thread has the access to the locker
- do not forget to destroy after using

### how to use mutex
```c
typedef struct	s_data
{
	int					n;
	pthread_mutex_t		mutex;
}	t_data;

/**
 * @brief init "int" to 0, init mutex to "NULL"
 * */
t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit (1);
	data->n = 0;
	pthread_mutex_init(&data->mutex, NULL);
	return (data);
}

void	free_data(t_data *data)
{
	pthread_mute_destroy(&data->mutex); //destry mutex
	free(data);
}

void	*routine_with_mutex(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < MAX)
	{
		pthread_mutex_lock(&data->mutex); //locked
		(data->n)++;
		pthread_mutex_unlock(&data->mutex); //locked
		i++;
	}
	return (NULL);
}

int	func()
{
	t_data			*data;
	pthread_t		t1;
	pthread_t		t2;

	data = init_data(); //added
	if (pthread_create(&t1, NULL, routine, NULL));
		exit(1);
	if (pthread_create(&t2, NULL, routine, NULL));
		exit(1);

	if (pthread_join(t1, NULL))
		exit(1);
	if (pthread_join(t2, NULL))
		exit(1);
}

```

