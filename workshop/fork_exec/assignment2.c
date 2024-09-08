#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid1 == 0) {
        printf("First child process: Executing 'ls' command\n");
        execl("/bin/ls", "ls", (char *)NULL);
        perror("execl failed");
        return 1;
    } else {
        pid2 = fork();

        if (pid2 < 0) {
            perror("fork failed");
            return 1;
        }

        if (pid2 == 0) {
            printf("Second child process: Executing 'date' command\n");
            execl("/bin/date", "date", (char *)NULL);
            perror("execl failed");
            return 1;
        } else {
            wait(NULL);
            wait(NULL);
            printf("Parent process done\n");
        }
    }

    return 0;
}
