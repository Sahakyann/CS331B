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

        printf("Child process: Executing 'ls' command\n");


        execl("/bin/ls", "ls", (char *)NULL);


        perror("execl failed");
        return 1;
    }
    else{
	   wait(NULL);

	   printf("parent process done\n");
    }
    return 0;
}

