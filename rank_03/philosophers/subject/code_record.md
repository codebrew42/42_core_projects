# 241203
## what I learned
- threads : pthread_create -> pthread_join (detach is also an option)
- timestamps

## todo
- handle arg:  parse av -> save to nbr of philo... (ING)
- init philo/table (X)
- write .h and Makefile (X)
- plan (X)
- watch this youtube video(OK)
	-https://www.youtube.com/watch?v=UGQsvVKwe90&ab_channel=JamshidbekErgashev from [10:37]

# 241204
## what I learned
- threads
	- pthread_create
	- pthread_join : does not affect the schedule of other threads
- parsing

## todo
- parsing
	- check if all args are properly saved to "t_arg"
- init philo/table 
- write .h and Makefile 

## prob
- gcc : didnt compile
- clang : is ok
-> check if its ok to compile with clang

#241210

## what I did
- parsing, init philo, init table(ing, almost finished)

- parsing.c [ok]
- philos.c [ok]
- table.c [ing] 

## todo
- learn how to write (c42_new, c42_update)
- need to check: table.c
- to understand behaviors which comes after init

```c
pthread_mutex_t forks[NUM_PHILOSOPHERS];

// In the philosopher function:
void *philosopher(void *arg)
{
    int id = *(int*)arg;
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    while (1)
    {
        // Try to pick up forks
        pthread_mutex_lock(&forks[left_fork]);
        if (pthread_mutex_trylock(&forks[right_fork]) != 0)
        {
            // Couldn't get right fork, release left fork and try again
            pthread_mutex_unlock(&forks[left_fork]);
            continue;
        }

        // Eat
        printf("Philosopher %d is eating\n", id);

        // Put down forks
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);
    }

    return NULL;
}

```