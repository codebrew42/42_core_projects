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

# 241211

## what I did
- init and cleanup table[ok]

## to do
- learn how to write (c42_new, c42_update)
- simulate dining
- try visualizing
- write makefile

## to learn. think about 
- how to display status? with usleep
- is it necessary to have s_table to store or the pointers?
- Makefile


# 241212

## what I did
- changed .h (struct) -> adjust other .c files [ing]
why? since only one param is allowed in the pthread_create

## things to remember
- when you use a new func like "pthread_create", u need to check
param in advance, so that you don't need to adjust/change .h or structure!


## 241216

## what I did
- try to understnad mutex, thread and their role

## to do
- to write .c files again considering mutex lock and unlock

## ref
https://github.com/dpetrosy/42-Philosophers/tree/master

# 241218
## ref
https://raidho.tistory.com/141

https://jiwon.oopy.io/2c8294ad-8bd9-4ad6-a2e0-ab62e79801fd\


# 241219
## what I did
- rewriting again

## to do
- to print result on the terminal