/**
 TITLE: Threads Example
 Author: Guillem Alminyana
 License: GPLv3 or Later
 Description: Just an example to create two threads
              and print their id
	      
 Compile: gcc threads.c -o threads -lpthread
 Use: ./threads
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/*
 Thread Called Function
*/
void * Thread_Function ( void * ptr)
{
        unsigned int *id = (unsigned int *)ptr;				//<- id points to the value of the parameter. The Thread ID in this case
        printf("Thread %u prints: \n",*id);				//<- And prints it
}

int main (void)
{
        int ret1, ret2;
	pthread_t thread_1, thread_2;                   		//<- ID for the threads


	/* Create two threads. PArameter for the thread function is the thread_id 
	   Parameters received:
	   	- The memory address to store the thread id
		- NULL for default thread options
		- The name of the thread function to call
		- Parameters for the function, in this case the address of the thread id
	*/
	
        ret1 = pthread_create(&thread_1, NULL, Thread_Function, (void *)&thread_1);
        ret2 = pthread_create(&thread_2, NULL, Thread_Function, (void *)&thread_2);

        /* Wait until both threads end */

        pthread_join(thread_1, NULL);
        pthread_join(thread_2, NULL);

        return 0;
}
