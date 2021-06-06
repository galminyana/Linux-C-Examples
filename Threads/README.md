# Threads Example
---

Operations with threads include:

- Thread Creation
- Thread Termination
- Thread Synch
- Scheduling
- Data Management
- Process Interaction

A Thread does not know who created it.

Threads in same process share:
- Process instructions
- Most data
- Open file descriptors
- Signals and it's handlers
- Working directory
- USer and group id

They have a unique id, set of registers and stack pointer, priority.

Lib `pthread.h` is required:
````c
#include <pthread.h>
````


### Thread Creation and Termination
---

`pthread.h` defines a `pthread_t` type. 

#### Thread Creation
---
````c 
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);
````

Where:

- `thread`: Returns the thread id
- `attr`: Thread attributes. Set to NULL for default attributes. Options can be:
  - PTHREAD_CREATE_JOINABLE
  - PTHREAD_INHERIT_SCHED,PTHREAD_EXPLICIT_SCHED,SCHED_OTHER
  - PTHREAD_EXPLICIT_SCHED, PTHREAD_INHERIT_SCHED
  - POSIX_THREAD_ATTR_STACKADDR
  - PTHREAD_STACK_SIZE 
- `start_routine`: Function to call for the thread. PArameters always is a `(void *)`
- `arg`: Arguments, if required, for the thread
 
 #### Thread Termination
 ---
 Call the following function inside the thread to terminate:
 ```c 
 void pthread_exit(void *retval);
 ```
 
 This kills the thread, and this function never returns. If required, returned value can be checked from another thread using `pthread_join` if the thread is not dettached.

### Thread Synchronization
---
Can be done by:
- Mutexes - Mutual exclusion lock. Enforces exclusive access by a thread to a variable or set of variables.
- Joins - Make a thread wait till others are complete (terminated).
- Condition variables - data type pthread_cond_t

#### Mutexes
---
To create and initialize a mutex:
```c
int  pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutexattr_t * attr);
```
Or using the following macro:
```c 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
```
To lock the mutex:
```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
```
To unlock the mutex:
```c
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
Also the following function acts like `pthread_mutex_lock` but if the mutex is already locked, the function exits:
```c
int pthread_mutex_trylock(pthread_mutex_t *mutex);
```

#### Joins
---
Used when one thread wants to wait to another to finish. Using:
```c
int pthread_join(pthread_t thread, void **retval);
```
Where `thread` is the thread id and `retval` usually is NULL. When not NULL, `retval` gets the value passed on to `pthread_exit` 

#### Condition Vars
---
TBD

### Compile and Link
---
To compile a multithread code, have to link it with the `pthreads` library:
```bash
# gcc multithread.c -lpthread
```
### References
---

- [POSIX Threads Libraries](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)
