# threads
## content
- [] threads vs processes
- [] thread management
- [] concurrency and parallelism
- [] race condition
- [] Mutual Exclusion (mutex)
- [] deadlocks
- [] condition variable

## 1. threads

- a processor with 4 cores : can have multiple operation, parallel

- each core can handle multiple threads

- clocks allow switching between threads

### how to schedule?
- using threads(one set of operations that need to be executed)
- tell CPU which thread to execute

- 4.17 Ghz : 4.17 * 10^9 cycles/second


### threading
- concurrent programming : multiple threads running at the same time
- parallelism : multiple threads running at the same time
- you don't need to wait for the server to respond, can switch to another thread

## core
## core execution
- A core can execute one thread at a time, but modern CPUs can handle multiple threads through techniques like multithreading.
- if a core can handle two threads
: 4 physical cores * 2 threads/core = 8 logical cores

- A **core** in a CPU can execute one thread of instructions at a time. However, modern CPUs use techniques like **multithreading** (e.g., Intel's Hyper-Threading) that allow a single core to handle multiple threads by rapidly switching between them. This gives the illusion that multiple threads are running simultaneously, but in reality, each core is still processing one thread at any given moment.

### parallel operation
- core to core, all operate at the same time

### concurrent operation
- core to thread, operate by switching


## 1. threads vs processes
### threads
- a thread is a unit of execution within a process
- a process can contain multiple threads
- all threads share the same address space
- switching between threads is faster/cheaper than switching between processes

### processes
- a process is an instance of a program
	- instance: an occurrence of a program in execution
- each process has its own address space
- processes are more expensive than threads
- switching between processes is more expensive/slower
- a process can contain multiple threads

## 2. threads management

### pthread
```c
#include <pthread.h>

pthread_t	thread;
pthread_create(&thread, NULL, function, arg); //assign a func to a thread
pthread_join(thread, NULL); // wait for the thread to finish
pthread_detach(thread); // thread will detach from the calling thread
pthread_exit(NULL); // terminate the calling thread
```

### pthread_mutex
```c
pthread_mutex_t		mutex;
pthread_mutex_init(&mutex, NULL);
pthread_mutex_lock(&mutex); 
pthread_mutex_unlock(&mutex);
pthread_mutex_destroy(&mutex); //clean up
```

### pthread_create
- assigns a function to a thread
- 2nd arg : attribute
- 4th arg : parameter to the func
- does not guarantee the thread scheduling, which means that the thread may not run in the order of creation.

- after creation, you have to options : either **join** or **detach**
### join vs detach
- join
	- join the thread to the calling thread
	- main thread should wait for all the threads to finish
	- ensures that resources are properly cleaned up after thread execution
	- useful for synchronization, as it guarantees the order of execution

- detach
	- the thread will run independently
	- will not block the calling thread
	- suitable for fire-and-forget tasks where the main thread does not need to wait
	- resources are automatically released when the detached thread finishes

- which is more common?
	- join 
	- why? if you use 'detach', the thread will run independently and you won't know when it will finish. Also, you need to free the resources manually, which can lead to memory leaks if not handled properly.
	- join is preferred in scenarios where the main thread needs to ensure all tasks are completed before proceeding.

### pthread_join
- this is to wait for a specific thread to terminate. when you call pthread_join on a thread, the calling thread(usually 'main') will block until the specified thread has finished executing

- important for resource management and ensuring that the main prog does not exit before all threads have completed their tasks.

- without joining a thread, it may continue running even after main has finished, which might lead to resource leaks or undefined behavior.

- so all the thread should be "pthread_join"ed to safely terminate the main program.

## compile
```
gcc -g -fsanitize=thread -o threads_prac1 threads_prac1.c -lpthread
gcc -g -pthread main.c -o main
```
- without flag it will not work