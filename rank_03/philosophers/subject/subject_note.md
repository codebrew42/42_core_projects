# overview
## allowed external functions
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock

## visualizer
https://nafuka11.github.io/philosophers-visualizer/

## example code
https://github.com/MarkosComK/42-Philosophers
https://en.wikipedia.org/wiki/Dining_philosophers_problem

## to execute
```
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
- for example, `valgrind --tool=helgrind ./philo 5 800 200 300  5`
- [number_of_times_each_philosopher_must_eat] : if each **phil** eats 5 times, simulation stops
	- what's helgrind?
		- a tool for checking multithreaded programs for data races and other concurrency bugs
	- -g : for debugging information
	- -fsanitize=thread: for checking data races


### result
- [phil_result](./phil_result.png)

## philosophers
### definition
- each has a number (1 to **number_of_philosophers**)
- **phil(1)** sits next to **phil(**number_of_philosophers**)**
- **phil(N)** sits btw **phil(N-1)** and **phil(N+1)**  
(except **phil(1)** and **phil(N)**)
- cases
	- **number_of_philosophers** is 1
	- **number_of_philosophers** is even
	- **number_of_philosophers** is odd

### threads
- every **phil** is on other thread
- additional threads
	- why needed? since **phils** are not allowed to communicate with each other
	- need one additional thread : constantly checking if any **phil** dies (using **flag**)
	- might add one more thread : to check if all **phil**s have eaten enough (using **flag**)


### behaviors
- alternatively eat, think, or sleep
- while eating, not thinking nor sleeping and so on.
- taking forks : 
	- all **phils** take from right fork, except the last **phil**(**phil(N)**)

### rules : do
- every *phil* should eat
- every *phil* should avoid dying
- each *phil* should be a thread

### rules : don't
- *phil*s do not speak with each other
- *phil*s do not know if other *phil*s is about to die

## table
- a bowl of spagetti
- *forks*
	- as many as phil. (be careful: 1 *phil* also 1 *fork*)
	- phil. takes their right and left forks
	- To prevent *phil*s from duplicating forks, you should protect the forks state
with a mutex for each of them.
	- meaning that you should lock the mutex when a *phil* takes a fork and unlock it when done
	- *mutex* : 
		- *a synchronization primitive* that can be used to protect shared resources from concurrent access

## code rules
### directory
- mandatory : philo
- bonus : philo_bonus

### must have arguments
1. **number_of_philosophers** : nbr of *phil*s and *fork*s
2. **time_to_die** (in millisec.): if *phil*s didnt start eating in *time_to_die* since the beginning of their last meal or beginning of the simulation, they die
	- if the **phil**s number is even : time_to_die = time_to_eat + time_to_sleep + 10 (millisec)
	- if odd : time_to_die = time_to_eat * 2 + time_to_sleep + 10 (millisec)
		- at least double time_to_eat
3. **time_to_eat** (in millisec.) : the time it takes for *phil*s to eat. *phil*s hold two *fork*s during this time 
4. **time_to_sleep** (in millisec.) : the time *phil*s spend sleeping
5. [**number_of_times_each_philosopher_must_eat**] (optional) : if all *phil*s hav eaten at least *number_of_times_each_philosopher_must_eat* times, simulation stops. (if not specified, the simulation stops when a *phil* dies)

### Any state change of a *phil* must be formatted as follows:

```
timestamp_in_ms		phil_id		state
```
- **timestamp_in_ms** : the current timestamp in milliseconds since the beginning of the simulation
- **phil_id** : the number of each *phil*
- **state** : the state of the *phil*
	- **is eating**
	- **is sleeping**
	- **is thinking**
	- **has taken a fork**
	- **died**

### global rules
- a message "a phil died" should be printed no more than 10 ms after the death
- again, *phil*s should avoid dying

- Your program must not have any "data race"
	- "data race" means that two or more *phil*s access to the same resource without proper synchronization

### bonus rules
- all **forks** in the middle of the table
	- have no states in mem, but *number of available forks* is displayed by a semaphore
- each **phil** should be a process
- but the main process should not be a *phil*

### key points for coding
- Must 
	- each *phil* should be a separate thread
	- use mutex to protect the forks state
	- use a semaphore to display the number of available forks
	- track states(eating/sleeping/thinking)
	- handle death detection within time constraints
- Avoid
	- the main process should not be a *phil*
	- need to avoid deadlocks 
		- when *phil*s all pick up one fork...
		- they are waiting for the last fork which is held by the *phil* on their right.
		- avoid them waiting forever
	- data races
		- using proper synchronization


## arguments
### Number of Philosophers
- Minimum: Not explicitly stated, but implied to be at least 1
- Maximum: Should not exceed 200 philosophers1

### Time Arguments (time_to_die, time_to_eat, time_to_sleep)
- Minimum: Should not be lower than 60 ms1
- Maximum: INT_MAX (2147483647)2

### Additional Guidelines
- All arguments must be positive integers2
- The arguments should be between 0 and INT_MAX, representing time in milliseconds2


## 