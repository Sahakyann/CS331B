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

    if (pid == 0){
        printf("Child: 'grep' command\n");
        execl("/bin/grep", "grep", "main", "test.txt", (char *)NULL);
        perror("execl failed");
        return 1;
    } else {
        wait(NULL);
        printf("Parent process completed\n");
    }

    return 0;
}
