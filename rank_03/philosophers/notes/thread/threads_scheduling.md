# thread scheduling

## why some functions are executed earlier?
### code1
```c
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
```
### result
```
c4b12c2% ./threads_prac2                                
Hello from thread no. 1
Hello from thread no. 2
Ends 1
Ends 2
```
- it is not like : hello -> ends, hello -> ends, but printing hello from each thread first.

### code2
```c
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
```

### result
```
4b12c2% ./threads_prac1                      
Jin
hi
Kazu
Kazu
Kazu
Kazu
Kazu
Kazu
Kazu
Kazu
Kazu
Kazu
Jin
hi
Jin
hi
Jin
hi
Jin
hi
Jin
hi
Jin
hi
Jin
hi
Jin
hi
Jin
hi

```
- the output from the `print_name` function appears before the outputs from `print_hi` and `print_jin`
- this can be attributed to the nature of thread scheduling and execution in a multi-threaded environment. 

- possible reasons

### 1. **Thread Scheduling and Preemption:**
   - When you call `pthread_create`, it creates the threads, but **it does not guarantee the order in which they will execute**. The OS's thread scheduler decides which thread to run based on various factors, including current CPU load, thread priority, and the scheduling algorithm in use.
   - Even though `print_hi` and `print_jin` are created first, the scheduler may choose to run `print_name` immediately after its creation, especially if it is ready to run and the other threads are not.

### 2. **Tight Loop in `print_name`:**
   - The `print_name` function has a loop that prints "Kazu" multiple times without any delay (like `usleep` or `sleep`). This means that once it starts executing, it can complete its task very quickly.
   - If `print_name` is scheduled to run right after its creation, it can finish its execution before the other threads have a chance to run significantly.

### 3. **Lack of Yielding:**
   - If the `print_hi` and `print_jin` functions are not yielding control back to the scheduler (e.g., by sleeping or waiting), they may not get a chance to run if the scheduler decides to keep running `print_name`.
   - In a tight loop without any blocking calls, the thread can consume CPU time until it completes, which can lead to it finishing before other threads have a chance to execute.

### 4. **Thread Priority:**
   - If the operating system's scheduler gives a higher priority to the thread running `print_name`, it may run that thread first, regardless of the order of creation. This can happen if the system is configured to prioritize certain threads or if the default scheduling policy favors certain types of threads.

### 5. **Context Switching:**
   - The operating system may perform context switching based on its scheduling policy. If `print_name` is ready to run and the CPU is available, it may be scheduled to run immediately, even if it was created after `print_hi` and `print_jin`.

### Example Scenario:
1. **Thread Creation:**
   - `pthread_create(&t1, NULL, print_hi, NULL)` creates the `print_hi` thread.
   - `pthread_create(&t2, NULL, print_jin, NULL)` creates the `print_jin` thread.
   - `pthread_create(&t3, NULL, print_name, "Kazu")` creates the `print_name` thread.

2. **Execution Order:**
   - The scheduler may decide to run `print_name` immediately after it is created, especially since it has a simple loop that can execute quickly.
   - If `print_name` starts executing and completes its loop before the scheduler gives CPU time to `print_hi` and `print_jin`, you will see "Kazu" printed first.

### Conclusion:
In summary, the order of thread execution is not strictly determined by the order of their creation. The operating system's thread scheduler plays a crucial role in deciding which thread runs at any given time, and factors like the tight loop in `print_name`, scheduling policies, and thread priorities can lead to the observed behavior where `print_name` outputs its results before the other threads. This is a common characteristic of multi-threaded programming and can lead to non-deterministic output.


## need of joining?
### code
```c
void	*display_id(void *i)
{
	int		nbr;

	nbr = *(int *)i;
	printf("thread no.[%d] is created\n", nbr);
	sleep(3);
	return (NULL);
}

t_philo		*init_philo(t_arg *arg)
{
	int				i;
	int				n_philos;
	t_philo			*philos;
	t_philo			*current;

	i = 1;
	n_philos = arg->number_of_philosophers;
	philos = malloc(n_philos * sizeof(t_philo));
	if (!philos)
		exit_on_error("Malloc failed");
	current = philos;
	while (current && i <= n_philos)
	{
		current->id = i;
		pthread_create(&current->thread, NULL, display_id, &current->id);
		if (i < n_philos)
			current->next_philo = current + 1;
		else
			current->next_philo = philos;
		current++;
		i++;
	}
	return (philos);
}

int main()
{
	t_philo *p;

	p = init_philo;
}
```
- without joining, some result of the display function will be missing,
it's because the caller(main) terminates without checking all the threads
are terminated.

### result
thread no.[10] is created
thread no.[7] is created