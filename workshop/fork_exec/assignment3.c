#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child: 'echo' command\n");
        execl("/bin/echo", "echo", "Hello from the child process", (char *)NULL);
        perror("execl failed");
        return 1;
    } else {
        // Parent process
        wait(NULL);
        printf("Parent process done\n");
    }
    return 0;
}
