#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("Child with PID: %d exiting.\n", getpid());
        exit(0); 
    } else {
        printf("Parent process with PID: %d is sleeping.\n", getpid());
        sleep(30); 
        printf("Parent process finished sleeping.\n");
    }

    return 0;
}
