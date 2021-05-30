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
 
 
 #### Thread Termination
 Call the following function inside the thread to terminate:
 ```c 
 void pthread_exit(void *retval);
 ```
 
 This kills the thread, and this function never returns. If required, returned value can be checked from another thread using `pthread_join` if the thread is not dettached.
