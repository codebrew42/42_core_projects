# how to fix?
(1) one strategy : use condition (check current_eaters)

[a]
there is one cycle (0 to n philosophers eating, but mostly 1 to n/2 philosophers eating)
check how many philos are currently eating

using d->counter

[b]
increment d->counter when a philosopher is allowed to eat (wait_for_turn())
decrement d->counter when a philosopher is done eating (done_eating())

*be careful about the counter, when it fails to hold a fork

[c]
wait for specific time when just low number of philos are eating




# explanation
Below is one way to “simulate” an arbitrator without using condition variables or semaphores—that is, by using a mutex and a simple counter (and a polling delay) to let a philosopher “wait for its turn” before picking up forks. In this design, we define a maximum allowed number of philosophers who may start eating concurrently (for example, _n – 1_). Then, when a philosopher wants to eat, it checks (by locking a mutex) whether the current count is below the threshold. If not, it waits a little (polling with a short usleep) until either:

1. The number of currently eating philosophers is low enough (that is, less than our threshold), or  
2. A maximum waiting time has elapsed (so that a “cycle” is over).

After the waiting loop, the philosopher increments the counter and proceeds. Then, after finishing eating, it decrements the counter. (Optionally, if you define a “cycle” of eating, you might reset the counter to 0 after all philosophers have had a chance.)

Below is an example of how you might implement such functions. (You would call these in your routine before and after the fork–locking section.)

---

### **Code Example**

Suppose in your `t_data` structure you add:
  
```c
// In t_data:
pthread_mutex_t arbitrator_lock;  // For protecting the counter
int current_eaters;               // Number of philosophers currently allowed to eat
```

You would initialize these in your initialization routine:

```c
// During init_data() after allocating d:
pthread_mutex_init(&d->arbitrator_lock, NULL);
d->current_eaters = 0;
```

Then, you write a helper function `wait_for_turn()` like this:

```c
#include <sys/time.h>

// Helper: get current time in microseconds
uint64_t get_current_time_us(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000UL + tv.tv_usec);
}

#define MAX_ALLOWED  (d->nbr_of_philos - 1)  // e.g., allow at most n-1 philosophers to eat concurrently
#define WAIT_THRESHOLD_US  2000               // Maximum wait time in microseconds (adjust as needed)
#define POLL_DELAY_US      50                 // Poll delay in microseconds

// wait_for_turn: a polling loop using only a mutex and a counter.
void wait_for_turn(t_data *d)
{
    uint64_t start_time = get_current_time_us();
    uint64_t elapsed = 0;
    int current;

    // Poll until the number of current eaters is less than MAX_ALLOWED
    // OR until we've waited long enough (i.e. one "cycle" is over)
    while (1)
    {
        pthread_mutex_lock(&d->arbitrator_lock);
        current = d->current_eaters;
        pthread_mutex_unlock(&d->arbitrator_lock);

        if (current < MAX_ALLOWED)
            break;  // It’s safe to proceed

        elapsed = get_current_time_us() - start_time;
        if (elapsed >= WAIT_THRESHOLD_US)
            break;  // Time is up—allow this philosopher to go ahead anyway

        // Small delay to avoid busy-waiting
        usleep(POLL_DELAY_US);
    }

    // Now increment the count (atomically)
    pthread_mutex_lock(&d->arbitrator_lock);
    d->current_eaters++;
    pthread_mutex_unlock(&d->arbitrator_lock);
}
```

Then, after a philosopher has finished eating (and released its forks), it should call a “done eating” function:

```c
void done_eating(t_data *d)
{
    pthread_mutex_lock(&d->arbitrator_lock);
    if (d->current_eaters > 0)
        d->current_eaters--;
    pthread_mutex_unlock(&d->arbitrator_lock);
}
```

Finally, in your main routine (for example in your `routine()` function) you would “wrap” the eating phase like this:

```c
void *routine(void *arg)
{
    t_philo *p = (t_philo *)arg;

    // (Optional) Initial staggering if needed
    if (p->id % 2 == 0)
        usleep(100);

    while (1)
    {
        // Wait for your turn to attempt to pick up forks:
        wait_for_turn(p->data);

        // Now pick up forks using your ordering method.
        // (For example, using even/odd ordering or a resource hierarchy.)
        if (eat_and_monitor(p))
        {
            done_eating(p->data);
            return (NULL);
        }

        // Finished eating – update the counter.
        done_eating(p->data);

        // Sleep:
        print_status_and_return_time(p->data, "is sleeping", p->id);
        usleep(p->data->time_to_sleep * 1000);

        if (check_and_print_a_philo_died(p->data, p->id) ||
            check_all_completed_meal(p->data, p->data->nbr_of_philos))
            return (NULL);

        // Think:
        print_status_and_return_time(p->data, "is thinking", p->id);
    }
    return (NULL);
}
```

---

### **Explanation of the Logic**

1. **One Circle of Eating:**  
   You define a “cycle” where—ideally—only one group (or “circle”) of philosophers eats concurrently. At the start of a cycle, the `current_eaters` counter is 0. As each philosopher calls `wait_for_turn()`, the counter increases up to (n–1) (or fewer, if a philosopher doesn’t wait long). After all philosophers finish their cycle (i.e. they eventually call `done_eating()`), the counter is reset back to 0.

2. **Waiting for a Specific Time When A Certain Number of Philosophers Are Eating:**  
   The function `wait_for_turn()` continuously checks the current number of eating philosophers. If that number is less than our allowed maximum (`MAX_ALLOWED`), it allows the philosopher to proceed immediately.  
   However, if the number is too high (for example, already _n–1_ philosophers are eating), then it polls until either the count drops below the threshold or a maximum wait time (`WAIT_THRESHOLD_US`) has elapsed. This “time-out” prevents a philosopher from waiting indefinitely—even if the current count is high, it will eventually break out and proceed.

3. **Starting to Eat or Holding Forks After Waiting:**  
   Once the waiting loop completes (because either there is room or the wait time is over), the philosopher increments the counter (atomically) and proceeds to pick up its forks and eat.  
   After it finishes eating and releases its forks, it decrements the counter. This mechanism “queues” philosophers naturally without an explicit condition variable or semaphore.

---

### **Important Considerations**

- **Polling Delay and Timeout:**  
  The constants `POLL_DELAY_US` and `WAIT_THRESHOLD_US` need to be tuned. They represent, respectively, the short delay between each check and the maximum time a philosopher will wait before proceeding. You want them small enough not to introduce noticeable delays but long enough to allow other threads to update the count.

- **Fairness and Starvation:**  
  This method does not “communicate” the state between philosophers directly (they still only use mutexes and a counter), but it gives a natural chance for each philosopher to eventually start eating even if the timing isn’t perfect.

- **Resetting the Cycle:**  
  In this simple example, each philosopher simply increments and then decrements the counter. In some designs you might want to “reset” the counter to 0 after all philosophers have eaten, but that is not strictly necessary if your waiting loop (with its timeout) already guarantees progress.

This solution respects 42’s restrictions and uses only `pthread_mutex_lock/unlock` and a counter (d->current_eaters) to simulate an arbitrator. It should help you reduce deadlocks and starvation by limiting the number of philosophers that are trying to pick up forks at the same time.

The counter is meant to represent how many philosophers are *currently eating* (or, more precisely, are in the critical section where they have reserved the right to pick up forks). Here’s the reasoning:

1. **Before Eating:**  
   When a philosopher calls `wait_for_turn()`, the function checks if the number of philosophers already eating (`current_eaters`) is below the allowed threshold. If so, it increments the counter (i.e. it "reserves a spot") and then the philosopher proceeds to eat.

2. **After Eating:**  
   Once the philosopher finishes eating and releases the forks, they are no longer in the "eating" state. To accurately reflect that, you need to decrement the counter by calling `done_eating()`. This tells the system that one less philosopher is eating, which in turn allows another waiting philosopher to proceed.

If you were to increment the counter after finishing eating, it would incorrectly signal that another philosopher has started eating when in fact that philosopher is done. The purpose of the counter is to limit the concurrent eating processes (for example, to at most _n – 1_ philosophers), so when a philosopher finishes, their “slot” should be freed up (i.e. the counter should be decremented) so that another philosopher can start.

In short:  
- **Increment (in wait_for_turn):** Reserve a spot because you're about to eat.  
- **Decrement (in done_eating):** Free up that spot because you're done eating.

That’s why after finishing eating, you call `done_eating()` to decrease `current_eaters`—ensuring that the count correctly reflects how many philosophers are still eating.