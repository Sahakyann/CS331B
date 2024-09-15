#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdint.h>

void out(void){
        printf("ID of the Exiting Process: %jd\n", (intmax_t)getpid());
}

int main() {
    pid_t pid1, pid2;
    int status;
    pid1 = fork();

    if (pid1 == 0) {
        printf("Child Process 1: PID = %d\n", getpid());
        atexit(out);
        exit(0);
    } else {
        waitpid(pid1, &status, 0);
        printf("Parent: Child 1 PID = %d exit status = %d\n", pid1, WEXITSTATUS(status));
        pid2 = fork();
        if (pid2 == 0) {
            printf("Child Process 2: PID = %d\n", getpid());
            atexit(out);
            exit(1);
        } else {
            waitpid(pid2,&status,0);
            printf("Parent: Child 2 PID = %d exit status = %d\n", pid2, WEXITSTATUS(status));
        }
    }

    return 0;
}
   
