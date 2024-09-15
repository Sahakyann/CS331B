#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); 

    if (pid == 0) {
        printf("Child process with PID: %d is exiting.\n", getpid());
        exit(0); 
    } else {
        printf("Parent with PID: %d is waiting for the child.\n", getpid());
        wait(NULL);
        printf("Parent got child's exit status.\n");
    }

    return 0;
}
