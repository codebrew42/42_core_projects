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


# 241225

## what I did
- wrote threads.c

## todo
- understand more about 
	- mutex
	- deadlock prevention
	- race condition
	- thread scheduling
	- CPU usage optimization with this code

- improve my code
	- proper error handling
	- clean shutdown, check all the cases
	- debuggin capabilities
	- proper termination mechanism

-check valgrind with edge cases

- test with diff numbers of philos (edge cases: 1 phio, 200 philos)

#241226
## what I did
- compile : possible

## todo
- result(compiled philo) : not seen -> fix it

#241227
## what I am writing
- monitor function in threads.c

#241230
## what I did
- improved threads.c but not finished

## todo
- fix threads.c : the philo[4] and philo[5] are eating at the same time
- eating sequence is not random, it is always the same (1,3 -> 2,4,5)


## 250111
## issues to fix

: after joining, it still thinks
see : jin1@iMac-von-TJ code % ./obj/philo 5 800 200 200 10
...
4874 3 is thinking
4874 4 is sleeping
4882 1 is thinking
Successfully joined routine thread 0
Attempting to join routine thread 1
Successfully joined routine thread 1
Attempting to join routine thread 2
Successfully joined routine thread 2
Attempting to join routine thread 3
5079 4 is thinking
Successfully joined routine thread 3
Attempting to join routine thread 4
Successfully joined routine thread 4
Attempting to join monitor thread
Successfully joined monitor thread
jin1@iMac-von-TJ code % ls


#250128
## things to fix
[1]
c4b12c2% valgrind --tool=helgrind --log-file=helgrind7.log ./obj/philo 1 800 200 200
=> should not eat and should die

# 250202
# to fix
- print after death
- early death : 5 800 200 200