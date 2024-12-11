/*
Assignment 2: Synchronizing Critical Sections
Objective:
Write a C program to demonstrate a critical section problem where two threads increment a shared counter. Synchronize the threads using:
1.      POSIX Spin Locks
2.      POSIX Mutexes
3.      POSIX Semaphores
________________________________________
Requirements:
1.      Critical Section:
        * The shared counter is a global variable.
        * Each thread increments the counter 1,000,000 times.
2.      Initial Setup:
        * Without synchronization, the program must show race conditions (e.g., incorrect counter values).
3.      Synchronization:
        You are required to modify the program to use:
        * POSIX spin locks.
        * POSIX mutexes.
        * POSIX semaphores.
________________________________________
Example Output:
1.      Without synchronization:
Final Counter: 1954782 (incorrect due to race conditions)
2.      With spin locks/mutexes/semaphores:
Final Counter: 2000000 (correct)
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_ITERATIONS 1000000

pthread_spinlock_t lock;
pthread_mutex_t lock_m;
sem_t semaphore;

int ret;
// Shared counter
volatile int counter = 0;

// Function for incrementing the counter (Critical Section)
void *increment_counter(void *arg) {
    /* Spinlock lock
     ret = pthread_spin_lock(&lock);
    if(ret != 0){
	printf("spinlock failed!");
	exit(1);	
    }*/
    
    // Semaphore wait
    /*if (sem_wait(&semaphore) != 0) {
            perror("sem_wait failed");
            pthread_exit(NULL);
    }*/
    
    // Mutex lock	
    ret = pthread_mutex_lock(&lock_m);
    if(ret != 0){
    	printf("mutex lock failed!");
	exit(1);
    }
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Critical Section: Increment the shared counter
        // Use all 3 mechanisms to sync this section. Keep two of them commented out.
        counter++;
    }

    /* Semaphore post
    if (sem_post(&semaphore) != 0) {
            perror("sem_post failed");
            pthread_exit(NULL);
    }*/

    //Spinlock unlock
    //ret = pthread_spin_unlock(&lock);
    
    // Mutex Unlock
    ret = pthread_mutex_unlock(&lock_m);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Spinlock initialization
    //ret = pthread_spin_init(&lock, NULL);
    
    // Semaphore initialization
    //ret = sem_init(&semaphore, 0, 1);
    
    // Mutex initialization
    ret = pthread_mutex_init(&lock_m, NULL);
    // Create two threads
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Spinlock destroy
    //ret = pthread_spin_destroy(&lock);
    
    // Semaphore destroy
    //  ret = sem_destroy(&semaphore);

    // Mutex Destroy
    ret = pthread_mutex_destroy(&lock_m);
    // Print the final value of the counter
    printf("Final Counter: %d\n", counter);

    
    return 0;
}
