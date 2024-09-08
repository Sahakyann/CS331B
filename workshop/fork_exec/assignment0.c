#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void result(pid_t pid);

int main(){
	pid_t pid;
	pid_t pid1;
	pid_t pid2;
	pid = fork();
	result(pid);
	pid1 = fork();
	result(pid1);
	pid2 = fork();
	result(pid2);
}

void result(pid_t pid){
	if(pid>0)
		printf(" Parent of the pid=%d\n",pid);
	else if(pid == 0)
		printf(" Child Process\n ");
	else if (pid == -1)
		perror("fork");
}


